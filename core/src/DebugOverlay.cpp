#include<DebugOverlay.h>
#include<extern.h>
#include<Event.h>
#include<Scene/Scene.h>
#include<Rendering/Renderer.h>
#include<Scene/Camera.h>

void DebugOverlay::OnRender(){
    Begin("Debug");

    ImGui::BeginChild("Performance", ImVec2(400, 50));
    
    ImGui::Text("Performance");

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::Text("Frame Time: %.2f ms", 1000.0f / ImGui::GetIO().Framerate);

    ImGui::EndChild();
    Scene* scene = Renderer::Instance()->GetActiveScene();
    if(scene){
        Camera* camera = scene->GetActiveCamera();
        if(camera){
            ImGui::Separator();
            ImGui::BeginChild("Camera", ImVec2(400, 50));
            ImGui::Text("Camera");
            glm::vec3 campos = camera->GetCameraTransform().position;
            ImGui::Text("<Position> x:%f, y:%f, z:%f", campos.x, campos.y, campos.z);
            ImGui::EndChild();
        }
    }
    
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