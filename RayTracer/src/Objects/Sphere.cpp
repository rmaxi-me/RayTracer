/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Objects/Sphere.hpp"

Sphere::Sphere(const raymath::Vector3 &c, float r) : center(c), radius(r)
{}

bool Sphere::isHit(const raylib::Ray &r, float tmin, float tmax, raylib::RayHitInfo &info)
{
    const raymath::Vector3 oc = r.getOrigin() - center;
    const float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    const float b = raymath::dotProduct(oc, r.getDirection());
    const float c = raymath::dotProduct(oc, oc) - radius * radius;
    const float discriminant = b * b - a * c;
    const float root = sqrt(discriminant);

    if (discriminant > 0) {
        std::vector<float> sol;
        sol.push_back((-b - root) / a);
        sol.push_back((-b + root) / a);
        for (auto &i : sol) {
            if (i < tmax && i > tmin) {
                info.distance = i;
                info.position = r.rayProjection(i);
                info.normal = (info.position - center) / radius;
                return true;
            }
        }
    }
    return false;
}

bool Sphere::isHit(const raylib::Ray &r, float tmin, float tmax, raylib::RayHitInfo &info, std::shared_ptr<AMaterial> &material)
{
    const raymath::Vector3 oc = r.getOrigin() - center;
    const float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    const float b = raymath::dotProduct(oc, r.getDirection());
    const float c = raymath::dotProduct(oc, oc) - radius * radius;
    const float discriminant = b * b - a * c;
    const float root = sqrt(discriminant);

    if (discriminant > 0) {
        std::vector<float> sol;
        sol.push_back((-b - root) / a);
        sol.push_back((-b + root) / a);
        for (auto &i : sol) {
            if (i < tmax && i > tmin) {
                info.distance = i;
                info.position = r.rayProjection(i);
                info.normal = (info.position - center) / radius;
                material = m_material;
                return true;
            }
        }
    }
    return false;
}

raymath::Vector3 Sphere::getRandomPoint()
{
    raymath::Vector3 point;

    do {
        point = 2.0f * raymath::Vector3(std::generate_canonical<double, 10>(Random::getGenerator()),
                                        std::generate_canonical<double, 10>(Random::getGenerator()),
                                        std::generate_canonical<double, 10>(Random::getGenerator()))
                - raymath::Vector3(1, 1, 1);
    } while (std::pow(point.length(), 2) >= 1.0f);
    return point;
}
