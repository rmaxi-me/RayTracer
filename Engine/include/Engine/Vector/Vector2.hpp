#pragma once

#include "Engine/Raymath.hpp"
#include <iostream>


#ifndef RAYLIB_H
#define RAYMATH_STANDALONE
#endif

namespace raymath
{

    //--------------------------
    //Class Vector2 declaration

    class Vector2
    {
    private:
        ::Vector2 Vector{};

    public:
        Vector2() = default;
        Vector2(float x, float y);
        Vector2(const Vector2 &);            // Copie Constructor
        Vector2(const ::Vector2 &);             // Constructor from RayMath vector
        Vector2 &operator=(const Vector2 &); // Operator d'affectation
        Vector2 &operator=(const ::Vector2 &);  // Operator d'affectation depuis RayMath vector
        ~Vector2() = default;

    public:
        inline float x() const { return Vector.x; };
        inline float y() const { return Vector.y; };

        inline const Vector2 &operator+() const { return *this; };
        inline const Vector2 operator-() const { return Vector2(-Vector.x, -Vector.y); }

        inline Vector2 &operator+=(const Vector2 &Vx);
        inline Vector2 &operator-=(const Vector2 &Vx);
        inline Vector2 &operator*=(const Vector2 &Vx);
        inline Vector2 &operator*=(const float scale);
        inline Vector2 &operator/=(const Vector2 &Vx);
        inline Vector2 &operator/=(const float div);

        inline float lenght() const { return ::Vector2Length({Vector.x, Vector.y}); };
        inline ::Vector2 getRawVector() const { return Vector; }

        friend std::ostream &operator<<(std::ostream &os, const raymath::Vector2 &v)
        {
            os << v.x() << " " << v.y();
            return os;
        }
    };

    //--------------------------
    //Inline function Definition

    inline Vector2 &Vector2::operator*=(const float scalar)
    {
        Vector.x *= scalar;
        Vector.y *= scalar;
        return *this;
    }

    inline Vector2 &Vector2::operator+=(const Vector2 &Vx)
    {
        Vector.x += Vx.Vector.x;
        Vector.y += Vx.Vector.y;
        return *this;
    }

    inline Vector2 &Vector2::operator*=(const Vector2 &Vx)
    {
        Vector.x *= Vx.Vector.x;
        Vector.y *= Vx.Vector.y;
        return *this;
    }

    inline Vector2 &Vector2::operator/=(const Vector2 &Vx)
    {
        Vector.x /= Vx.Vector.x;
        Vector.y /= Vx.Vector.y;
        return *this;
    }

    inline Vector2 &Vector2::operator-=(const Vector2 &Vx)
    {
        Vector.x -= Vx.Vector.x;
        Vector.y -= Vx.Vector.y;
        return *this;
    }

    inline Vector2 &Vector2::operator/=(const float div)
    {
        Vector.x /= div;
        Vector.y /= div;
        return *this;
    }

    inline raymath::Vector2 operator+(const raymath::Vector2 &Vx, const raymath::Vector2 &Vy)
    {
        ::Vector2 Vz = ::Vector2Add(Vx.getRawVector(), Vy.getRawVector());
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator-(const raymath::Vector2 &Vx, const raymath::Vector2 &Vy)
    {
        ::Vector2 Vz = ::Vector2Subtract(Vx.getRawVector(), Vy.getRawVector());
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator*(const raymath::Vector2 &Vx, const raymath::Vector2 &Vy)
    {
        ::Vector2 Vz = ::Vector2Multiply(Vx.getRawVector(), Vy.getRawVector());
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator*(const raymath::Vector2 &Vx, float Scalar)
    {
        ::Vector2 Vz = ::Vector2Scale(Vx.getRawVector(), Scalar);
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator*(float Scalar, const raymath::Vector2 &Vx)
    {
        ::Vector2 Vz = ::Vector2Scale(Vx.getRawVector(), Scalar);
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator/(const raymath::Vector2 &Vx, const raymath::Vector2 &Vy)
    {
        ::Vector2 Vz = ::Vector2Divide(Vx.getRawVector(), Vy.getRawVector());
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator/(const raymath::Vector2 &Vx, float Scalar)
    {
        ::Vector2 Vz = ::Vector2Divide(Vx.getRawVector(), {Scalar, Scalar});
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline raymath::Vector2 operator/(float Scalar, const raymath::Vector2 &Vx)
    {
        ::Vector2 Vz = ::Vector2Divide(Vx.getRawVector(), {Scalar, Scalar});
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline float dotProduct(const raymath::Vector2 &Vx, const raymath::Vector2 &Vy)
    {
        return ::Vector2DotProduct(Vx.getRawVector(), Vy.getRawVector());
    }

    inline raymath::Vector2 normalize(const raymath::Vector2 &Vx)
    {
        ::Vector2 Vz = ::Vector2Normalize(Vx.getRawVector());
        return raymath::Vector2(Vz.x, Vz.y);
    }

    inline bool operator==(const raymath::Vector2 Vx, const raymath::Vector2 Vy)
    {
        return Vx.x() == Vy.x() && Vx.y() == Vy.y();
    }
    //--------------------------
    //--------------------------
} // namespace maths
