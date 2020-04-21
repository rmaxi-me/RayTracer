/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>
#include <string>
#include <memory>

#include "Engine/Utils/ArgumentParser.hpp"
#include "Window/Window.hpp"

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
    std::unique_ptr<raylib::Window> m_window{nullptr};
    ArgumentParser m_parser;
    Settings m_settings;

    std::uint32_t m_fps{0};
public:
    Application(int ac, char **av, int width, int height);
    virtual ~Application() = default;

    void start();
    void drawFps() const;

    virtual void init() = 0;
    virtual void deinit() = 0;
    virtual void tick(float deltaTime) = 0;
    virtual void draw() = 0;
};
