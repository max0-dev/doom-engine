#pragma once

#include<Windowing/Application.h>
#include<extern.h>

#include<IEditorTool.h>

class EditorApplication : public Application{
private:
    std::vector<glm::vec3> mPoints;
    std::unique_ptr<IEditorTool> mActiveTool = nullptr;
public:
    EditorApplication(WindowSpecs specs);
    // temp
    static EditorApplication* sEditorApplication;
    inline const std::vector<glm::vec3>& GetPoints() const { return mPoints; }
    void AddPoint(glm::vec3 p);
    template<typename T>
    requires(std::is_base_of_v<IEditorTool, T>)
    void SetActiveTool(){
        mActiveTool = std::make_unique<T>();
    }
    inline bool HasToolSelected() const { return mActiveTool ? true : false; }
    inline std::unique_ptr<IEditorTool>& GetActiveTool() { return mActiveTool; }
    void UnselectTool(){
        mActiveTool.~unique_ptr();
        mActiveTool = nullptr;
    }
};