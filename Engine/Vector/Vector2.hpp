#pragma once

#include <raymath.h>
#include <iostream>


#ifndef RAYLIB_H
#define RAYMATH_STANDALONE
#endif

namespace maths
{

    //--------------------------
    //Class Vector_2 declaration

    class Vector_2
    {
    private:
        Vector2 Vector = {0};

    public:
        Vector_2() = default;
        Vector_2(float x, float y);
        Vector_2(const Vector_2 &);            // Copie Constructor
        Vector_2(const Vector2 &);             // Constructor from RayMath vector
        Vector_2 &operator=(const Vector_2 &); // Operator d'affectation
        Vector_2 &operator=(const Vector2 &);  // Operator d'affectation depuis RayMath vector
        ~Vector_2() = default;

    public:
        inline float x() const { return Vector.x; };
        inline float y() const { return Vector.y; };

        inline const Vector_2 &operator+() const { return *this; };
        inline const Vector_2 operator-() const { return Vector_2(-Vector.x, -Vector.y); }

        inline Vector_2 &operator+=(const Vector_2 &Vx);
        inline Vector_2 &operator-=(const Vector_2 &Vx);
        inline Vector_2 &operator*=(const Vector_2 &Vx);
        inline Vector_2 &operator*=(const float scale);
        inline Vector_2 &operator/=(const Vector_2 &Vx);
        inline Vector_2 &operator/=(const float div);

        inline float lenght() const { return Vector2Length({Vector.x, Vector.y}); };
        inline Vector2 getRawVector() const { return Vector; }

        friend std::ostream &operator<<(std::ostream &os, const maths::Vector_2 &v)
        {
            os << v.x() << " " << v.y();
            return os;
        }
    };

    //--------------------------
    //Inline function Definition

    inline Vector_2 &Vector_2::operator*=(const float scalar)
    {
        Vector.x *= scalar;
        Vector.y *= scalar;
        return *this;
    }

    inline Vector_2 &Vector_2::operator+=(const Vector_2 &Vx)
    {
        Vector.x += Vx.Vector.x;
        Vector.y += Vx.Vector.y;
        return *this;
    }

    inline Vector_2 &Vector_2::operator*=(const Vector_2 &Vx)
    {
        Vector.x *= Vx.Vector.x;
        Vector.y *= Vx.Vector.y;
        return *this;
    }

    inline Vector_2 &Vector_2::operator/=(const Vector_2 &Vx)
    {
        Vector.x /= Vx.Vector.x;
        Vector.y /= Vx.Vector.y;
        return *this;
    }

    inline Vector_2 &Vector_2::operator-=(const Vector_2 &Vx)
    {
        Vector.x -= Vx.Vector.x;
        Vector.y -= Vx.Vector.y;
        return *this;
    }

    inline Vector_2 &Vector_2::operator/=(const float div)
    {
        Vector.x /= div;
        Vector.y /= div;
        return *this;
    }

    inline maths::Vector_2 operator+(const maths::Vector_2 &Vx, const maths::Vector_2 &Vy)
    {
        Vector2 Vz = Vector2Add(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator-(const maths::Vector_2 &Vx, const maths::Vector_2 &Vy)
    {
        Vector2 Vz = Vector2Subtract(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator*(const maths::Vector_2 &Vx, const maths::Vector_2 &Vy)
    {
        Vector2 Vz = Vector2MultiplyV(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator*(const maths::Vector_2 &Vx, float Scalar)
    {
        Vector2 Vz = Vector2Scale(Vx.getRawVector(), Scalar);
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator*(float Scalar, const maths::Vector_2 &Vx)
    {
        Vector2 Vz = Vector2Scale(Vx.getRawVector(), Scalar);
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator/(const maths::Vector_2 &Vx, const maths::Vector_2 &Vy)
    {
        Vector2 Vz = Vector2DivideV(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator/(const maths::Vector_2 &Vx, float Scalar)
    {
        Vector2 Vz = Vector2Divide(Vx.getRawVector(), Scalar);
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline maths::Vector_2 operator/(float Scalar, const maths::Vector_2 &Vx)
    {
        Vector2 Vz = Vector2Divide(Vx.getRawVector(), Scalar);
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline float dotProduct(const maths::Vector_2 &Vx, const maths::Vector_2 &Vy)
    {
        return Vector2DotProduct(Vx.getRawVector(), Vy.getRawVector());
    }

    inline maths::Vector_2 normalize(const maths::Vector_2 &Vx)
    {
        Vector2 Vz = Vector2Normalize(Vx.getRawVector());
        return maths::Vector_2(Vz.x, Vz.y);
    }

    inline bool operator==(const maths::Vector_2 Vx, const maths::Vector_2 Vy)
    {
        return Vx.x() == Vy.x() && Vx.y() == Vy.y();
    }
    //--------------------------
    //--------------------------
} // namespace maths
