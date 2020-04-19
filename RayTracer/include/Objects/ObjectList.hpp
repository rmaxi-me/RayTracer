#pragma once

#include <utility>
#include <vector>
#include <memory>
#include "Object.hpp"

class ObjectList : public Object {
private:
    std::vector<std::shared_ptr<Object>> list{};

public:
    ObjectList() = default;

    explicit ObjectList(std::vector<std::shared_ptr<Object>> obj)
            : list(std::move(obj))
    {}

    ~ObjectList() override = default;

public:
    //Fill the data of the closest obj hit
    //Cause we dont want to see something behind an obj
    bool isHit(const raylib::Ray &r, float t_min, float t_max, raylib::RayHitInfo &info) override
    {
        raylib::RayHitInfo tmpInfo;
        bool hasHit = false;
        float closestObj = t_max;

        for (auto &i : list) {
            if (i->isHit(r, t_min, closestObj, tmpInfo)) {
                hasHit = true;
                closestObj = tmpInfo.distance;
                info = tmpInfo;
            }
        }
        return hasHit;
    }
};
