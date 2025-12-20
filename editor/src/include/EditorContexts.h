#pragma once

#include<Rendering/FrameBuffer.h>
#include<std_common.h>

struct ViewportContext{
    std::unique_ptr<FrameBuffer> mFrameBuffer;
    float mViewportWidth;
    float mViewportHeight;
    
};