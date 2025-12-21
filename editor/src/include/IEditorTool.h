#pragma once
#include<Event.h>

class EditorContext;

class IEditorTool{
public:
    virtual ~IEditorTool() = default;
    virtual void OnEvent(Event& event, EditorContext& context) {}
    virtual void OnRender(EditorContext& context) {}
};