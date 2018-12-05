#include "glwindow.h"
#include "logger.h"

#include "input.h"

namespace kidsnow {

GLWindow::GLWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

GLWindow::~GLWindow() {}


bool GLWindow::Initialize()
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

void GLWindow::Greetings()
{
	std::cout << "******************************************************************\n";
	std::cout << "    OpenGL Framework by Kidsnow\n";
	std::cout << "    OpenGL Version: " << glGetString(GL_VERSION) << "\n";
	std::cout << "    GLFW Version: " << glfwGetVersionString() << "\n";
	std::cout << "******************************************************************\n";
}

void GLWindow::Update(Input* input)
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool GLWindow::Finalize()
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