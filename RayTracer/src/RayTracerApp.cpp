/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <thread>

#include "Engine/Raylib.hpp"
#include "Engine/Ray/Ray.hpp"
#include "Engine/Utils/Random.hpp"

#include "RayTracerApp.hpp"
#include "Materials/AMaterial.hpp"
#include "Objects/ObjectList.hpp"
#include "Scene/Scene.hpp"

RayTracerApp::RayTracerApp(int ac, char **av)
        : Application(ac, av, 800, 600)
{
    m_anti_aliasing = m_parser.getOrDefault<int>("aa", "a", 128, APFuncs::toInt<int>);

    if (m_anti_aliasing <= 0) {
        TraceLog(LOG_ERROR, "Anti aliasing must be higher than 0. (Got %d)", m_anti_aliasing);
        throw std::runtime_error("Anti aliasing must be higher than 0.");
    }
    TraceLog(LOG_DEBUG, "Anti Aliasing: x%d", m_anti_aliasing);
}

void RayTracerApp::init()
{
    auto scene = Scene::fromFile(m_settings.filePath.c_str());

    m_list = scene.getObjectList();

    m_pixelCount = m_settings.width * m_settings.height;
    m_frameBuffer.width = m_settings.width;
    m_frameBuffer.height = m_settings.height;
    m_frameBuffer.raw.reserve(m_pixelCount);
    m_frameBuffer.pixels.reserve(m_pixelCount);

    for (int y = m_frameBuffer.height - 1; y >= 0; --y) {
        for (int x = 0; x < m_frameBuffer.width; ++x) {
            m_frameBuffer.pixels.push_back({x, y, {}, {}});
        }
    }

    m_tpBegin = std::chrono::high_resolution_clock::now();
    multithreadTask(&RayTracerApp::computePixelRange, false);
}

void RayTracerApp::deinit()
{
    m_taskMutex.lock();
    decltype(m_tasks)().swap(m_tasks);
    m_taskMutex.unlock();

    for (auto &thread : m_threads)
        thread.join();
    m_threads.clear();

    if (m_loaded) {
        UnloadTexture(m_texture);
        UnloadImage(m_image);
    }
}

raymath::Vector3 colorize(const raylib::Ray &ray, const std::shared_ptr<ObjectList> &list, int depth)
{
    raylib::RayHitInfo info;
    std::shared_ptr<AMaterial> currentMaterial{nullptr};

    if (depth <= 0)
        return raymath::Vector3();

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the operation if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True

    if (list->isHit(ray, 0.001f, std::numeric_limits<float>::max(), info, currentMaterial)) {
        auto reflectedRay = currentMaterial->reflect(ray, info);
        raymath::Vector3 reflectedVec;

        if (reflectedRay.has_value())
            reflectedVec = reflectedRay->second * colorize(reflectedRay->first, list, depth - 1);
        else
            reflectedVec = raymath::Vector3();

        if (!currentMaterial->isOpaque()) {
            auto refractedRay = currentMaterial->refract(ray, info);
            raymath::Vector3 refractedVec;

            if (refractedRay.has_value())
                refractedVec = refractedRay->second * colorize(refractedRay->first, list, depth - 1);
            else
                refractedVec = raymath::Vector3();

            return reflectedVec * refractedVec;
        }

        return reflectedVec;
    }
    raymath::Vector3 unit = normalize(ray.getDirection());
    float t = 0.5f * (unit.y() + 1.0f);
    return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
}

void RayTracerApp::computePixelColor(RayTracerApp::Pixel &pixel)
{
    static const raymath::Vector3 l(-2, -1, -1);
    static const raymath::Vector3 h(4, 0, 0);
    static const raymath::Vector3 v(0, 3, 0);
    static const raymath::Vector3 o(0, 0, 0);
    raymath::Vector3 col;

    //Begin AntiAliasing
    for (int k = 0; k < m_anti_aliasing; k++) {
        float Vu = (float) (pixel.x + std::generate_canonical<double, 10>(Random::getGenerator())) / (float) (m_frameBuffer.width);
        float Vv = (float) (pixel.y + std::generate_canonical<double, 10>(Random::getGenerator())) / (float) (m_frameBuffer.height);

        //Projection of the ray depending of the size of the screen
        raylib::Ray ray(o, l + Vu * h + Vv * v);
        col += colorize(ray, m_list, 50);
    }
    col /= (float) m_anti_aliasing;
    //End AntiAliasing

    pixel.color = col;
    pixel.raw = col.toColor();

    ++m_progress;
}

void RayTracerApp::computePixelRange()
{
    size_t begin;
    size_t end;

    while (!m_loaded) {
        {
            std::lock_guard<std::mutex> guard(m_taskMutex);

            if (m_abort || m_tasks.empty())
                return;

            const auto &task = m_tasks.front();
            begin = task.first;
            end = task.second;
            m_tasks.pop();
        }
        for (auto i = begin; i < end; ++i) {
            if (m_abort)
                return;
            computePixelColor(m_frameBuffer[i]);
            m_frameBuffer.raw[i] = m_frameBuffer[i].raw;
        }
    }
}

void RayTracerApp::multithreadTask(void (RayTracerApp::*func)(), bool join)
{
    const auto maxThreads = std::thread::hardware_concurrency();
    const auto threadCount = maxThreads > 1 ? maxThreads - 1 : 1; // '- 1' because manager thread counts as one
    const std::size_t splitSize = m_pixelCount / m_frameBuffer.height;

    std::size_t offset = 0;

    m_threads.clear();
    for (int y = 0; y < m_frameBuffer.height; y++) {
        m_tasks.emplace(offset, offset + splitSize);
        offset += splitSize;
    }
    for (std::size_t i = 0; i < threadCount; ++i) {
        m_threads.emplace_back(func, this);
    }

    if (join) {
        for (auto &thread : m_threads)
            thread.join();
    }
}

void RayTracerApp::tick(float)
{
    if (!m_loaded && m_progress == m_pixelCount) {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - m_tpBegin;
        std::cout << "Image generation done in " << duration.count() << " seconds" << std::endl;

        m_image = LoadImageEx(m_frameBuffer.raw.data(), m_settings.width, m_settings.height);
        m_texture = LoadTextureFromImage(m_image);
        m_loaded = true;
    }
}

void RayTracerApp::draw()
{
    if (m_progress < m_pixelCount) {
        for (const auto &pixel : m_frameBuffer.pixels) {
            DrawPixel(pixel.x, m_frameBuffer.height - pixel.y, pixel.raw);
        }
    } else {
        if (m_loaded)
            DrawTexture(m_texture, 0, 0, WHITE);
    }
}
