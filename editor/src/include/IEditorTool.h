#pragma once
#include<Event.h>
#include<EditorContext.h>
#include<Windowing/Application.h>

class IEditorTool{
public:
    virtual void OnEvent(Event& event, EditorContext& context) {}
    virtual void OnRender() {}
};