#include<Engine.h>
#include<EditorViewport.h>
#include<EditorOverlay.h>
#include<EditorApplication.h>

int main(){
    EditorApplication editor({900, 900, "Editor", false});
    editor.PushLayer<EditorViewport>();
    editor.PushLayer<EditorOverlay>();
    editor.Run();
}