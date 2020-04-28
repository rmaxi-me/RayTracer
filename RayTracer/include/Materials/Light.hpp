/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "AMaterial.hpp"

class Light : public AMaterial {
private:
    raymath::Vector3 m_light{1, 1, 1};
public:
    explicit Light(const raymath::Vector3 &light) : m_light(light)
    {};

    [[nodiscard]] virtual std::optional<std::pair<const raylib::Ray, raymath::Vector3>> compute(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept;
    [[nodiscard]] raymath::Vector3 emit() override;

    ~Light() override = default;
};
