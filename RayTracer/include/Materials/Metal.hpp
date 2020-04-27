/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "AMaterial.hpp"

class Metal : public AMaterial
{
public:
    explicit Metal(const raymath::Vector3 &attenuation);
};
