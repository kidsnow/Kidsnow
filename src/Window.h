#pragma once

#ifdef WINDOWS
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <string>

namespace kidsnow {

class Window {
public:
    Window(std::string windowName, int width, int height);
    ~Window();

public:
    bool Initialize();
    void Update();
    inline bool Finalize() { return glfwWindowShouldClose(m_window); }

public:
    bool isKeyPressed(unsigned int keycode) const;
    bool isMouseBtnPressed(unsigned int button) const;
    void getMousePosition(double& x, double& y) const;

private:
    void Greetings();

private:
    GLFWwindow* m_window;
    std::string m_windowName;
    int m_width;
    int m_height;
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

} // end of kidsnoaw
