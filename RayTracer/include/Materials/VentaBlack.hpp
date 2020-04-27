/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Materials/AMaterial.hpp"

class VentaBlack : public AMaterial {
public:
    VentaBlack();

    [[nodiscard]] RayTraceOpt reflect(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept override;
    [[nodiscard]] RayTraceOpt refract(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept override;
};
