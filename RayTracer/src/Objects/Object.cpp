/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <utility>

#include "Objects/Object.hpp"

Object::Object(std::shared_ptr<IMaterial> material)
        : m_material(std::move(material))
{
}

void Object::attachMaterial(std::shared_ptr<IMaterial> material)
{
    m_material = std::move(material);
}

void Object::setColor(const raymath::Vector3 &color)
{
    m_color = color;
}
