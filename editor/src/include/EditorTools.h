#pragma once

#include<IEditorTool.h>

#define MOUSE_X_OFF -0.5
#define MOUSE_Y_OFF 20

class VertexTool : public IEditorTool{
public:
    void OnEvent(Event& event, ViewportContext& context) override{
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonDown>([&](MouseButtonDown& e){
            Window& window = EditorApplication::sEditorApplication->GetWindow();
            double x, y;
            window.GetMousePos(&x, &y);
            spdlog::info("Clicked on x: {0}, y: {1}", x, y);

            x = x - context.mViewportWidth + MOUSE_X_OFF;
            y = (window.GetSpecs().height - y) - context.mViewportHeight + MOUSE_Y_OFF;

            //y = window.GetSpecs().height - y;
            glm::vec3 p(x, y, 0);
            
            EditorApplication::sEditorApplication->AddPoint(p);
            return true;
        });
    }
};