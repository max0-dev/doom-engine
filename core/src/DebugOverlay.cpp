#include<Engine/DebugOverlay.h>
#include<Engine/extern.h>
#include<Engine/Event.h>

void DebugOverlay::OnRender(){
    Begin("Performance");

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::Text("Frame Time: %.2f ms", 1000.0f / ImGui::GetIO().Framerate);

    End();
}

void DebugOverlay::OnUpdate(double dt){

}

void DebugOverlay::OnEvent(Event& event){
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<KeyDown>([this](KeyDown& e){
        
        if(e.GetKey() == GLFW_KEY_T){
            mActive = !mActive;
            return true;
        }
        return false;
    });
}