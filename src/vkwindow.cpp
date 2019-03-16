#include "vkwindow.h"
#include "vkrenderer.h"
#include "input.h"
#include "logger.h"


namespace kidsnow {

VKWindow::VKWindow(std::string windowName, int posX, int posY, int width, int height)
	: Window(SDL_WINDOW_VULKAN, windowName, posX, posY, width, height) {}

VKWindow::~VKWindow() {}

bool VKWindow::Initialize()
{

	return true;
}

void VKWindow::Greetings()
{

}

void VKWindow::Update(Input* input)
{
}

bool VKWindow::Finalize()
{

	return false;
}

Renderer* VKWindow::GenerateRenderer()
{
	VKRenderer* renderer = new VKRenderer(m_window);

	if (renderer->Initialize())
		return renderer;

	return nullptr;
}

} // end of kidsnow