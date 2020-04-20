/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Utils/OS.hpp"

#if defined(OS_WINDOWS)
  #pragma warning (push)
  #pragma warning (disable : 4244 4267)

  #include <raylib.h>

  #pragma warning (pop)
#else

  #include <raylib.h>

#endif
