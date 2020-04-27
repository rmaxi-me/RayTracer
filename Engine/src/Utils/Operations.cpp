/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <cmath>
#include <algorithm>

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

float raymath::fresnel(const raymath::Vector3 &vec, const raymath::Vector3 &norm, const float &refractionFactor)
{
    float cosI = std::clamp(dotProduct(vec, norm), -1.f, 1.f);
    float etaI = 1.f;
    float etaT = refractionFactor;
    if (cosI > 0) std::swap(etaI, etaT);
    float sinT = etaI / etaT * sqrtf(std::max(0.f, 1.f - cosI * cosI));

    if (sinT >= 1.f) {
        // Total reflection
        return 1.f;
    } else {
        float cosT = std::sqrt(std::max(0.f, 1.f - sinT * sinT));
        cosI = std::fabs(cosI);
        float Rs = ((etaT * cosI) - (etaI * cosT)) / ((etaT * cosI) + (etaI * cosT));
        float Rp = ((etaI * cosI) - (etaT * cosT)) / ((etaI * cosI) + (etaT * cosT));
        return (Rs * Rs + Rp * Rp) / 2.f;
    }
}
