/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/VentaBlack.hpp"

VentaBlack::VentaBlack()
    : AMaterial({0, 0, 0}, true, 0.f, (1.0f - 0.99965f), 0.f)
{
}

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> VentaBlack::compute(const raylib::Ray &, raylib::RayHitInfo &) const noexcept
{
    return {};
}
