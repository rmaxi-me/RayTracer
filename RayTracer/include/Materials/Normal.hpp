/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "IMaterial.hpp"

class Normal : public IMaterial {
private:
    raymath::Vector3 m_attenuation{0.8, 0.8, 0.0};
public:
    Normal() = default;
    explicit Normal(const raymath::Vector3 &fac) : m_attenuation(fac)
    {};

    [[nodiscard]] std::optional<std::pair<const raylib::Ray, raymath::Vector3>> compute(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept override;
    [[nodiscard]] float getGammaCorrection() const noexcept override;
    [[nodiscard]] bool isOpaque() const noexcept override;
    [[nodiscard]] float getReflectionFactor() const noexcept override;
    [[nodiscard]] float getRefractionFactor() const noexcept override;
};
