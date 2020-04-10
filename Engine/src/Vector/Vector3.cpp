#include <iostream>
#include "Vector/Vector3.hpp"


namespace maths
{
    Vector_3::Vector_3(float x, float y, float z) : Vector({x,y,z}) {}
    Vector_3::Vector_3(const Vector_3 &Vx) : Vector(Vx.Vector) {}
    Vector_3::Vector_3(const Vector3 &Vx) : Vector(Vx) {}
    
    Vector_3 &Vector_3::operator=(const Vector_3 &Vx)
    {
        Vector.x = Vx.Vector.x;
        Vector.y = Vx.Vector.y;
        Vector.z = Vx.Vector.z;

        return *this;
    }

    Vector_3 &Vector_3::operator=(const Vector3 &Vx)
    {
        Vector.x = Vx.x;
        Vector.y = Vx.y;
        Vector.z = Vx.z;

        return *this;
    }

} // namespace maths

