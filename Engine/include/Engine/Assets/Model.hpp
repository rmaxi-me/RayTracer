/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Raylib.hpp"

#include "Mesh.hpp"

namespace raylib {
    class Model {
    protected:
        ::Model m_raylibModel;
    public:
        explicit Model(const char *filename);
        explicit Model(const Mesh &mesh);
        ~Model();

        inline void attachTexture(Texture texture)
        {
            m_raylibModel.materials[0].maps[MAP_DIFFUSE].texture = texture;
        }

        inline void setMeshMaterial(int meshId, int materialId)
        {
            SetModelMeshMaterial(&m_raylibModel, meshId, materialId);
        }

        [[nodiscard]] inline const ::Model &getRaylibModel() const
        {
            return m_raylibModel;
        }
    };
}
