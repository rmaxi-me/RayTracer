#pragma once

#include "Engine/Vector/Vector3.hpp"

namespace raymath {
    inline raymath::Vector3 reflect(const raymath::Vector3 &v, const raymath::Vector3 &n)
    {
        return v - 2 * (raymath::dotProduct(v, n) * n);
    }

    raymath::Vector3 refract(const raymath::Vector3 &vec, const raymath::Vector3 &norm, float n1, float n2);
} // namespace raymath
