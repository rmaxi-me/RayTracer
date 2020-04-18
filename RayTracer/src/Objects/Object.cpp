/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Objects/Object.hpp"

Object::Object(const IMaterial *material)
        : m_material(material)
{
}

void Object::attachMaterial(const IMaterial *material)
{
    m_material = material;
}
