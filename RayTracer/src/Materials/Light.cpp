/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Light.hpp"

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> Light::compute(const raylib::Ray &, raylib::RayHitInfo &) const noexcept
{
    return {};
}

raymath::Vector3 Light::emit()
{
    return m_light;
}
