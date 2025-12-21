#pragma once

#include<IEditorTool.h>
#include<Windowing/Application.h>
#include<EditorContext.h>
#include<EditorEvents.h>

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
            
            x = x - context.mViewportWidth + MOUSE_X_OFF;
            y = (window.GetSpecs().height - y) - context.mViewportHeight + MOUSE_Y_OFF;
            spdlog::info("Clicked on x: {0}, y: {1}", x, y);
            
            //y = window.GetSpecs().height - y;
            glm::vec3 p(x, y, 0);
            
            OnPointAdded event(p);
            Application::sApplication->Raise(event);
            return true;
        });
    }
    void OnRender(EditorContext& context){}
};

class SelectionTool : public IEditorTool{
public:
    void OnEvent(Event& event, EditorContext& context){}
    void OnRender(EditorContext& context) override{
        Window& window = Application::sApplication->GetWindow();
        
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

            float startx = startpos.x - context.mViewportWidth + MOUSE_X_OFF;
            float starty = (window.GetSpecs().height - startpos.y) - context.mViewportHeight + MOUSE_Y_OFF;

            float endx = endpos.x - context.mViewportWidth + MOUSE_X_OFF;
            float endy = (window.GetSpecs().height - endpos.y) - context.mViewportHeight + MOUSE_Y_OFF;

            float minx = std::min(startx, endx);
            float maxx = std::max(startx, endx);
            float miny = std::min(starty, endy);
            float maxy = std::max(starty, endy);
            
            //spdlog::info("startpos: x{0}, y{1}", startx, starty);
            //spdlog::info("endpos: x{0}, y{1}", endpos.x, endpos.y);

            for(auto& p : context.mPoints){
                if(p.position.x >= minx && p.position.x <= maxx && p.position.y >= miny && p.position.y <= maxy){
                   if(p.selected != 1){
                        p.selected = 1;
                        OnSelected event;
                        Application::sApplication->Raise(event);
                   }
                }else{
                    if(p.selected != 0){
                        p.selected = 0;
                        OnSelected event;
                        Application::sApplication->Raise(event);
                    }
                }
            }
        }

        if(ImGui::IsMouseReleased(ImGuiMouseButton_Left)){
            startpos.x = -1;
            startpos.y = -1;
            first = true;
        }
    }
};