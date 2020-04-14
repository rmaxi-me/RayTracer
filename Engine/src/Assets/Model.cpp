/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Assets/Model.hpp"

raylib::Model::Model(const char *filename)
        : m_raylibModel{LoadModel(filename)}
{
}

raylib::Model::Model(const raylib::Mesh &mesh)
        : m_raylibModel(LoadModelFromMesh(mesh.getRaylibMesh()))
{
}

raylib::Model::~Model()
{
    UnloadModel(m_raylibModel);
}
