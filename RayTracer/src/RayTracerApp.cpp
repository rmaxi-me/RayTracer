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
#include "Objects/ObjectList.hpp"
#include "Objects/Sphere.hpp"
#include "Scene/Scene.hpp"

RayTracerApp::RayTracerApp(int ac, char **av)
        : Application(ac, av)
{
}

void RayTracerApp::init()
{
    auto scene = Scene::fromFile(m_settings.filePath.c_str());

    m_list = scene.getObjectList();

    m_frameBuffer.width = m_settings.width;
    m_frameBuffer.height = m_settings.height;
    m_frameBuffer.pixels.reserve(m_settings.width * m_settings.height);

    for (int y = 0; y < m_frameBuffer.height; ++y) {
        for (int x = 0; x < m_frameBuffer.width; ++x) {
            m_frameBuffer.pixels.push_back({x, y, {}});
        }
    }
}

void RayTracerApp::deinit()
{
}

void RayTracerApp::tick(float deltaTime)
{
    (void) deltaTime;
}

raymath::Vector3 linearInterpolation(const raylib::Ray &ray, const std::shared_ptr<ObjectList> &list)
{
    raylib::RayHitInfo info;

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the calcul if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True
    if (list->isHit(ray, 0.001f, std::numeric_limits<float>::max(), info)) {
        raymath::Vector3 color = info.position + info.normal + Sphere::getRandomPoint();
        return 0.5 * linearInterpolation(raylib::Ray(info.position, color - info.position), list);
    } else {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5f * (vecteurUnitaire.y() + 1.0f);
        return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
    }
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
        col += linearInterpolation(ray, m_list);
    }
    col /= (float) m_anti_aliasing;
    // col*=255;
    // std::cout << (int)col.x() << " " << (int)col.y() << " " << (int)col.z() << std::endl;
    //End AntiAliasing

    pixel.color = col;
}

void RayTracerApp::computePixelRange(std::vector<Pixel> &pixels, size_t begin, size_t end)
{
    for (auto i = begin; i < end; ++i)
        computePixelColor(pixels[i]);
}

void RayTracerApp::draw()
{
//    m_window->clear();

    static const auto maxThreads = std::thread::hardware_concurrency();
    static const auto threadCount = maxThreads > 1 ? maxThreads - 1 : 1; // '- 1' because manager thread counts as one
    static const std::size_t pixelCount = m_frameBuffer.pixels.size();
    static const std::size_t splitSize = pixelCount / threadCount;

    std::size_t offset = 0;
    std::vector<std::thread> threads{};

    for (std::size_t i = 0; i < threadCount; ++i) {
        threads.emplace_back(&RayTracerApp::computePixelRange, this,
                             std::ref(m_frameBuffer.pixels), offset, offset + splitSize);
        offset += splitSize;
    }

    for (auto &thread : threads)
        thread.join();

    BeginDrawing();
    for (const auto &pixel : m_frameBuffer.pixels) {
        DrawPixel(pixel.x, m_frameBuffer.height - pixel.y, pixel.color.toColor());
    }
    EndDrawing();

    std::cout << "draw() frame time = " << GetFrameTime() << "\tfps = " << m_fps << '\n';
}
