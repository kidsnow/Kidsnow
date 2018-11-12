#include "window.h"
#include "logger.h"

#include "input.h"

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
	if (!glfwInit())
	{
		LogDebug("GLFW initialize failed!");
		return false;
	}

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    m_window = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), NULL, NULL);
    if (!m_window)
    {
        LogDebug("Failed to create GLFW window.");
		glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);

    Greetings();

    return true;
}

void Window::Greetings()
{
#ifndef _WIN32
    std::cout << ANSI_COLOR_CYAN;
#endif
    std::cout << "******************************************************************\n";
    std::cout << "    OpenGL Framework by Kidsnow\n";
    std::cout << "    OpenGL Version: " << glGetString(GL_VERSION) << "\n";
    std::cout << "    GLFW Version: " << glfwGetVersionString() << "\n";
    std::cout << "******************************************************************\n";
#ifndef _WIN32
    std::cout << ANSI_COLOR_RESET;
#endif
}

void Window::Update(Input* input)
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

bool Window::Finalize()
{
	if (glfwWindowShouldClose(m_window))
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return true;
	}

	return false;
}

} // end of kidsnow
