#pragma once
#include<Scene/Camera.h>

class Scene{
private:
    Camera* mActiveCamera;
public:
    Scene() : mActiveCamera(nullptr) {}
    void SetActiveCamera(Camera* target) { mActiveCamera = target; }
    inline Camera* GetActiveCamera() { return mActiveCamera; }
};