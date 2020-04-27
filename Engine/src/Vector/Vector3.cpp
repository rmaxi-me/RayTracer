#include <iostream>
#include "Engine/Vector/Vector3.hpp"

namespace raymath {
    Vector3::Vector3(float x, float y, float z) : Vector({x, y, z})
    {}

    Vector3::Vector3(const Vector3 &Vx) : Vector(Vx.Vector)
    {}

    Vector3::Vector3(const ::Vector3 &Vx) : Vector(Vx)
    {}

    Vector3 &Vector3::operator=(const Vector3 &Vx)
    {
        Vector.x = Vx.Vector.x;
        Vector.y = Vx.Vector.y;
        Vector.z = Vx.Vector.z;

        return *this;
    }

    Vector3 &Vector3::operator=(const ::Vector3 &Vx)
    {
        Vector.x = Vx.x;
        Vector.y = Vx.y;
        Vector.z = Vx.z;

        return *this;
    }

    Vector3 Vector3::fromString(const char *source)
    {
        char *end_ptr = const_cast<char *>(source);
        float x = std::strtof(end_ptr, &end_ptr);
        float y = std::strtof(end_ptr, &end_ptr);
        float z = std::strtof(end_ptr, &end_ptr);

        return Vector3(x, y, z);
    }

} // namespace maths

