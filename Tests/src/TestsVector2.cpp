#include <criterion/criterion.h>
#include <iostream>

#include "Vector/Vector2.hpp"

Test(Vector2, Constructors)
{
    raymath::Vector2 Vec;
    raymath::Vector2 Vec2 = Vec;

    raymath::Vector2 Vec3(5, 6);
    raymath::Vector2 Vec4(Vec3);

    Vector2 raylibVector = { 10, 11};
    raymath::Vector2 Vec5(raylibVector);
    raymath::Vector2 Vec6 = raylibVector;

    cr_assert(Vec.x() == 0 && Vec.y() == 0);
    cr_assert(Vec2.x() == 0 && Vec2.y() == 0);

    cr_assert(Vec3.x() == 5 && Vec3.y() == 6);
    cr_assert(Vec4.x() == 5 && Vec4.y() == 6);

    cr_assert(Vec5.x() == 10 && Vec5.y() == 11);
    cr_assert(Vec6.x() == 10 && Vec6.y() == 11);
}

Test(Vector2, Operation)
{
    raymath::Vector2 VecX(3, 2);
    raymath::Vector2 VecY(1, 2);

    VecX += VecY;
    cr_assert(VecX == raymath::Vector2(4,4));

    VecX -= VecY;
    cr_assert(VecX == raymath::Vector2(3, 2));

    VecX *= VecY;
    cr_assert(VecX == raymath::Vector2(3, 4));

    VecX /= VecY;
    cr_assert(VecX == raymath::Vector2(3, 2));

    VecX *= 5;
    cr_assert(VecX == raymath::Vector2(15, 10));

    VecX /= 5;
    cr_assert(VecX == raymath::Vector2(3, 2));

    cr_assert(-VecX == raymath::Vector2(-3, -2));
    
    cr_assert(VecX - VecY == raymath::Vector2(2, 0));
    cr_assert(VecX + VecY == raymath::Vector2(4, 4));
    cr_assert(VecX * VecY == raymath::Vector2(3, 4));
    cr_assert(VecX * 5 == raymath::Vector2(15, 10));
    cr_assert(VecX / raymath::Vector2(2,2) == raymath::Vector2(1.5, 1));
    cr_assert(VecX / 2 == raymath::Vector2(1.5, 1));
}

Test(Vector2, Product)
{
    raymath::Vector2 VecX(3, 2);
    raymath::Vector2 VecY(1, 2);

    cr_assert(dotProduct(VecX, VecY) == 7.0f);
}
