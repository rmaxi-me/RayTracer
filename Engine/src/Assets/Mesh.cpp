/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Assets/Mesh.hpp"

raylib::Mesh::Mesh(::Mesh raylibMesh)
        : m_raylibMesh{raylibMesh}
{
}

raylib::Mesh::~Mesh()
{
    UnloadMesh(m_raylibMesh);
}

std::vector<raylib::Mesh> raylib::Mesh::loadMeshes(const char *filename)
{
    decltype(loadMeshes("")) vec;
    int count = 0;
    auto meshes = LoadMeshes(filename, &count);

    if (meshes != nullptr && count > 0) {
        for (int i = 0; i < count; ++i) {
            vec.emplace_back(meshes[i]);
        }
    }

    return vec;
}

const Mesh &raylib::Mesh::getRaylibMesh() const noexcept
{
    return m_raylibMesh;
}
