#include <criterion/criterion.h>
#include <iostream>

#include "Vector/Vector3.hpp"

Test(Vector3, Constructors)
{
    maths::Vector_3 Vec;
    maths::Vector_3 Vec2 = Vec;

    maths::Vector_3 Vec3(5, 6, 7);
    maths::Vector_3 Vec4(Vec3);

    Vector3 raylibVector = { 10, 11, 12 };
    maths::Vector_3 Vec5(raylibVector);
    maths::Vector_3 Vec6 = raylibVector;

    cr_assert(Vec.x() == 0 && Vec.y() == 0 && Vec.z() == 0);
    cr_assert(Vec2.x() == 0 && Vec2.y() == 0 && Vec2.z() == 0);

    cr_assert(Vec3.x() == 5 && Vec3.y() == 6 && Vec3.z() == 7);
    cr_assert(Vec4.x() == 5 && Vec4.y() == 6 && Vec4.z() == 7);

    cr_assert(Vec5.x() == 10 && Vec5.y() == 11 && Vec5.z() == 12);
    cr_assert(Vec6.x() == 10 && Vec6.y() == 11 && Vec6.z() == 12);
}

Test(Vector3, Operation)
{
    maths::Vector_3 VecX(3, 2, 1);
    maths::Vector_3 VecY(1, 2, 3);

    VecX += VecY;
    cr_assert(VecX == maths::Vector_3(4,4,4));

    VecX -= VecY;
    cr_assert(VecX == maths::Vector_3(3, 2, 1));

    VecX *= VecY;
    cr_assert(VecX == maths::Vector_3(3, 4, 3));

    VecX /= VecY;
    cr_assert(VecX == maths::Vector_3(3, 2, 1));

    VecX *= 5;
    cr_assert(VecX == maths::Vector_3(15, 10, 5));

    VecX /= 5;
    cr_assert(VecX == maths::Vector_3(3, 2, 1));

    cr_assert(-VecX == maths::Vector_3(-3, -2, -1));
    
    cr_assert(VecX - VecY == maths::Vector_3(2, 0, -2));
    cr_assert(VecX + VecY == maths::Vector_3(4, 4, 4));
    cr_assert(VecX * VecY == maths::Vector_3(3, 4, 3));
    cr_assert(VecX * 5 == maths::Vector_3(15, 10, 5));
    cr_assert(VecX / maths::Vector_3(2,2,2) == maths::Vector_3(1.5, 1, 0.5));
    cr_assert(VecX / 2 == maths::Vector_3(1.5, 1, 0.5));
}

Test(Vector3, Product)
{
    maths::Vector_3 VecX(3, 2, 1);
    maths::Vector_3 VecY(1, 2, 3);

    cr_assert(dotProduct(VecX, VecY) == 10.0f);
    cr_assert(crossProduct(VecX, VecY) == maths::Vector_3(4.0f, -8.0f, 4.0f));
}