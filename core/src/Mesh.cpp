#include<Scene/Mesh.h>
#include<Rendering/VertexArray.h>
#include<std_common.h>
#include<extern.h>

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) {
    mVbo.BufferData(vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    mIbo.BufferData(indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW, indices.size());
}

void Mesh::Draw(VertexArray& vao){
    vao.AddBuffer(mVbo);
    mIbo.Bind();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glDrawElements(GL_TRIANGLES, mIbo.GetCount(), GL_UNSIGNED_INT, NULL);
}