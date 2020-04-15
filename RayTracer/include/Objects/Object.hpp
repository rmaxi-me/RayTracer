#pragma once

#include "Ray/Ray.hpp"

#define T_MIN 0.0
#define T_MAX MAXFLOAT


class Object
{
public:
    virtual ~Object() = default;
    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info) = 0;
};