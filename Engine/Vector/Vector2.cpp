#include <iostream>
#include "Vector2.hpp"

namespace maths
{
    Vector_2::Vector_2(float x, float y) : Vector({x, y}) {}
    Vector_2::Vector_2(const Vector_2 &Vx) : Vector(Vx.Vector) {}
    Vector_2::Vector_2(const Vector2 &Vx) : Vector(Vx) {}

    Vector_2 &Vector_2::operator=(const Vector_2 &Vx)
    {
        Vector.x = Vx.Vector.x;
        Vector.y = Vx.Vector.y;

        return *this;
    }

    Vector_2 &Vector_2::operator=(const Vector2 &Vx)
    {
        Vector.x = Vx.x;
        Vector.y = Vx.y;

        return *this;
    }

} // namespace maths
