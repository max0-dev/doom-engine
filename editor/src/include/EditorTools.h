#pragma once

#include<IEditorTool.h>
#include<Windowing/Application.h>
#include<EditorContext.h>

#define MOUSE_X_OFF -0.5
#define MOUSE_Y_OFF 20

class VertexTool : public IEditorTool{
public:
    void OnEvent(Event& event, EditorContext& context){
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonDown>([&](MouseButtonDown& e){
            Window& window = Application::sApplication->GetWindow();
            double x, y;
            window.GetMousePos(&x, &y);
            //spdlog::info("Clicked on x: {0}, y: {1}", x, y);

            x = x - context.mViewportWidth + MOUSE_X_OFF;
            y = (window.GetSpecs().height - y) - context.mViewportHeight + MOUSE_Y_OFF;

            //y = window.GetSpecs().height - y;
            glm::vec3 p(x, y, 0);
            
            context.mPoints.push_back(p);
            return true;
        });
    }
    void OnRender(){}
};

class SelectionTool : public IEditorTool{
public:
    void OnEvent(Event& event, EditorContext& context){}
    void OnRender() override{
        
        static ImVec2 startpos(-1, -1);
        static bool first = true;
        
        if(ImGui::IsMouseDown(ImGuiMouseButton_Left) && first){
            startpos = ImGui::GetMousePos();
            first = false;
        }
        
        if(ImGui::IsMouseDragging(ImGuiMouseButton_Left)){
            ImVec2 endpos = ImGui::GetMousePos();

            ImDrawList* draw_list = ImGui::GetForegroundDrawList(); //ImGui::GetWindowDrawList();
            draw_list->AddRect(startpos, endpos, ImGui::GetColorU32(IM_COL32(0, 130, 216, 255)));   // Border
            draw_list->AddRectFilled(startpos, endpos, ImGui::GetColorU32(IM_COL32(0, 130, 216, 50)));    // Background
        }

        if(ImGui::IsMouseReleased(ImGuiMouseButton_Left)){
            startpos.x = -1;
            startpos.y = -1;
            first = true;
        }
    }
};