/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "OS.hpp"

#if defined(OS_LINUX)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wmissing-field-initializers"

  #include <raymath.h>

  #pragma GCC diagnostic pop
#elif defined(OS_WINDOWS)
  #pragma warning (push)
  #pragma warning (disable : 4244 4267)

  #include <raymath.h>

  #pragma warning (pop)
#else
  #include <raymath.h>
#endif
