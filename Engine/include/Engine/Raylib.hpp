/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "OS.hpp"

#if defined(OS_WINDOWS)
  #pragma warning disable C4244, C4267

  #include <raylib.h>

  #pragma warning restore C4244, C4267
#else

  #include <raylib.h>

#endif
