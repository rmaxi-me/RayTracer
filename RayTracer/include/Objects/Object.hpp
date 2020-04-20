#pragma once

#include <memory>

#include "Engine/Ray/Ray.hpp"
#include "Materials/AMaterial.hpp"

#define T_MIN 0.0
#define T_MAX MAXFLOAT

class Object {
protected:
    std::shared_ptr<AMaterial> m_material{nullptr};
public:
    Object() = default;
    explicit Object(std::shared_ptr<AMaterial> material);
    virtual ~Object() = default;

    Object(const Object &rhs) = default;
    Object &operator=(const Object &rhs) = default;

    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info) = 0;
    virtual bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info, std::shared_ptr<AMaterial> &ptr) = 0;

    virtual void attachMaterial(std::shared_ptr<AMaterial> material) final;
    virtual const std::shared_ptr<AMaterial> &getMaterial() const noexcept final;
};
