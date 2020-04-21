/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#define RAYGUI_IMPLEMENTATION

#include "Engine/Utils/OS.hpp"

#if defined(OS_LINUX)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
  #pragma GCC diagnostic ignored "-Wunused-parameter"
  #pragma GCC diagnostic ignored "-Wnarrowing"
  #pragma GCC diagnostic ignored "-Wenum-compare"

  #include <raygui.h>

  #pragma GCC diagnostic pop
#elif defined(OS_WINDOWS)
#pragma warning (push)
  #pragma warning (disable : 4244 4267)

  #include <raygui.h>

  #pragma warning (pop)
#else
  #include <raygui.h>
#endif

#undef RAYGUI_IMPLEMENTATION
