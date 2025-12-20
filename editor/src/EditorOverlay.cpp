#include<EditorOverlay.h>
#include<EditorApplication.h>
#include<EditorViewport.h>
#include<EditorTools.h>
#include<EditorEvents.h>

EditorOverlay::EditorOverlay(EditorContext& context) : Overlay(), mContext(context) {

}

void EditorOverlay::OnUpdate(double dt) {
}

void EditorOverlay::OnRender(){
    Begin();

    ImGui::Begin("Map Editor");
    
    if(ImGui::TreeNode("Points:")){
        for(int i = 0; i < mContext.mPoints.size(); i++){
            const glm::vec3& p = mContext.mPoints[i];
            ImGui::Text("p%d: x:%f, y:%f", i, p.x, p.y);
        }
        ImGui::TreePop();
    }

    ImGui::End();

    static float lastw = ImGui::GetContentRegionAvail().x;
    static float lasth = ImGui::GetContentRegionAvail().y;

    static float lastx = ImGui::GetCursorScreenPos().x;
    static float lasty = ImGui::GetCursorScreenPos().y;

    ImGui::Begin("Viewport");

    float x = ImGui::GetCursorScreenPos().x;
    float y = ImGui::GetCursorScreenPos().y;

    if(x != lastx || y != lasty){
        OnViewportMove event(x, y);
        Application::sApplication->Raise(event);
    }

    float width = ImGui::GetContentRegionAvail().x;
    float height = ImGui::GetContentRegionAvail().y;

    if(width != lastw || height != lasth){
        OnViewportResize event(width, height);
        Application::sApplication->Raise(event);
    }

    lastw = width;
    lasth = height;

    unsigned int fbo = mContext.mFrameBuffer->GetTexture();
    ImGui::Image((ImTextureID)fbo, ImGui::GetContentRegionAvail(), ImVec2(0,1), ImVec2(1,0));

    

    if(mContext.HasActiveTool()){
        mContext.mActiveTool->OnRender();
    }

    ImGui::End();

    End();
}

void EditorOverlay::OnEvent(Event& event){
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<KeyDown>([this](KeyDown& e){ 

        if(e.GetKey() == GLFW_KEY_1){
            mContext.SetActiveTool<VertexTool>();
        }else if(e.GetKey() == GLFW_KEY_2){
            mContext.SetActiveTool<SelectionTool>();
        } 
        else if(e.GetKey() == GLFW_KEY_ESCAPE){
            mContext.UnselectTool();
        }

        return true;
    });
}