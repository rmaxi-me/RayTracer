/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <json.hpp>

#include <fstream>

#include "Scene/Scene.hpp"
#include "Objects/Sphere.hpp"
#include "Engine/Raylib.hpp"

#include "Materials/Glass.hpp"
#include "Materials/Normal.hpp"
#include "Materials/VentaBlack.hpp"

Scene::Scene()
= default;

std::shared_ptr<Object> Scene::getObject(const Json &json)
{
    auto type = json["type"].get<std::string>();
    auto position = json["position"].get<std::string>();
    auto params = json["params"];

    if (type == "sphere")
        return std::make_shared<Sphere>(raymath::Vector3::fromString(position.c_str()), params["radius"].get<float>());

    TraceLog(LOG_ERROR, "%s: unknown object", type.c_str());
    throw std::runtime_error("unknown object");
}

std::shared_ptr<AMaterial> Scene::getMaterial(const Json &json)
{
    auto type = json["type"].get<std::string>();
    auto color = json["color"].get<std::string>();
    std::shared_ptr<AMaterial> mat{nullptr};

    if (type == "normal")
        mat = std::make_shared<Normal>();
    else if (type == "glass")
        mat = std::make_shared<Glass>();
    else if (type == "ventablack")
        mat = std::make_shared<VentaBlack>();
    else {
        TraceLog(LOG_ERROR, "%s: unknown material", type.c_str());
        throw std::runtime_error("unknown material");
    }

    mat->setAttenuation(raymath::Vector3::fromString(color.c_str()));
    return mat;
}

Scene Scene::fromFile(const char *filepath)
{
    Scene scene;
    std::ifstream file(filepath);

    if (!file) {
        std::cerr << "Could not open scene file " << filepath << std::endl;
        throw std::runtime_error("Failed to open file");
    }

    Json json;
    file >> json;

    std::vector<std::shared_ptr<Object>> vec;
    for (const auto &elem : json["objects"]) {
        auto obj = getObject(elem);
        auto mat = getMaterial(elem["material"]);

        obj->attachMaterial(mat);
        vec.push_back(std::move(obj));
    }
    scene.m_objectList = std::make_shared<ObjectList>(vec);
    return scene;
}

const std::shared_ptr<ObjectList> &Scene::getObjectList() const noexcept
{
    return m_objectList;
}

