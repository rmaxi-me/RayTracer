/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Objects/Object.hpp"

Object::Object(IMaterial *material)
        : m_material(material)
{
}

void Object::attachMaterial(IMaterial *material)
{
    m_material.reset(material);
}

void Object::attachMaterial(std::shared_ptr<IMaterial> material)
{
    m_material = material;
}
