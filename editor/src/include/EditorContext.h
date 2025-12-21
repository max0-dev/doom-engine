#pragma once

#include<Rendering/FrameBuffer.h>
#include<std_common.h>
#include<Windowing/Application.h>
#include<IEditorTool.h>
#include<MapPrimitives.h>

struct EditorContext{
    std::vector<Point> mPoints;
    std::vector<glm::vec3> mSelectedPoints;
    std::unique_ptr<IEditorTool> mActiveTool = nullptr;
    std::unique_ptr<FrameBuffer> mFrameBuffer;
    float mViewportWidth;
    float mViewportHeight;

    template<typename T>
    requires(std::is_base_of_v<IEditorTool, T>)
    void SetActiveTool(){
        mActiveTool = std::make_unique<T>();
    }
    void UnselectTool(){
        mActiveTool.~unique_ptr();
        mActiveTool = nullptr;
    }
    bool HasActiveTool(){
        return mActiveTool ? true : false;
    }
};