#include "Objects/Sphere.hpp"

Sphere::Sphere(const raymath::Vector3 &c, float r) : center(c), radius(r)
{}

bool Sphere::isHit(const raylib::Ray &r, float tmin, float tmax, raylib::RayHitInfo &info)
{
    raymath::Vector3 oc = r.getOrigin() - center;
    float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    float b = 2.0f * raymath::dotProduct(oc, r.getDirection());
    float c = raymath::dotProduct(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {

        float sol[2];
        sol[0] = (-b - sqrt(b * b - a * c) / a);
        sol[1] = (-b + sqrt(b * b - a * c) / a);
        for (auto &i : sol) {
//             std::cout << i << "|" << tmin << "|" << tmax << std::endl;
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
