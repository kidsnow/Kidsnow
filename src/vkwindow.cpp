#include "vkwindow.h"
#include "logger.h"

#include "input.h"

namespace kidsnow {

VKWindow::VKWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

VKWindow::~VKWindow() {}

bool VKWindow::Initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(m_width, m_height, "Vulkan", nullptr, nullptr);

	return true;
}

void VKWindow::Greetings()
{

}

void VKWindow::Update(Input* input)
{
	glfwPollEvents();
}

bool VKWindow::Finalize()
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