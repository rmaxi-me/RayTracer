/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Raylib.hpp"

#include <sstream>
#include <iostream>
#include <chrono>

#include "Engine/Application.hpp"
#include "Engine/ArgumentParser.hpp"
#include "Engine/Window/Window.hpp"

using namespace std::chrono_literals;

Application::Application(int ac, char **av)
        : m_parser{ac, av}, m_settings{}
{
    m_settings.fullscreen = m_parser.getOrDefault<bool>("fullscreen", "f", false, APFuncs::toBool);
    m_settings.width = m_parser.getOrDefault<std::uint16_t>("width", "w", 800, APFuncs::toInt<std::uint16_t>);
    m_settings.height = m_parser.getOrDefault<std::uint16_t>("height", "h", 600, APFuncs::toInt<std::uint16_t>);
    m_settings.fpsMax = m_parser.getOrDefault<std::uint16_t>("fps", "", 240, APFuncs::toInt<std::uint16_t>);
    m_settings.filePath = m_parser.getOrDefault<std::string>("openfile", "o", "", APFuncs::toString);

    // TODO: Reset screen dimensions on fullscreen
    if (m_settings.fullscreen) {
        m_settings.width = GetScreenWidth();
        m_settings.height = GetScreenHeight();
    }

#if defined(RAYTRACER_DEBUG)
    SetTraceLogLevel(TraceLogType::LOG_ALL);
#elif defined(RAYTRACER_RELEASE)
    SetTraceLogLevel(TraceLogType::LOG_WARNING);
#else
    SetTraceLogLevel(TraceLogType::LOG_ERROR);
#endif

    TraceLog(TraceLogType::LOG_DEBUG, "File to open: %s", m_settings.filePath.c_str());
}

void Application::start()
{
    m_window = std::make_unique<raylib::Window>(m_settings.width, m_settings.height, "Raylib tests");

    if (m_settings.fpsMax != 0)
        m_window->setFPS(m_settings.fpsMax);
    if (m_settings.fullscreen)
        m_window->toggleFullscreen();
    m_window->setClearColor(BLACK);

    auto frameCount = m_fps;
    auto previous = std::chrono::high_resolution_clock::now();
    decltype(previous) now;

    init();

    while (m_window->isOpen()) {
        m_window->clear();

        tick(GetFrameTime());

        BeginDrawing();
        draw();
#if defined(RAYTRACER_DEBUG)
        drawFps();
#endif
        EndDrawing();

        ++frameCount;

        now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - previous) >= 1s) {
            m_fps = frameCount;
            frameCount = 0;
            previous = now;
        }
    }

    deinit();
}

void Application::drawFps() const
{
    DrawText(TextFormat("%u FPS", m_fps), 5, 5, 20, LIME);
}
