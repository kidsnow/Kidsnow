#include "windowfactory.h"
#include "glwindow.h"
#include "kidsnow.h"
#include "utilities.h"

namespace kidsnow {

Window* WindowFactory::GetWindow(std::string windowName, int posX, int posY, int width, int height, SupportedAPI graphicsAPI)
{
	if (graphicsAPI == SupportedAPI::OPENGL)
		return new GLWindow(windowName, posX, posY, width, height);
	/*else if (graphicsAPI == SupportedAPI::VULKAN)
		return new VKWindow(windowName, posX, posY, width, height);*/
	
	LogDebug("This API is not supported.");
	return nullptr;
}

}