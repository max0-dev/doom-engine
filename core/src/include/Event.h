#pragma once
#include<extern.h>
#include<string>
#include<functional>
#include<sstream>

#define EVENT_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                         virtual EventType GetEventType() const override { return GetStaticType(); }


enum class EventType{
    None,
    MouseButtonDown,MouseButtonUp,MouseButtonHold,
    KeyDown,KeyUp,KeyRepeat,
    WindowResize
};

class Event{
protected:
    bool mHandled = false;
public:
    inline bool& IsHandled() { return mHandled; }
    virtual EventType GetEventType() const = 0;
};

class EventDispatcher{
private:
    Event& mEvent;
public:
    EventDispatcher(Event& event) : mEvent(event) {}
    template<typename T>
    void Dispatch(std::function<bool(T&)> func){
        if(mEvent.GetEventType() == T::GetStaticType() && !mEvent.IsHandled() ){
            bool& handled = mEvent.IsHandled();
            handled = func(*((T*)&mEvent));
        }
    }
};

class MouseButtonDown : public Event{
private:
    GLenum mButton;
public:
    MouseButtonDown(GLenum button) : mButton(button) {}
    std::string ToString(){
        return "Mouse Button Pressed";
    }
    inline GLenum GetMouseButton() const { return mButton; }
    EVENT_TYPE(MouseButtonDown)
};

class MouseButtonUp : public Event{
private:
    GLenum mButton;
public:
    MouseButtonUp(GLenum button) : mButton(button) {}
    std::string ToString(){
        return "Mouse Button Released";
    }
    inline GLenum GetMouseButton() const { return mButton; }
    EVENT_TYPE(MouseButtonUp)
};

class KeyDown : public Event{
private:
    int mKey;
public:
    KeyDown(int key) : mKey(key) {}
    std::string ToString(){
        return "Key Pressed";
    }
    inline GLenum GetKey() const { return mKey; }
    EVENT_TYPE(KeyDown)
};

class KeyUp : public Event{
private:
    int mKey;
public:
    KeyUp(int key) : mKey(key) {}
    std::string ToString(){
        return "Key Released";
    }
    inline GLenum GetKey() const { return mKey; }
    EVENT_TYPE(KeyUp)
};

class KeyRepeat : public Event{
private:
    int mKey;
public:
    KeyRepeat(int key) : mKey(key) {}
    std::string ToString(){
        return "Key is being held";
    }
    inline GLenum GetKey() const { return mKey; }
    EVENT_TYPE(KeyRepeat)
};

class WindowResize : public Event{
private:
    int mWidth;
    int mHeight;
public:
    WindowResize(int width, int height): mWidth(width), mHeight(height) {}
    std::string ToString(){
        std::stringstream ss;
        ss << "Window resized to " << mWidth << " x " << mHeight;
        return ss.str();
    }
    inline std::tuple<int, int> GetDimensions() const {return std::tuple<int, int>(mWidth, mHeight);}
    EVENT_TYPE(WindowResize)
};