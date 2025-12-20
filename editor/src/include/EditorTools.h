#pragma once

#include<IEditorTool.h>

class VertexTool : public IEditorTool{
public:
    void OnEvent(Event& event) override{
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonDown>([this](MouseButtonDown& e){
            Window& window = EditorApplication::sEditorApplication->GetWindow();
            double x, y;
            window.GetMousePos(&x, &y);
            spdlog::info("Clicked on x: {0}, y: {1}", x, y);

            y = window.GetSpecs().height - y;
            glm::vec3 p(x, y, 0);
            
            EditorApplication::sEditorApplication->AddPoint(p);
            return true;
        });
    }
};