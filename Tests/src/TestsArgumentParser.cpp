/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <criterion/criterion.h>

#include "Engine/ArgumentParser.hpp"

Test(ArgumentParser, ctor)
{
    auto arg = ArgumentParser{0, nullptr};
    (void) arg;
}
