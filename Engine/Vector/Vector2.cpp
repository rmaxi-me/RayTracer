#include <iostream>
#include "Vector2.hpp"

namespace maths
{
    Vector2::Vector2(float x, float y) : Vector({x, y}) {}
    Vector2::Vector2(const Vector2 &Vx) : Vector(Vx.Vector) {}
    Vector2::Vector2(const ::Vector2 &Vx) : Vector(Vx) {}

    Vector2 &Vector2::operator=(const Vector2 &Vx)
    {
        Vector.x = Vx.Vector.x;
        Vector.y = Vx.Vector.y;
    }

    Vector2 &Vector2::operator=(const ::Vector2 &Vx)
    {
        Vector.x = Vx.x;
        Vector.y = Vx.y;
    }

} // namespace maths
