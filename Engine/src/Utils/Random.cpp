/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Utils/Random.hpp"

std::random_device Random::m_randomDevice{};
std::mt19937 Random::m_generator{m_randomDevice()};

std::random_device &Random::getRandomDevice() noexcept
{
    return m_randomDevice;
}

std::mt19937 &Random::getGenerator() noexcept
{
    return m_generator;
}
