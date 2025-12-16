#pragma once

#include<Scene/Scene.h>

class Renderer{
private:
    Scene* mActiveScene;
    static Renderer* sInstance;

    Renderer() : mActiveScene(nullptr) {}
public:
    static Renderer* Instance();

    void SetActiveScene(Scene* target){
        mActiveScene = target;
    }
    inline Scene* GetActiveScene() { return mActiveScene; }
};