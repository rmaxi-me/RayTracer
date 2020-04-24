/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Utils/Operations.hpp"

#include "Materials/AMaterial.hpp"

AMaterial::AMaterial(const raymath::Vector3 &attenuation, bool opaque, float gammaCorrection, float reflectionFactor, float refractionFactor)
        : m_attenuation(attenuation), m_opaque(opaque),
          m_gammaCorrection(gammaCorrection),
          m_reflectionFactor(reflectionFactor),
          m_refractionFactor(refractionFactor)
{}

AMaterial::~AMaterial()
= default;

RayTraceOpt AMaterial::reflect(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept
{
    raymath::Vector3 reflected = raymath::reflect(raymath::normalize(ray.getDirection()), info.normal);
    raylib::Ray scattered(info.position, reflected);

    if (raymath::dotProduct(scattered.getDirection(), info.normal) > 0)
        return std::pair{scattered, m_attenuation};
    return std::nullopt;
}

RayTraceOpt AMaterial::refract(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept
{
    if (isOpaque())
        return std::nullopt;

    raymath::Vector3 refracted = raymath::refract(raymath::normalize(ray.getDirection()), info.normal, 1.f, getRefractionFactor());
    raylib::Ray scattered(info.position, refracted);

    if (raymath::dotProduct(scattered.getDirection(), info.normal) > 0)
        return std::pair{scattered, m_attenuation};
    return std::nullopt;
}

bool AMaterial::isOpaque() const noexcept
{
    return m_opaque;
}

float AMaterial::getGammaCorrection() const noexcept
{
    return m_gammaCorrection;
}

float AMaterial::getReflectionFactor() const noexcept
{
    return m_reflectionFactor;
}

float AMaterial::getRefractionFactor() const noexcept
{
    return m_refractionFactor;
}

raymath::Vector3 AMaterial::getAttenuation() const noexcept
{
    return m_attenuation;
}

void AMaterial::setAttenuation(const raymath::Vector3 &attenuation) noexcept
{
    m_attenuation = attenuation;
}

void AMaterial::setOpaque(bool opaque) noexcept
{
    m_opaque = opaque;
}

void AMaterial::setGammaCorrection(float gammaCorrection) noexcept
{
    m_gammaCorrection = gammaCorrection;
}

void AMaterial::setReflectionFactor(float reflectionFactor) noexcept
{
    m_reflectionFactor = reflectionFactor;
}

void AMaterial::setRefractionFactor(float refractionFactor) noexcept
{
    m_refractionFactor = refractionFactor;
}
