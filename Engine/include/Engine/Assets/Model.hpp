/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <raylib.h>

#include "Mesh.hpp"

namespace raylib {
    class Model {
    protected:
        ::Model m_raylibModel;
    public:
        explicit Model(const char *filename);
        explicit Model(const Mesh &mesh);
        ~Model();
    };
}
