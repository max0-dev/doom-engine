#include<EditorOverlay.h>
#include<EditorApplication.h>

#include<EditorTools.h>

EditorOverlay::EditorOverlay() : Overlay(){

}

void EditorOverlay::OnUpdate(double dt) {

    const auto& points = EditorApplication::sEditorApplication->GetPoints();

    Begin("Map Info");
    
    if(ImGui::TreeNode("Points:")){
        for(int i = 0; i < points.size(); i++){
            const glm::vec3& p = points[i];
            ImGui::Text("p%d: x:%f, y:%f", i, p.x, p.y);
        }
        ImGui::TreePop();
    }

    End();
}

void EditorOverlay::OnRender(){

}

void EditorOverlay::OnEvent(Event& event){
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<KeyDown>([this](KeyDown& e){ 

        if(e.GetKey() == GLFW_KEY_1){
            EditorApplication::sEditorApplication->SetActiveTool<VertexTool>();
        } else if(e.GetKey() == GLFW_KEY_ESCAPE){
            EditorApplication::sEditorApplication->UnselectTool();
        }

        return true;
    });
}