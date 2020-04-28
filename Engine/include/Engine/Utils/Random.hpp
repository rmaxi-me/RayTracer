/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <random>

class Random final {
private:
    static std::random_device m_randomDevice;
    static std::mt19937 m_generator;
    Random() = default;

public:
    static std::random_device &getRandomDevice() noexcept;
    static std::mt19937 &getGenerator() noexcept;
};
