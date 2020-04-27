#include "Camera/Camera.hpp"
#include "Engine/Utils/Random.hpp"

void RCamera::compute()
{
    float theta = m_fov * DEG2RAD;

    auto half_height = tan(theta / 2);
    auto half_width = m_aspectRatio * half_height;

    m_w = raymath::normalize(m_origin - m_lookAt);
    m_u = raymath::normalize(raymath::crossProduct(m_vUp, m_w));
    m_v = raymath::crossProduct(m_w, m_u);

    m_lower_left_corner = m_origin - half_width * m_focusDistance * m_u - half_height * m_focusDistance * m_v - m_focusDistance * m_w;
    m_horizontal = 2 * half_width * m_focusDistance * m_u;
    m_vertical = 2 * half_height * m_focusDistance * m_v;
}

raymath::Vector3 randomUnitDisk()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(-1, 1);

    // while (true)
    // {
    //     auto point = raymath::Vector3(dis(gen), dis(gen), 0.0f);
    //     if (point.lenght() * point.lenght() >= 1)
    //         continue;
    //     return point;
    // }
    raymath::Vector3 p;
    do {
        p = 2.0 * raymath::Vector3(dis(gen), dis(gen), 0) - raymath::Vector3(1, 1, 0);
    } while (raymath::dotProduct(p, p) >= 1.0);
    return p;
}

raylib::Ray RCamera::getRay(float s, float t)
{
    raymath::Vector3 rd = m_lensRadius * randomUnitDisk();
    raymath::Vector3 offset = m_u * rd.x() + m_v * rd.y();
    return raylib::Ray(m_origin + offset, m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin - offset);
}

void RCamera::setOrigin(const raymath::Vector3 &o)
{ m_origin = o; }

void RCamera::setLookAt(const raymath::Vector3 &lookAt)
{ m_lookAt = lookAt; }

void RCamera::setVUp(const raymath::Vector3 &vUp)
{ m_vUp = vUp; }

void RCamera::setFov(float fov)
{ m_fov = fov; }

void RCamera::setAperture(float aperture)
{ m_lensRadius = aperture / 2; }

void RCamera::setFocusDistance(float focusDistance)
{ m_focusDistance = focusDistance; }

void RCamera::setAspectRatio(float aspect)
{ m_aspectRatio = aspect; }
