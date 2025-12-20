#include<Engine.h>
#include<EditorViewport.h>
#include<EditorOverlay.h>
#include<EditorApplication.h>
#include<EditorContexts.h>
int main(){
    ViewportContext viewportContext;
    EditorApplication editor({900, 900, "Editor", false});
    editor.PushLayer<EditorViewport>(viewportContext);
    editor.PushLayer<EditorOverlay>(viewportContext);
    editor.Run();
}