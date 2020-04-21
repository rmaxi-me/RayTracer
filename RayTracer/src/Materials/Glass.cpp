/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Glass.hpp"

Glass::Glass(const raymath::Vector3 &attenuation)
        : AMaterial(attenuation, false, .0f, .25f, 1.5f)
{}

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> Glass::compute(const raylib::Ray &, raylib::RayHitInfo &) const noexcept
{
    return {};
}
