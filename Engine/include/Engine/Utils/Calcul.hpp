#pragma once

#include "Engine/Vector/Vector3.hpp"

namespace raymath
{
    inline raymath::Vector3 reflect(const raymath::Vector3 &v, const raymath::Vector3 &n)
    {
        return v - 2 * (raymath::dotProduct(v, n) * n);
    }
} // namespace raymath
