/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "VentaBlack.hpp"

Vector3 VentaBlack::compute(const Ray &ray) const noexcept
{
    return Vector3();
}

bool VentaBlack::isOpaque() const noexcept
{
    return true;
}

float VentaBlack::getGammaCorrection() const noexcept
{
    return 0.f;
}

float VentaBlack::getReflectionFactor() const noexcept
{
    return (1.0f - 0.99965f);
}

float VentaBlack::getRefractionFactor() const noexcept
{
    return 0.f;
}
