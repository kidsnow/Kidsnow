#include "Window.h"

namespace kidsnow {

Window::Window(std::string windowName)
{
    m_windowName = windowName;
}

Window::~Window()
{

}
    
int Window::Initialize()
{
    if (!glfwInit)
        return -1;

    window = glfwCreateWindow(640, 480, m_windowName, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0, 1.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;

}

}
