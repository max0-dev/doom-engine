#include<EditorApplication.h>
#include<EditorViewport.h>

EditorApplication* EditorApplication::sEditorApplication = nullptr;

EditorApplication::EditorApplication(WindowSpecs specs) : Application(specs), mActiveTool(nullptr){
    sEditorApplication = this;
}

void EditorApplication::AddPoint(glm::vec3 p){
    mPoints.push_back(p);
    EditorViewport::sEditorViewport->UpdateVbo(p);
}