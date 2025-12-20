#pragma once
#include<Windowing/Layer.h>
#include<Event.h>

class Overlay : public Layer{
public:
    Overlay();
    ~Overlay();
    virtual void OnUpdate(double dt) {}
    virtual void OnRender() {}
    virtual void OnEvent(Event& event) {}

    void Begin();
    void End();
};