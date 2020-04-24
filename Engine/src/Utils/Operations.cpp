/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Utils/Operations.hpp"

raymath::Vector3 raymath::refract(const raymath::Vector3 &vec, const raymath::Vector3 &norm, float n1, float n2)
{
    const auto n = n1 / n2;
    const auto cosI = -raymath::dotProduct(norm, vec);
    const auto sinT2 = std::pow(n, 2) * (1.f - std::pow(cosI, 2));

    if (sinT2 > 1.f)
        return {};
    const auto cosT = (float) std::sqrt(1.f - sinT2);
    return n * vec + (n * cosI - cosT) * norm;
}
