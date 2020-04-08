/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

class ArgumentParser {
private:
    const int m_argc;
    const char *const *const m_argv;
public:
    ArgumentParser(int ac, char **av);
};
