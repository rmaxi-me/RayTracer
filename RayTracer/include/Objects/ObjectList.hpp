#pragma once

#include <vector>
#include "Object.hpp"

class ObjectList : public Object
{
private:
    std::vector<Object *> list;

public:
    ObjectList() = default;
    ObjectList(std::vector<Object *> obj) : list(obj) {}
    virtual ~ObjectList() = default;

public:
    //Fill the data of the closest obj hit
    //Cause we dont want to see something behind an obj
    virtual bool isHit(const raylib::Ray &r, float t_min, float t_max, raylib::RayHitInfo &rec)
    {
        raylib::RayHitInfo tmpInfo;
        bool hasHit = false;
        float closestObj = t_max;

        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]->isHit(r, t_min, closestObj, tmpInfo))
            {
                hasHit = true;
                closestObj = tmpInfo.distance;
                rec = tmpInfo;
            }
        }
        return hasHit;
    }
};
