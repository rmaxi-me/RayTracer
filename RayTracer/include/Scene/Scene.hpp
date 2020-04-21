/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <json.hpp>

#include "Objects/ObjectList.hpp"

using Json = nlohmann::json;

class Scene {
private:
    std::shared_ptr<ObjectList> m_objectList{nullptr};

    Scene();

    static std::shared_ptr<Object> getObject(const Json &json);
    static std::shared_ptr<AMaterial> getMaterial(const Json &json);
public:
    static Scene fromFile(const char *filepath);

    [[nodiscard]] const std::shared_ptr<ObjectList> &getObjectList() const noexcept;
};
