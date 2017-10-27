#include "Window.h"
#include "log.h"

namespace kidsnow {

    Window::Window(std::string windowName, int width, int height)
    {
        m_windowName = windowName;
        m_width = width;
        m_height = height;
    }

    Window::~Window()
    {

    }

    bool Window::Initialize()
    {
        m_window = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), NULL, NULL);
        if (!m_window)
        {
            LogDebug("Failed to create GLFW window.");
            return false;
        }

        glfwMakeContextCurrent(m_window);

        Greetings();

        return true;
    }

    void Window::Greetings()
    {
        printf (ANSI_COLOR_CYAN);
        printf("******************************************************************\n");
        printf("    OpenGL Framework by Kidsnow\n");
        printf("    OpenGL Version: %s\n", glGetString(GL_VERSION));
        printf("    GLFW Version: %s\n", glfwGetVersionString());
        //printf("    GLEW Version: %s\n", glewGetString(GLEW_VERSION));
        printf("******************************************************************\n");
        printf (ANSI_COLOR_RESET);
    }

    void Window::Update()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

}