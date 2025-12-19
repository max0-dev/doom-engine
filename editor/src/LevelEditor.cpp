#include<LevelEditor.h>
#include<Windowing/Application.h>
#include<Rendering/VertexArray.h>
#include<extern.h>
#include<std_common.h>


#define VBO_CAPACITY 100 * sizeof(float) * 3


LevelEditor::LevelEditor() : mWindow(Application::sApplication->GetWindow()) {
    mPrimitiveShader = std::make_unique<Shader>("../../res/editor/shaders/EditorPrimitives.vert", "../../res/editor/shaders/EditorPrimitives.frag");

    VertexArrayLayout& layout = mVao.GetLayout();
    layout.PushFloat(3);

    mVbo.BufferData(VBO_CAPACITY, nullptr, GL_DYNAMIC_DRAW);
}

void LevelEditor::OnUpdate(double dt){

}

void LevelEditor::OnRender(){
    mPrimitiveShader->Use();
    mVao.AddBuffer(mVbo);
    glPointSize(5);
    glm::mat4 proj = glm::ortho(0.0f, (float)mWindow.GetSpecs().width, 0.0f, (float)mWindow.GetSpecs().height);
    mPrimitiveShader->SetUniformMat4("proj", proj);
    glDrawArrays(GL_POINTS, 0, mPoints.size());
}

void LevelEditor::OnEvent(Event& event){
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<MouseButtonDown>([this](MouseButtonDown& e){

        double x, y;
        mWindow.GetMousePos(&x, &y);
        spdlog::info("Clicked on x: {0}, y: {1}", x, y);

        y = mWindow.GetSpecs().height - y;
        glm::vec3 p(x, y, 0);
        
        mVbo.BufferSubData(mVbo.GetWriteOffset(), sizeof(float) * 3, glm::value_ptr(p));
        mPoints.push_back(std::move(p));
        return true;
    });
}