#include "tos_window.h"

namespace kidsnow {

TOSWindow::TOSWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

TOSWindow::~TOSWindow() {}

bool TOSWindow::Initialize()
{

	return true;
}

void TOSWindow::Update(Input* input)
{

}

bool TOSWindow::Finalize()
{

	return true;
}

} // end of kidsnow