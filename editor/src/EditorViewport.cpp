#include<EditorViewport.h>
#include<EditorApplication.h>

#include<Windowing/Application.h>
#include<Rendering/VertexArray.h>
#include<extern.h>

#include<std_common.h>


#define VBO_CAPACITY 100 * sizeof(float) * 3

EditorViewport* EditorViewport::sEditorViewport = nullptr;

EditorViewport::EditorViewport() : mWindow(Application::sApplication->GetWindow()) {
    sEditorViewport = this;
    mPrimitiveShader = std::make_unique<Shader>("../../res/editor/shaders/EditorPrimitives.vert", "../../res/editor/shaders/EditorPrimitives.frag");

    VertexArrayLayout& layout = mVao.GetLayout();
    layout.PushFloat(3);

    mVbo.BufferData(VBO_CAPACITY, nullptr, GL_DYNAMIC_DRAW);
}

void EditorViewport::OnUpdate(double dt){

}

void EditorViewport::OnRender(){
    mPrimitiveShader->Use();
    mVao.AddBuffer(mVbo);
    glPointSize(5);
    glm::mat4 proj = glm::ortho(0.0f, (float)mWindow.GetSpecs().width, 0.0f, (float)mWindow.GetSpecs().height);
    mPrimitiveShader->SetUniformMat4("proj", proj);
    glDrawArrays(GL_POINTS, 0, EditorApplication::sEditorApplication->GetPoints().size());
}

void EditorViewport::OnEvent(Event& event){
    if(EditorApplication::sEditorApplication->HasToolSelected()){
        EditorApplication::sEditorApplication->GetActiveTool()->OnEvent(event);
    }
}

void EditorViewport::UpdateVbo(glm::vec3 p){
    mVbo.BufferSubData(mVbo.GetWriteOffset(), sizeof(float) * 3, glm::value_ptr(p));
}