/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <regex>

#include "Objects/ObjectList.hpp"

class Scene {
private:
    struct RawObject {
        std::string line;
        std::string type;
        std::string position;
        std::string color;
        std::string material;
        std::string params;
    };

    static constexpr auto rgx_raw = R"(^(\w+) pos=([\d \.-]+) color=(\w+) material=(\w+) params=([\d \.-]+)$)";
    static const std::regex REGEX;

    std::shared_ptr<ObjectList> m_objectList{nullptr};

    Scene();

    static std::shared_ptr<Object> getObject(const RawObject &raw);
    static std::vector<std::shared_ptr<Object>> rawListToObjList(const std::vector<RawObject> &rawList);
public:
    static Scene fromFile(const char *filepath);

    [[nodiscard]] const std::shared_ptr<ObjectList> &getObjectList() const noexcept;
};
