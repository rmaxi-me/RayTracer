/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Metal.hpp"
#include "Objects/Sphere.hpp"
#include "Engine/Utils/Calcul.hpp"

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> Metal::compute(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept
{
    raymath::Vector3 reflected = raymath::reflect(raymath::normalize(ray.getDirection()), info.normal);
    raylib::Ray scattered(info.position, reflected);

    if (raymath::dotProduct(scattered.getDirection(), info.normal) > 0)
        return std::pair{scattered, m_attenuation};
    return {};
}

float Metal::getGammaCorrection() const noexcept
{
    return 0;
}

bool Metal::isOpaque() const noexcept
{
    return true;
}

float Metal::getReflectionFactor() const noexcept
{
    return 0.25f;
}

float Metal::getRefractionFactor() const noexcept
{
    return 0;
}
