#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace Kidsnow {

/*
 * I wanna hide any GLFW-dependent logic into class Window.
 */
class Window {
public:
    Window(std::string windowName);
    ~Window();

public:
    void Initialize();
    inline bool Closed() { return glfwWindowShouldClose(m_window); }
    inline bool m_window->Update();


private:
    GLFWwindow* m_window;
    std::string m_windowName;
};

}
