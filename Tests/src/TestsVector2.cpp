#include <criterion/criterion.h>
#include <iostream>

#include "Vector/Vector2.hpp"

Test(Vector2, Constructors)
{
    maths::Vector_2 Vec;
    maths::Vector_2 Vec2 = Vec;

    maths::Vector_2 Vec3(5, 6);
    maths::Vector_2 Vec4(Vec3);

    Vector2 raylibVector = { 10, 11};
    maths::Vector_2 Vec5(raylibVector);
    maths::Vector_2 Vec6 = raylibVector;

    cr_assert(Vec.x() == 0 && Vec.y() == 0);
    cr_assert(Vec2.x() == 0 && Vec2.y() == 0);

    cr_assert(Vec3.x() == 5 && Vec3.y() == 6);
    cr_assert(Vec4.x() == 5 && Vec4.y() == 6);

    cr_assert(Vec5.x() == 10 && Vec5.y() == 11);
    cr_assert(Vec6.x() == 10 && Vec6.y() == 11);
}

Test(Vector2, Operation)
{
    maths::Vector_2 VecX(3, 2);
    maths::Vector_2 VecY(1, 2);

    VecX += VecY;
    cr_assert(VecX == maths::Vector_2(4,4));

    VecX -= VecY;
    cr_assert(VecX == maths::Vector_2(3, 2));

    VecX *= VecY;
    cr_assert(VecX == maths::Vector_2(3, 4));

    VecX /= VecY;
    cr_assert(VecX == maths::Vector_2(3, 2));

    VecX *= 5;
    cr_assert(VecX == maths::Vector_2(15, 10));

    VecX /= 5;
    cr_assert(VecX == maths::Vector_2(3, 2));

    cr_assert(-VecX == maths::Vector_2(-3, -2));
    
    cr_assert(VecX - VecY == maths::Vector_2(2, 0));
    cr_assert(VecX + VecY == maths::Vector_2(4, 4));
    cr_assert(VecX * VecY == maths::Vector_2(3, 4));
    cr_assert(VecX * 5 == maths::Vector_2(15, 10));
    cr_assert(VecX / maths::Vector_2(2,2) == maths::Vector_2(1.5, 1));
    cr_assert(VecX / 2 == maths::Vector_2(1.5, 1));
}

Test(Vector2, Product)
{
    maths::Vector_2 VecX(3, 2);
    maths::Vector_2 VecY(1, 2);

    cr_assert(dotProduct(VecX, VecY) == 7.0f);
}