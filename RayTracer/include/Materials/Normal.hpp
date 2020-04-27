/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "AMaterial.hpp"

class Normal : public AMaterial {
public:
    explicit Normal(const raymath::Vector3 &fac);

    [[nodiscard]] RayTraceOpt reflect(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept override;
};
