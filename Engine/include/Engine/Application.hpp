/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>
#include <string>

#include "ArgumentParser.hpp"

class Application {
public:
    struct Settings {
        bool fullscreen;
        std::uint16_t width;
        std::uint16_t height;
        std::uint16_t fpsMax;
        std::string filePath;
    };
protected:
    ArgumentParser m_parser;
    Settings m_settings;

    std::uint32_t m_fps{0};
public:
    Application(int ac, char **av);
    virtual ~Application() = default;

    void start();
    void drawFps() const;

    virtual void tick(float deltaTime) = 0;
    virtual void draw() = 0;
};
