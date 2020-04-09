/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <criterion/criterion.h>
#include <iostream>

#include "Engine/ArgumentParser.hpp"

Test(ArgumentParser, Constructors)
{
    const char *argv[] = {"bin", "--fullscreen", "--width", "1600", "--height", "900"};
    const auto parser = ArgumentParser{6, argv};

    auto fullscreen = parser.getOrDefault<bool>("fullscreen", "f", false, APFuncs::boolean);
    auto missing = parser.getOrDefault<bool>("missing", "m", false, APFuncs::boolean);
    auto width = parser.getOrDefault<int>("width", "w", 1920, APFuncs::integer<int>);
    auto height = parser.getOrDefault<int>("height", "h", 1080, APFuncs::integer<int>);
    auto depth = parser.getOrDefault<int>("depth", "d", 32, APFuncs::integer<int>);

    cr_assert(parser.getBinName() == "bin");
    cr_assert(parser.getArgc() == 6);
    cr_assert(parser.getArgv() == argv);
    cr_assert(fullscreen);
    cr_assert(!missing);
    cr_assert(width == 1600);
    cr_assert(height == 900);
    cr_assert(depth == 32);
}
