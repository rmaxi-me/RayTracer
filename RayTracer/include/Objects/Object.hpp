#pragma once

#include <memory>

#include "Engine/Ray/Ray.hpp"
#include "Materials/IMaterial.hpp"



#define T_MIN 0.0
#define T_MAX MAXFLOAT

class Object
{
protected:
    std::shared_ptr<IMaterial> m_material{nullptr};
public:
    enum class Type {
        Cube,
        Sphere,
//        Cylinder
    };
    Object() = default;
    explicit Object(IMaterial *material);
    virtual ~Object() = default;

    Object(const Object &rhs) = default;
    Object &operator=(const Object &rhs) = default;

    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info) = 0;
    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info, std::shared_ptr<IMaterial> &ptr) = 0;
    virtual void attachMaterial(IMaterial *material) final;
    virtual void attachMaterial(std::shared_ptr<IMaterial> material) final;
};
