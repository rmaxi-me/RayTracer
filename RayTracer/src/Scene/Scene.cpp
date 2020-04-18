/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <fstream>

#include "Objects/Sphere.hpp"
#include "Engine/Raylib.hpp"
#include "Scene/Scene.hpp"

const std::regex Scene::REGEX{rgx_raw, std::regex_constants::ECMAScript | std::regex_constants::icase};

Scene::Scene()
= default;

std::shared_ptr<Object> Scene::getObject(const RawObject &raw)
{
    auto pos = raymath::Vector3::fromString(raw.position.c_str());

    if (raw.type == "sphere")
        return std::make_shared<Sphere>(pos, std::stof(raw.params));

    TraceLog(TraceLogType::LOG_ERROR, "%s: invalid object.", raw.type.c_str());
    throw std::runtime_error("Invalid object");
}

std::vector<std::shared_ptr<Object>> Scene::rawListToObjList(const std::vector<RawObject> &rawList)
{
    std::vector<std::shared_ptr<Object>> objs{};

    for (const auto &raw : rawList) {
        std::shared_ptr<Object> obj = getObject(raw);
    }

    return objs;
}

Scene Scene::fromFile(const char *filepath)
{
    Scene scene;
    std::ifstream file(filepath);
    std::string line;
    std::size_t lineCount = 0;
    std::vector<RawObject> rawObjects{};

    if (!file) {
        TraceLog(TraceLogType::LOG_ERROR, "%s: Could not open file.", filepath);
        throw std::runtime_error("Invalid file");
    }
    while (std::getline(file, line)) {
        ++lineCount;
        if (line[0] == '#')
            continue;
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        auto line_match = std::sregex_iterator(line.begin(), line.end(), REGEX);
        auto rgx_end = std::sregex_iterator();
        auto matchCount = std::distance(line_match, rgx_end);

        if (matchCount != 1) {
            TraceLog(TraceLogType::LOG_ERROR, "%s:%u: Invalid line format.", filepath, lineCount);
            throw std::runtime_error("Invalid line");
        }

        auto match = *line_match;

        if (match.size() != 6) {
            TraceLog(TraceLogType::LOG_ERROR, "%s:%u: Invalid line format.", filepath, lineCount);
            throw std::runtime_error("Invalid object");
        }
        rawObjects.push_back({*(match.cbegin() + 0),
                              *(match.cbegin() + 1),
                              *(match.cbegin() + 2),
                              *(match.cbegin() + 3),
                              *(match.cbegin() + 4),
                              *(match.cbegin() + 5)});
    }

    scene.m_objectList = std::make_shared<ObjectList>(rawListToObjList(rawObjects));
    return scene;
}

const std::shared_ptr<ObjectList> &Scene::getObjectList() const noexcept
{
    return m_objectList;
}
