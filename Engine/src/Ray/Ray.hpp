#pragma once

#include <raylib.h>
#include "Vector/Vector3.hpp"

namespace raylib
{
    class Ray
    {
    private:
        maths::Vector3 origin;
        maths::Vector3 direction;
    public:
        Ray() = default;
        Ray(Vector3 position, Vector3 direction);
        Ray(maths::Vector3 position, maths::Vector3 direction);
        Ray &operator=(const Ray &);
        ~Ray() = default;
    public:
        maths::Vector3 getOrigin() const;
        maths::Vector3 getDirection() const;
        maths::Vector3 rayProjection(float f) const;
        ::Ray getRawRay() const;
    };

    inline maths::Vector3 Ray::getOrigin() const
    {
        return origin;
    }

    inline maths::Vector3 Ray::getDirection() const
    {
        return direction;
    }

    inline ::Ray Ray::getRawRay() const
    {
        return ::Ray{origin.getRawVector(), direction.getRawVector()};
    }

    inline maths::Vector3 Ray::rayProjection(float f) const
    {
        return origin + f * direction;
    }
} // namespace raylib
