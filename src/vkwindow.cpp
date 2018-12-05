#include "vkwindow.h"
#include "logger.h"

#include "input.h"

namespace kidsnow {

VKWindow::VKWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

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

	return true;
}

} // end of kidsnow