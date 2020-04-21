#include "Objects/Sphere.hpp"

Sphere::Sphere(const raymath::Vector3 &c, float r) : center(c), radius(r)
{}

bool Sphere::isHit(const raylib::Ray &r, float tmin, float tmax, raylib::RayHitInfo &info)
{
    raymath::Vector3 oc = r.getOrigin() - center;
    float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    float b = raymath::dotProduct(oc, r.getDirection());
    float c = raymath::dotProduct(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;

    if (discriminant > 0)
    {
        std::vector<float> sol;
        sol.push_back((-b - sqrt(discriminant)) / a);
        sol.push_back((-b + sqrt(discriminant)) / a);
        for (auto &i : sol)
        {
            if (i < tmax && i > tmin)
            {
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
    raymath::Vector3 oc = r.getOrigin() - center;
    float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    float b = raymath::dotProduct(oc, r.getDirection());
    float c = raymath::dotProduct(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;

    if (discriminant > 0)
    {
        std::vector<float> sol;
        sol.push_back((-b - sqrt(discriminant)) / a);
        sol.push_back((-b + sqrt(discriminant)) / a);
        for (auto &i : sol)
        {
            if (i < tmax && i > tmin)
            {
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
