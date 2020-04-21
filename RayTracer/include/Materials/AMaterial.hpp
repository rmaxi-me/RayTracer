/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <optional>

#include "Engine/Vector/Vector3.hpp"
#include "Engine/Ray/Ray.hpp"

class AMaterial {
protected:
    raymath::Vector3 m_attenuation{};
public:
    AMaterial();
    explicit AMaterial(const raymath::Vector3 &attenuation);
    virtual ~AMaterial();

    [[nodiscard]] virtual std::optional<std::pair<const raylib::Ray, raymath::Vector3>> compute(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept = 0;

    [[nodiscard]] virtual bool isOpaque() const noexcept = 0;
    [[nodiscard]] virtual float getGammaCorrection() const noexcept = 0;
    [[nodiscard]] virtual float getReflectionFactor() const noexcept = 0;
    [[nodiscard]] virtual float getRefractionFactor() const noexcept = 0;

    virtual void setAttenuation(const raymath::Vector3 &attenuation) noexcept final;
    [[nodiscard]] virtual raymath::Vector3 getAttenuation() const noexcept final;
};
