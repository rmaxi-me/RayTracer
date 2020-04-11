#include "Ray/Ray.hpp"

namespace raylib
{
    Ray::Ray(Vector3 position, Vector3 direction) : origin(position), direction(direction) {}
    Ray::Ray(raymath::Vector3 position, raymath::Vector3 direction) : origin(position), direction(direction) {}
    Ray &Ray::operator=(const Ray &value)
    {
        origin = value.origin;
        direction = value.direction;
        return *this;
    }
} // namespace raylib
