#pragma once

#include "Engine/Ray/Ray.hpp"
#include "Materials/IMaterial.hpp"

#define T_MIN 0.0
#define T_MAX MAXFLOAT

class Object
{
protected:
    const IMaterial *m_material{nullptr};
public:
    enum class Type {
        Cube,
        Sphere,
//        Cylinder
    };
    Object() = default;
    explicit Object(const IMaterial *material);
    virtual ~Object() = default;

    Object(const Object &rhs) = default;
    Object &operator=(const Object &rhs) = default;

    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info) = 0;
    virtual void attachMaterial(const IMaterial *material) final;
};
