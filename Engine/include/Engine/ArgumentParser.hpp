/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <map>
#include <string>
#include <string_view>
#include <functional>

namespace APFuncs {
    template<typename Int>
    Int toInt(const std::string &raw)
    {
        return static_cast<Int>(std::stoll(raw));
    }

    std::string toString(const std::string &raw);
    bool toBool(const std::string &raw);
    float toFloat(const std::string &raw);
    double toDouble(const std::string &raw);
}

class ArgumentParser {
private:
    const int m_argc;
    const char *const *const m_argv;
    std::string_view m_binName;
    std::string_view m_stopParsing;

    std::map<std::string_view, std::string> m_args{};
public:
    ArgumentParser(int ac, const char *const *av, std::string_view stopParsing = "--");

    ArgumentParser(const ArgumentParser &) = delete;
    ArgumentParser &operator=(const ArgumentParser &) = delete;

    template<typename Type>
    Type getOrDefault(decltype(m_args)::key_type key, decltype(m_args)::key_type alias,
                      Type &&defaultValue, std::function<Type(const std::string &rawValue)> conversion) const
    {
        auto value = m_args.find(key);
        if (value != m_args.cend()) {
            return conversion(value->second);
        }

        if (alias != "") {
            value = m_args.find(alias);
            if (value != m_args.cend()) {
                return conversion(value->second);
            }
        }

        return defaultValue;
    }

    [[nodiscard]] std::string_view getBinName() const noexcept;
    [[nodiscard]] int getArgc() const noexcept;
    [[nodiscard]] const char *const *getArgv() const noexcept;
};
