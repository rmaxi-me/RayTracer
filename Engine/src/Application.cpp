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

using namespace std::chrono_literals;

Application::Application(int ac, char **av)
        : m_parser{ac, av}, m_settings{}
{
    m_settings.width = m_parser.getOrDefault<std::uint16_t>("width", "w", 1600, APFuncs::toInt<std::uint16_t>);
    m_settings.height = m_parser.getOrDefault<std::uint16_t>("height", "h", 900, APFuncs::toInt<std::uint16_t>);
    m_settings.fullscreen = m_parser.getOrDefault<bool>("fullscreen", "f", false, APFuncs::toBool);
    m_settings.filePath = m_parser.getOrDefault<std::string>("openfile", "o", "", APFuncs::toString);

    // TODO: Reset screen dimensions on fullscreen
    if (m_settings.fullscreen) {
        m_settings.width = GetScreenWidth();
        m_settings.height = GetScreenHeight();
    }

    std::cout << "File to open: " << m_settings.filePath << '\n';
}

void Application::start()
{
    InitWindow(m_settings.width, m_settings.height, "Raylib tests");

    if (m_settings.fullscreen) {
        ToggleFullscreen();
    }

    while (!WindowShouldClose()) {
        ClearBackground(Color{0, 0, 0, 255});
        BeginDrawing();
        DrawFPS(0, 0);
        EndDrawing();
    }
}
