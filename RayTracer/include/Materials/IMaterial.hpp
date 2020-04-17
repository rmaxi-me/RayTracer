/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Vector/Vector3.hpp"

class IMaterial {
public:
    virtual ~IMaterial();

    [[nodiscard]] virtual Vector3 compute(const Ray &ray) const noexcept = 0;

    [[nodiscard]] virtual bool isOpaque() const noexcept = 0;
    [[nodiscard]] virtual float getGammaCorrection() const noexcept = 0;
    [[nodiscard]] virtual float getReflectionFactor() const noexcept = 0;
    [[nodiscard]] virtual float getRefractionFactor() const noexcept = 0;
};
