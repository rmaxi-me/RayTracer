/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <json.hpp>

#include "Camera/Camera.hpp"
#include "Objects/ObjectList.hpp"

using Json = nlohmann::json;

class Scene {
private:
    std::shared_ptr<ObjectList> m_objectList{nullptr};
    RCamera m_camera{};

    Scene();

    static std::shared_ptr<Object> getObject(const Json &json);
    static std::shared_ptr<AMaterial> getMaterial(const Json &json);
    static RCamera getCamera(const Json &json);
public:
    static Scene fromFile(const char *filepath);

    [[nodiscard]] const std::shared_ptr<ObjectList> &getObjectList() const noexcept;
    [[nodiscard]] const RCamera &getCamera() const noexcept;
};
