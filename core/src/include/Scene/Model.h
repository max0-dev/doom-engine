#pragma once

#include<std_common.h>
#include<Scene/Mesh.h>
#include<Rendering/VertexArray.h>

class Model{
private:
    std::vector<Mesh> mMeshes;
    void processNode(aiNode* node, const aiScene* scene);
public:
    Model(const std::string& filepath);
    void Render(VertexArray& vao);
};