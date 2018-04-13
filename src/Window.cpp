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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
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
    std::cout << ANSI_COLOR_CYAN;
    std::cout << "******************************************************************\n";
    std::cout << "    OpenGL Framework by Kidsnow\n";
    std::cout << "    OpenGL Version: %s\n", glGetString(GL_VERSION);
    std::cout << "    GLFW Version: %s\n", glfwGetVersionString();
    //printf("    GLEW Version: %s\n", glewGetString(GLEW_VERSION));
    std::cout << "******************************************************************\n";
    std::cout << ANSI_COLOR_RESET;
}

void Window::Update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

} // end of kidsnow
