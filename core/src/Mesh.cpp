#include<Scene/Mesh.h>

#include<std_common.h>

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices){
    mVbo.BufferData(sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    mIbo.BufferData(sizeof(indices), indices.data(), GL_STATIC_DRAW);
}

void Mesh::Draw(VertexArray& vao){
    vao.AddBuffer(mVbo);
    mIbo.Bind();

    glDrawElements(GL_TRIANGLES, mIbo.GetCount(), GL_UNSIGNED_INT, NULL);
}