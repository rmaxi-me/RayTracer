/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "RayTracerApp.hpp"

static void show_help(const char *bin)
{
    std::cout << "USAGE\n"
              << '\t' << bin << " (--file/-f) path_to_scene [OPTIONS...]\n\n";

    std::cout << "OPTIONS\n"
                 "\t--file, -f    * Open scene file (json format)\n"
                 "\t--fullscreen    Run app in fullscreen\n"
                 "\t--width, -w   X Set window's width in pixels\n"
                 "\t--height, -h  X Set window's height in pixels\n"
                 "\t--fps         X Set application max FPS\n"
                 "\t--aa, -a      X Set the anti-aliasing level\n"
                 "\n"
                 "* Mandatory\n"
                 "X Optional, requires value (e.g.: --fps 144)\n"

              << std::flush;
}

int main(int ac, char **av)
{
    if (ac > 1 && std::string_view(av[1]) == "--help")
        return show_help(av[0]), 0;
    if (ac < 3)
        return show_help(av[0]), 84;

    try {
        RayTracerApp app(ac, av);

        app.start("Ray Tracer");
    } catch (const std::exception &e) {
        std::cerr << "error: " << e.what() << '\n';
        return 84;
    }
    return 0;
}
