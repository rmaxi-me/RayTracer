/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cmath>

#include "Engine/Vector/Vector3.hpp"

namespace raymath {
    inline raymath::Vector3 reflect(const raymath::Vector3 &v, const raymath::Vector3 &n)
    {
        return v - 2 * (raymath::dotProduct(v, n) * n);
    }

    raymath::Vector3 refract(const raymath::Vector3 &vec, const raymath::Vector3 &norm, float n1, float n2);
    float fresnel(const raymath::Vector3 &vec, const raymath::Vector3 &norm, const float &refractionFactor);
} // namespace raymath
