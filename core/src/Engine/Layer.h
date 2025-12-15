#pragma once
#include<Engine/Event.h>

class Layer{
public:
    virtual void OnUpdate(double dt) {};
    virtual void OnRender() {};
    virtual void OnEvent(Event& event) {};
};