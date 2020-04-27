/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Ray/Ray.hpp"

namespace raylib {
    Ray::Ray(Vector3 position, Vector3 direction) : origin(position), direction(direction)
    {}

    Ray::Ray(raymath::Vector3 position, raymath::Vector3 direction) : origin(position), direction(direction)
    {}

    Ray &Ray::operator=(const Ray &value)
    {
        origin = value.origin;
        direction = value.direction;
        return *this;
    }
} // namespace raylib
