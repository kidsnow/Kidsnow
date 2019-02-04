#include "vkwindow.h"
#include "logger.h"

#include "input.h"

namespace kidsnow {

VKWindow::VKWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

VKWindow::~VKWindow() {}

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	// Set m_framebufferResized to true in VKRenderer.
}

bool VKWindow::Initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	m_window = glfwCreateWindow(m_width, m_height, "Vulkan", nullptr, nullptr);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);

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