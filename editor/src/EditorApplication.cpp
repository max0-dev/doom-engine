#include<EditorApplication.h>
#include<EditorViewport.h>

EditorApplication* EditorApplication::sEditorApplication = nullptr;

EditorApplication::EditorApplication(WindowSpecs specs) : Application(specs){
    sEditorApplication = this;
}