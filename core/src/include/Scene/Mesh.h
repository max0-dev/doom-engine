#pragma once

#include<Rendering/Rendering_m.h>

class Mesh{
private:
    VertexBuffer mVbo;
    IndexBuffer mIbo;
public:
    Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);
    void Draw(VertexArray& vao);
};