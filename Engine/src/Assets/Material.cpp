/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Assets/Material.hpp"

raylib::Material::Material()
        : m_raylibMaterial(LoadMaterialDefault())
{
}

raylib::Material::Material(::Material raylibMaterial)
        : m_raylibMaterial(raylibMaterial)
{
}

raylib::Material::~Material()
{
    UnloadMaterial(m_raylibMaterial);
}

std::vector<raylib::Material> raylib::Material::loadMaterials(const char *filename)
{
    decltype(loadMaterials("")) vec;
    int count = 0;
    auto materials = LoadMaterials(filename, &count);

    if (materials != nullptr && count > 0) {
        for (int i = 0; i < count; ++i) {
            vec.emplace_back(materials[i]);
        }
    }

    return vec;
}
