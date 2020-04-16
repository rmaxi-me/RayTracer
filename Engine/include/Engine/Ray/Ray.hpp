#pragma once

#include <raylib.h>
#include "Engine/Vector/Vector3.hpp"

namespace raylib
{
    class Ray
    {
    private:
        raymath::Vector3 origin;
        raymath::Vector3 direction;
    public:
        Ray() = default;
        Ray(Vector3 position, Vector3 direction);
        Ray(raymath::Vector3 position, raymath::Vector3 direction);
        Ray &operator=(const Ray &);
        ~Ray() = default;
    public:
        raymath::Vector3 getOrigin() const;
        raymath::Vector3 getDirection() const;
        raymath::Vector3 rayProjection(float f) const;
        ::Ray getRawRay() const;
    };

    inline raymath::Vector3 Ray::getOrigin() const
    {
        return origin;
    }

    inline raymath::Vector3 Ray::getDirection() const
    {
        return direction;
    }

    inline ::Ray Ray::getRawRay() const
    {
        return ::Ray{origin.getRawVector(), direction.getRawVector()};
    }

    inline raymath::Vector3 Ray::rayProjection(float f) const
    {
        return origin + f * direction;
    }
} // namespace raylib
