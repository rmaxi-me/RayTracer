/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <utility>

#include "Objects/Object.hpp"

Object::Object(std::shared_ptr<AMaterial> material)
        : m_material(std::move(material))
{
}

void Object::attachMaterial(std::shared_ptr<AMaterial> material)
{
    m_material = std::move(material);
}

const std::shared_ptr<AMaterial> &Object::getMaterial() const noexcept
{
    return m_material;
}
