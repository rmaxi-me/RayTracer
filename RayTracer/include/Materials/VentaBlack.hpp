/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Materials/IMaterial.hpp"

class VentaBlack : public IMaterial {
public:
    [[nodiscard]] Vector3 compute(const Ray &ray) const noexcept override;
    [[nodiscard]] bool isOpaque() const noexcept override;
    [[nodiscard]] float getGammaCorrection() const noexcept override;
    [[nodiscard]] float getReflectionFactor() const noexcept override;
    [[nodiscard]] float getRefractionFactor() const noexcept override;
};
