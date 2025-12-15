#pragma once
#include<Engine/Layer.h>
#include<Engine/VertexBuffer.h>
#include<Engine/VertexArray.h>
#include<Engine/Shader.h>
#include<Engine/Event.h>
#include<memory>

class DemoLayer : public Layer{
private:
    VertexBuffer vbo;
    VertexArray vao;
    std::unique_ptr<Shader> shader;
public:
    DemoLayer();
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event) override;
};