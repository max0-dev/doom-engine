#pragma once

#include<Windowing/Application.h>
#include<extern.h>
#include<Rendering/FrameBuffer.h>
#include<EditorContext.h>

#include<IEditorTool.h>


class EditorApplication : public Application{
public:
    EditorApplication(WindowSpecs specs);
    // temp
    static EditorApplication* sEditorApplication;
};