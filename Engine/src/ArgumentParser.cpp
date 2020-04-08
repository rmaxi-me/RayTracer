/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "ArgumentParser.hpp"

ArgumentParser::ArgumentParser(int ac, char **av)
        : m_argc{ac}, m_argv{av}
{
}

int ArgumentParser::getArgc() const noexcept
{
    return m_argc;
}

const char *const *ArgumentParser::getArgv() const noexcept
{
    return m_argv;
}
