#pragma once
#include<Engine.h>
#include<memory>

class DemoLayer : public Layer{
private:
    VertexBuffer vbo;
    VertexArray vao;
    IndexBuffer ibo;

    std::unique_ptr<Texture> sample;

    FreeLookCamera camera;

    std::unique_ptr<Shader> shader;
public:
    DemoLayer();
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event) override;
};