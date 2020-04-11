#pragma once

#include <raymath.h>

#ifndef RAYLIB_H
#define RAYMATH_STANDALONE
#endif


namespace maths
{

    //--------------------------
    //Class Vector3 declaration

    class Vector3
    {
    private:
        ::Vector3 Vector = {0};
    public:
        Vector3() = default;
        Vector3(float x, float y, float z);
        Vector3(const Vector3 &);               // Copie Constructor
        Vector3(const ::Vector3 &);               // Constructor from RayMath vector
        Vector3 &operator=(const Vector3 &);    // Operator d'affectation
        Vector3 &operator=(const ::Vector3 &);     // Operator d'affectation depuis RayMath vector
        ~Vector3() = default;
    public:
        inline float x() const { return Vector.x; };
        inline float y() const { return Vector.y; };
        inline float z() const { return Vector.z; };

        inline const Vector3 &operator+() const { return *this; };
        inline const Vector3  operator-() const { return Vector3(-Vector.x, -Vector.y, -Vector.z); }

        inline Vector3 &operator+=(const Vector3 &Vx);
        inline Vector3 &operator-=(const Vector3 &Vx);
        inline Vector3 &operator*=(const Vector3 &Vx);
        inline Vector3 &operator*=(const float scale);
        inline Vector3 &operator/=(const Vector3 &Vx);
        inline Vector3 &operator/=(const float div);

        inline float lenght() const { return Vector3Length({Vector.x, Vector.y, Vector.z}); };
        inline ::Vector3 getRawVector() const { return Vector; }

        friend std::ostream &operator<<(std::ostream &os, const maths::Vector3 &v)
        {
            os << v.x() << " " << v.y() << " " << v.z();
            return os;
        }
    };

    //--------------------------
    //Inline function Definition

    inline Vector3 &Vector3::operator*=(const float scalar)
    {
        Vector.x *= scalar;
        Vector.y *= scalar;
        Vector.z *= scalar;
        return *this;
    }

    inline Vector3 &Vector3::operator+=(const Vector3 &Vx)
    {
        Vector.x += Vx.Vector.x;
        Vector.y += Vx.Vector.y;
        Vector.z += Vx.Vector.z;
        return *this;
    }

    inline Vector3 &Vector3::operator*=(const Vector3 &Vx)
    {
        Vector.x *= Vx.Vector.x;
        Vector.y *= Vx.Vector.y;
        Vector.z *= Vx.Vector.z;
        return *this;
    }

    inline Vector3 &Vector3::operator/=(const Vector3 &Vx)
    {
        Vector.x /= Vx.Vector.x;
        Vector.y /= Vx.Vector.y;
        Vector.z /= Vx.Vector.z;
        return *this;
    }

    inline Vector3 &Vector3::operator-=(const Vector3 &Vx)
    {
        Vector.x -= Vx.Vector.x;
        Vector.y -= Vx.Vector.y;
        Vector.z -= Vx.Vector.z;
        return *this;
    }

    inline Vector3 &Vector3::operator/=(const float div)
    {
        Vector.x /= div;
        Vector.y /= div;
        Vector.z /= div;
        return *this;
    }

    inline maths::Vector3 operator+(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        ::Vector3 Vz = Vector3Add(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator-(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        ::Vector3 Vz = Vector3Subtract(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator*(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        ::Vector3 Vz = Vector3Multiply(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator*(const maths::Vector3 &Vx, float Scalar)
    {
        ::Vector3 Vz = Vector3Scale(Vx.getRawVector(), Scalar);
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator*(float Scalar, const maths::Vector3 &Vx)
    {
        ::Vector3 Vz = Vector3Scale(Vx.getRawVector(), Scalar);
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator/(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        ::Vector3 Vz = Vector3DivideV(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator/(const maths::Vector3 &Vx, float Scalar)
    {
        ::Vector3 Vz = Vector3Divide(Vx.getRawVector(), Scalar);
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 operator/(float Scalar, const maths::Vector3 &Vx)
    {
        ::Vector3 Vz = Vector3Divide(Vx.getRawVector(), Scalar);
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline float dotProduct(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        return Vector3DotProduct(Vx.getRawVector(), Vy.getRawVector());
    }

    inline maths::Vector3 crossProduct(const maths::Vector3 &Vx, const maths::Vector3 &Vy)
    {
        ::Vector3 Vz = Vector3CrossProduct(Vx.getRawVector(), Vy.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline maths::Vector3 normalize(const maths::Vector3 &Vx)
    {
        ::Vector3 Vz = Vector3Normalize(Vx.getRawVector());
        return maths::Vector3(Vz.x, Vz.y, Vz.z);
    }

    inline bool operator==(const maths::Vector3 Vx, const maths::Vector3 Vy)
    {
        return Vx.x() == Vy.x() && Vx.y() == Vy.y() && Vx.z() == Vy.z();
    }
    //--------------------------
    //--------------------------

} // namespace maths


