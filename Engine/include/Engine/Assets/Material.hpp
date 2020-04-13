/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <raylib.h>

#include <vector>

namespace raylib {
    class Material {
    private:
        ::Material m_raylibMaterial;
    public:
        Material();
        explicit Material(::Material raylibMaterial);
        ~Material();

        static std::vector<Material> loadMaterials(const char *filename);
    };
}
