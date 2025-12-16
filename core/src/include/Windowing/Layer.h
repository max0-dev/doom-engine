#pragma once
#include<Event.h>

class Layer{
protected:
    bool mActive = true;
public:
    virtual void OnUpdate(double dt) {};
    virtual void OnRender() {};
    virtual void OnEvent(Event& event) {};
    inline bool IsActive() const { return mActive; }
};