/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <raylib.h>
#include <iostream>
#include <chrono>

#include "Application.hpp"
#include "ArgumentParser.hpp"
#include "Window/Window.hpp"

using namespace std::chrono_literals;

Application::Application(int ac, char **av)
        : m_parser{ac, av}, m_settings{}
{
    m_settings.fullscreen = m_parser.getOrDefault<bool>("fullscreen", "f", false, APFuncs::toBool);
    m_settings.width = m_parser.getOrDefault<std::uint16_t>("width", "w", 1600, APFuncs::toInt<std::uint16_t>);
    m_settings.height = m_parser.getOrDefault<std::uint16_t>("height", "h", 900, APFuncs::toInt<std::uint16_t>);
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
    raylib::Window window(m_settings.width, m_settings.height, "Raylib tests");

    if (m_settings.fpsMax != 0)
        window.setFPS(m_settings.fpsMax);
    if (m_settings.fullscreen)
        window.toggleFullscreen();

    window.changeClearColor(BLACK);

    while (window.isOpen()) {
        window.clear();
        BeginDrawing();
        DrawRectangle(100, 100, 100, 100, RAYWHITE);

#if defined(RAYTRACER_DEBUG)
        DrawFPS(0, 0);
#endif
        EndDrawing();
    }
}
