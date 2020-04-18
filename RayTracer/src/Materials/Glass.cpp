/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Glass.hpp"

Vector3 Glass::compute(const Ray &) const noexcept
{
    return Vector3();
}

bool Glass::isOpaque() const noexcept
{
    return false;
}

float Glass::getGammaCorrection() const noexcept
{
    return 0.f;
}

float Glass::getReflectionFactor() const noexcept
{
    return 0.25f;
}

float Glass::getRefractionFactor() const noexcept
{
    return 1.5f;
}
