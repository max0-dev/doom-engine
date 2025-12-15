#pragma once
#include<Engine/Layer.h>
#include<Engine/Event.h>

class Overlay : public Layer{
public:
    Overlay();
    ~Overlay();
    virtual void OnUpdate(double dt) {}
    virtual void OnRender() {}
    virtual void OnEvent(Event& event) {}

    void Begin(const char* title);
    void End();
};