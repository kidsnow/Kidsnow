#pragma once

#include "Window.h"
#include "Renderer.h"

namespace kidsnow {

class Application {
public:
    Application();
    ~Application();
public:
    void Initialize();
private:
    Window* m_window;
    Renderer* m_renderer;
};

}
