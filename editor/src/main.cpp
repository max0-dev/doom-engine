#include<Engine.h>
#include<EditorViewport.h>
#include<EditorOverlay.h>
#include<EditorApplication.h>
#include<EditorContext.h>
int main(){
    EditorContext context;
    Application editor({900, 900, "Editor", false});
    editor.PushLayer<EditorViewport>(context);
    editor.PushLayer<EditorOverlay>(context);
    editor.Run();
}