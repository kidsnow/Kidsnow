#include "windowfactory.h"
#include "glwindow.h"
#include "vkwindow.h"
#include "kidsnow.h"
#include "logger.h"

namespace kidsnow {

Window* WindowFactory::GetWindow(std::string windowName, int width, int height, SupportedAPI graphicsAPI)
{
	if (graphicsAPI == SupportedAPI::KIDSNOW_OPENGL)
		return new GLWindow(windowName, width, height);
	else if (graphicsAPI == SupportedAPI::KIDSNOW_VULKAN)
		return new VKWindow(windowName, width, height);
	
	LogDebug("This API is not supported.");
	return nullptr;
}

}