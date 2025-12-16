#include<Windowing/Overlay.h>
#include<Windowing/Application.h>
#include<extern.h>

Overlay::Overlay(){
    Window& window = Application::sApplication->GetWindow();
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window.GetRawPtr(), true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

Overlay::~Overlay(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Overlay::Begin(const char* title){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin(title);
}

void Overlay::End(){
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}