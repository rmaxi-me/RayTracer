#pragma once

#include "Engine/Utils/Random.hpp"
#include "Object.hpp"

class Sphere : public Object {
private:
    raymath::Vector3 center{};
    float radius{};
public:
    Sphere() = default;
    Sphere(const raymath::Vector3 &, float);
    ~Sphere() override = default;
public:
    bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info) override;
    bool isHit(const raylib::Ray &, float, float, raylib::RayHitInfo &info, std::shared_ptr<AMaterial> &ptr) override;

    static raymath::Vector3 getRandomPoint()
    {
        raymath::Vector3 point;

        do {
            point = 2.0f * raymath::Vector3(std::generate_canonical<double, 10>(Random::getGenerator()),
                                            std::generate_canonical<double, 10>(Random::getGenerator()),
                                            std::generate_canonical<double, 10>(Random::getGenerator()))
                    - raymath::Vector3(1, 1, 1);
        } while (point.length() * point.length() >= 1.0f);
        return point;
    };

};
