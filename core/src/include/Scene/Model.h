#pragma once

#include<std_common.h>
#include<Scene/Mesh.h>

class Model{
private:
    std::vector<Mesh> mMeshes;
public:
    Model(const std::string& filepath);
};