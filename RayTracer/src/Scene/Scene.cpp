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

#include "Materials/Glass.hpp"
#include "Materials/Normal.hpp"
#include "Materials/VentaBlack.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Light.hpp"

Scene::Scene()
= default;

std::shared_ptr<Object> Scene::getObject(const Json &json)
{
    const auto type = json["type"].get<std::string>();
    const auto position = json["position"].get<std::string>();
    const auto params = json["params"];

    if (type == "sphere")
        return std::make_shared<Sphere>(raymath::Vector3::fromString(position.c_str()), params["radius"].get<float>());

    TraceLog(LOG_ERROR, "%s: unknown object", type.c_str());
    throw std::runtime_error("unknown object");
}

std::shared_ptr<AMaterial> Scene::getMaterial(const Json &json)
{
    const auto type = json["type"].get<std::string>();
    const auto color = json["color"].get<std::string>();
    const auto colorVec = raymath::Vector3::fromString(color.c_str());
    std::shared_ptr<AMaterial> mat{nullptr};

    if (type == "normal")
        mat = std::make_shared<Normal>(colorVec);
    else if (type == "glass")
        mat = std::make_shared<Glass>(colorVec);
    else if (type == "ventablack")
        mat = std::make_shared<VentaBlack>();
    else if (type == "metal")
        mat = std::make_shared<Metal>(colorVec);
    else if (type == "light")
        mat = std::make_shared<Light>(colorVec);
    else {
        TraceLog(LOG_ERROR, "%s: unknown material", type.c_str());
        throw std::runtime_error("unknown material");
    }

    if (json.contains("gamma_correction"))
        mat->setGammaCorrection(json["gamma_correction"].get<float>());
    if (json.contains("reflection_factor"))
        mat->setReflectionFactor(json["reflection_factor"].get<float>());
    if (json.contains("refraction_factor"))
        mat->setRefractionFactor(json["refraction_factor"].get<float>());
    return mat;
}

RCamera Scene::getCamera(const Json &json)
{
    RCamera cam;

    cam.setOrigin(raymath::Vector3::fromString(json["origin"].get<std::string>().c_str()));
    cam.setLookAt(raymath::Vector3::fromString(json["look_at"].get<std::string>().c_str()));
    cam.setVUp(raymath::Vector3::fromString(json["v_up"].get<std::string>().c_str()));
    cam.setFov(json["field_of_view"].get<float>());
    cam.setAperture(json["aperture"].get<float>());
    cam.setFocusDistance(json["focus_distance"].get<float>());
    return cam;
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
    scene.m_camera = getCamera(json["camera"]);
    return scene;
}

const std::shared_ptr<ObjectList> &Scene::getObjectList() const noexcept
{
    return m_objectList;
}

const RCamera &Scene::getCamera() const noexcept
{
    return m_camera;
}

