/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/Metal.hpp"
#include "Objects/Sphere.hpp"
#include "Engine/Utils/Operations.hpp"

Metal::Metal(const raymath::Vector3 &attenuation)
        : AMaterial(attenuation, true, 0, 0.25f, 0.f)
{
}

