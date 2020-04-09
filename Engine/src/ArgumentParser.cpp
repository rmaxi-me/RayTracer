/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "ArgumentParser.hpp"

bool APFuncs::boolean(const std::string &raw)
{
    return raw == "1";
}

float APFuncs::floating(const std::string &raw)
{
    return std::stof(raw);
}

double APFuncs::double_float(const std::string &raw)
{
    return std::stod(raw);
}

ArgumentParser::ArgumentParser(int ac, const char *const *av, std::string_view stopParsing)
        : m_argc{ac}, m_argv{av}, m_binName{av[0]}, m_stopParsing{stopParsing}
{
    for (int i = 1; i < ac; i++) {
        auto flag = std::string_view(av[i]);

        if (flag == m_stopParsing)
            break;

        if (flag.length() >= 2) {
            if (flag[0] == '-') {
                if (flag[1] == '-') {
                    flag.remove_prefix(2);
                } else {
                    flag.remove_prefix(1);
                }

                if (i + 1 < ac && std::string_view(av[i + 1])[0] != '-') {
                    m_args.insert(std::make_pair(flag, std::string(av[i + 1])));
                } else {
                    m_args.insert(std::make_pair(flag, std::string("1")));
                }
            } else {
                m_args.insert(std::make_pair(flag, std::string("1")));
            }
        }
    }
}

int ArgumentParser::getArgc() const noexcept
{
    return m_argc;
}

const char *const *ArgumentParser::getArgv() const noexcept
{
    return m_argv;
}

std::string_view ArgumentParser::getBinName() const noexcept
{
    return m_binName;
}
