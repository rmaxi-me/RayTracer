/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Normal.hpp"
#include "Objects/Sphere.hpp"

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> Normal::compute(const raylib::Ray &, raylib::RayHitInfo &info) const noexcept
{
    raymath::Vector3 color = info.position + info.normal + Sphere::getRandomPoint();
    raylib::Ray reflection{info.position, color - info.position};

    return std::pair{reflection, m_attenuation};
}

float Normal::getGammaCorrection() const noexcept
{
    return 0;
}

bool Normal::isOpaque() const noexcept
{
    return true;
}

float Normal::getReflectionFactor() const noexcept
{
    return 0.25f;
}

float Normal::getRefractionFactor() const noexcept
{
    return 0;
}
