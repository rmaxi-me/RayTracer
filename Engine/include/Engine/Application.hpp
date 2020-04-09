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

class Application final {
public:
    struct Settings {
        std::uint16_t width;
        std::uint16_t height;
        bool fullscreen;
        std::string filePath;
    };
private:
    ArgumentParser m_parser;
    Settings m_settings;
public:
    Application(int ac, char **av);

    void start();
};
