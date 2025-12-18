#pragma once

#include<Rendering/VertexBuffer.h>
#include<Rendering/IndexBuffer.h>
#include<Rendering/VertexArray.h>

class Mesh{
private:
    VertexBuffer mVbo;
    IndexBuffer mIbo;
public:
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
    void Draw(VertexArray& vao);
};