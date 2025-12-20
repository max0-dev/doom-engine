#pragma once
#include<extern.h>
#include<string>
#include<functional>
#include<sstream>


class Event{
protected:
    bool mHandled = false;
public:
    inline bool& IsHandled() { return mHandled; }
    virtual ~Event() = default;
};

class EventDispatcher{
private:
    Event& mEvent;
public:
    EventDispatcher(Event& event) : mEvent(event) {}
    template<typename T>
    requires(std::is_base_of_v<Event, T>)
    void Dispatch(std::function<bool(T&)> func){
        auto* derived_e = dynamic_cast<T*>(&mEvent);
        if(derived_e != nullptr && !mEvent.IsHandled()){
            bool& handled = mEvent.IsHandled();
            handled = func(*derived_e);
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
};