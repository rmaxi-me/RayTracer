/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <mutex>
#include <queue>
#include <thread>
#include <atomic>
#include <memory>

#include "Engine/Application.hpp"
#include "Engine/Assets/Model.hpp"
#include "Engine/Assets/Texture.hpp"

#include "Camera/Camera.hpp"
#include "Objects/ObjectList.hpp"

class RayTracerApp : public Application {
public:
    struct Pixel {
        int x;
        int y;
        raymath::Vector3 color;
        Color raw;
    };

    struct FrameBuffer {
        int width;
        int height;
        std::vector<Pixel> pixels{};
        std::vector<Color> raw{};

        inline Pixel &operator[](const std::size_t &index)
        {
            return pixels[index];
        }

        inline const Pixel &operator[](const std::size_t &index) const
        {
            return pixels[index];
        }
    };
private:
    int m_anti_aliasing{};
    RCamera m_camera{};

    std::shared_ptr<ObjectList> m_list{};
    FrameBuffer m_frameBuffer{};
    std::vector<std::thread> m_threads{};

    std::size_t m_pixelCount{0};
    std::atomic<std::size_t> m_progress{0};

    Image m_image{};
    Texture m_texture{};
    bool m_loaded{false};
    bool m_abort{false};

    using Range = std::pair<size_t, size_t>;
    std::queue<Range> m_tasks{};
    std::mutex m_taskMutex{};

    decltype(std::chrono::high_resolution_clock::now()) m_tpBegin{};

    void computePixelColor(Pixel &pixel);
    void computePixelRange();

    void multithreadTask(void (RayTracerApp::*func)(), bool join);
public:
    RayTracerApp(int ac, char **av);

    void init() override;
    void deinit() override;
    void tick(float deltaTime) override;
    void draw() override;
};
