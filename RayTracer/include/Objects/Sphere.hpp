#pragma once

#include "Object.hpp"

class Sphere : public Object
{
private:
    float radius;
    raymath::Vector3 center;
public:
    Sphere() = default;
    Sphere(raymath::Vector3, float);
    virtual ~Sphere() = default;
public:
    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info);
};