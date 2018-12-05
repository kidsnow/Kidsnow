#include "rendererfactory.h"
#include "glrenderer.h"
#include "vkrenderer.h"
#include "kidsnow.h"
#include "logger.h"

namespace kidsnow {

Renderer* RendererFactory::GetRenderer(SupportedAPI graphicsAPI)
{
	if (graphicsAPI == SupportedAPI::KIDSNOW_OPENGL)
		return new GLRenderer();
	else if (graphicsAPI == SupportedAPI::KIDSNOW_VULKAN)
		return new VKRenderer();
	
	LogDebug("This API is not supported.");
	return nullptr;
}

}