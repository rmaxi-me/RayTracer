#include "Materials/Light.hpp"

std::optional<std::pair<const raylib::Ray, raymath::Vector3>> Light::compute(const raylib::Ray &, raylib::RayHitInfo &) const noexcept
{
    return {};
}

raymath::Vector3 Light::emitt()
{
    return raymath::Vector3(1,1,1);
}
