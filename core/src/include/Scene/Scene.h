#pragma once
#include<Scene/Camera.h>
#include<Scene/Model.h>
#include<Scene/Light.h>
#include<Rendering/VertexArray.h>
#include<std_common.h>

class Scene{
private:
    Camera* mActiveCamera;
public:
    Scene() : mActiveCamera(nullptr) {}
    void SetActiveCamera(Camera* target) { mActiveCamera = target; }
    inline Camera* GetActiveCamera() { return mActiveCamera; }
    std::vector<Model> mModels;
    Light light;

    void Render(VertexArray& vao){
        for(Model& model : mModels){
            model.Render(vao);
        }
    }
};