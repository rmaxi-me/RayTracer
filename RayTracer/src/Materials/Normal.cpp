/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Normal.hpp"

Vector3 Normal::compute(const Ray &) const noexcept
{
    return Vector3();
}

float Normal::getGammaCorrection() const noexcept
{
    return 0;
}

bool Normal::isOpaque() const noexcept
{
    return true;
}

float Normal::getReflectionFactor() const noexcept
{
    return 0.25f;
}

float Normal::getRefractionFactor() const noexcept
{
    return 0;
}
