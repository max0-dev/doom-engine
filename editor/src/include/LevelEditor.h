#pragma once

#include<Windowing/Layer.h>
#include<Windowing/Window.h>

#include<extern.h>
#include<Rendering/Rendering_m.h>

class LevelEditor : public Layer{
private:
    std::vector<glm::vec2> mPoints;
    glm::mat4 projection;
    std::unique_ptr<Shader> mPrimitiveShader;
    VertexBuffer mVbo;
    VertexArray mVao;
    Window& mWindow;
public:
    LevelEditor();
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event);
};