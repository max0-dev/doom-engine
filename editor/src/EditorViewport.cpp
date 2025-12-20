#include<EditorViewport.h>
#include<EditorApplication.h>
#include<EditorEvents.h>

#include<Windowing/Application.h>
#include<Rendering/VertexArray.h>
#include<extern.h>

#include<std_common.h>


#define VBO_CAPACITY 100 * sizeof(float) * 3

EditorViewport* EditorViewport::sEditorViewport = nullptr;

EditorViewport::EditorViewport(EditorContext& context) : mWindow(Application::sApplication->GetWindow()), mContext(context) {
    sEditorViewport = this;
    mPrimitiveShader = std::make_unique<Shader>("../../res/editor/shaders/EditorPrimitives.vert", "../../res/editor/shaders/EditorPrimitives.frag");

    VertexArrayLayout& layout = mVao.GetLayout();
    layout.PushFloat(3);

    mVbo.BufferData(VBO_CAPACITY, nullptr, GL_DYNAMIC_DRAW);
    mContext.mFrameBuffer = std::make_unique<FrameBuffer>(mWindow.GetSpecs().width, mWindow.GetSpecs().height);
}

void EditorViewport::OnUpdate(double dt){

}

void EditorViewport::OnRender(){
    mContext.mFrameBuffer->Bind();
    mPrimitiveShader->Use();
    mVao.AddBuffer(mVbo);
    glPointSize(5);
    glm::mat4 proj = glm::ortho(0.0f, (float)mWindow.GetSpecs().width, 0.0f, (float)mWindow.GetSpecs().height);
    mPrimitiveShader->SetUniformMat4("proj", proj);
    glDrawArrays(GL_POINTS, 0, mContext.mPoints.size());
    mContext.mFrameBuffer->Unbind();
}

void EditorViewport::OnEvent(Event& event){
    if(mContext.HasActiveTool()){
        mContext.mActiveTool->OnEvent(event, mContext);
    }
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<OnViewportResize>([this](OnViewportResize& e){
        std::tuple<float, float> d = e.GetDimensions();
        float width = std::get<0>(d);
        float height = std::get<1>(d);
        spdlog::info("Resized viewport to x:{0}, y{1}", width, height);
        mContext.mFrameBuffer->Resize(width, height);
        return true;
    });
    dispatcher.Dispatch<OnViewportMove>([this](OnViewportMove& e){
        glm::vec2 pos = e.GetPosition();

        mContext.mViewportWidth = pos.x;
        mContext.mViewportHeight = pos.y;
        
        return true;
    });
}

void EditorViewport::UpdateVbo(glm::vec3 p){
    mVbo.BufferSubData(mVbo.GetWriteOffset(), sizeof(float) * 3, glm::value_ptr(p));
}