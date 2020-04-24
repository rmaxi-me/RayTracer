/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#if defined(__clang__)
  #define COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
  #define COMPILER_GCC
#elif defined(_MSC_VER)
  #define COMPILER_MSC
#endif

#if defined(__linux__) || defined(__linux) || defined(linux) || defined(_LINUX)
  #define OS_LINUX
#elif defined(__APPLE__)
  #define OS_DARWIN
#elif defined(_WIN32) || defined(_WIN64)
  #define OS_WINDOWS
#else
  #error "Unsupported platform"
#endif
