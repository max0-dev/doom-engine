#pragma once

class Layer{
public:
    Layer();
    virtual void OnUpdate(double dt) = 0;
    virtual void OnRender() = 0;
};