#pragma once

#include <string>
/* Renderer.h includes glew on Windows platform and glew must be included before glfw. */
/* Windows.h may include glfw so Renderer.h must be included before Window.h. */
#include "Renderer.h"
#include "Window.h"

namespace kidsnow {

class Application {
public:
    Application(std::string appName, int width, int height);
    ~Application();

public:
    bool Initialize();
    void Run();

private:
    std::string m_appName;
    Window* m_window;
    Renderer* m_renderer;
};

} // end of kidsnow
