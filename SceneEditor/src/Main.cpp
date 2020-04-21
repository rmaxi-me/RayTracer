/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "SceneEditorApp.hpp"

int main(int ac, char **av)
{
    try {
        SceneEditorApp app(ac, av);

        app.start();
    } catch (const std::exception &e) {
        std::cerr << "error: " << e.what() << '\n';
        return 84;
    }
    return 0;
}
