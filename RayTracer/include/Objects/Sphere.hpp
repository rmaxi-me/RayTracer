#pragma once

#include "Object.hpp"

class Sphere : public Object {
private:
    raymath::Vector3 center;
    float radius{};
public:
    Sphere() = default;
    Sphere(const raymath::Vector3 &, float);
    virtual ~Sphere() = default;
public:
    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info);
};
