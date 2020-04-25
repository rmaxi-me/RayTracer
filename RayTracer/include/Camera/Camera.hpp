/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Vector/Vector3.hpp"
#include "Engine/Ray/Ray.hpp"

class RCamera {
public:
    RCamera() = default;
    ~RCamera() = default;

    void setOrigin(const raymath::Vector3 &o);
    void setLookAt(const raymath::Vector3 &lookAt);
    void setVUp(const raymath::Vector3 &vUp);

    void setFov(float fov);
    void setAperture(float aperture);
    void setFocusDistance(float focusDistance);
    void setAspectRatio(float aspect);

    void compute();
    raylib::Ray getRay(float i, float j);

private:
    raymath::Vector3 m_origin{};
    raymath::Vector3 m_lower_left_corner{};
    raymath::Vector3 m_horizontal{};
    raymath::Vector3 m_vertical{};

    raymath::Vector3 m_lookAt{};
    raymath::Vector3 m_vUp{};

    float m_fov = 0.0f;
    float m_aspectRatio = 0.0f;
    float m_focusDistance = 0.0f;
    float m_lensRadius = 0.0f;

    raymath::Vector3 m_w{};
    raymath::Vector3 m_u{};
    raymath::Vector3 m_v{};
};
