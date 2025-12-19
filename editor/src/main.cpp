#include<Engine.h>
#include<LevelEditor.h>
int main(){
    Application editor_app({900, 900, "Editor", false});
    editor_app.PushLayer<LevelEditor>();
    editor_app.Run();
}