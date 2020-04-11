#include "Ray.hpp"

namespace raylib
{
    Ray::Ray(Vector3 position, Vector3 direction) : origin(position), direction(direction) {}
    Ray::Ray(maths::Vector3 position, maths::Vector3 direction) : origin(position), direction(direction) {}
    Ray &Ray::operator=(const Ray &value)
    {
        origin = value.origin;
        direction = value.direction;
    }
} // namespace raylib
