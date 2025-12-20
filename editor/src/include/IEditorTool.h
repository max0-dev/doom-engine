#pragma once
#include<Event.h>

class IEditorTool{
public:
    virtual void OnEvent(Event& event, ViewportContext& context) = 0;
};