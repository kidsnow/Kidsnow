#include "rendererfactory.h"
#include "glrenderer.h"
#include "logger.h"

namespace kidsnow {

Renderer* RendererFactory::GetRenderer(SupportedAPI graphicsAPI)
{
	if (graphicsAPI == SupportedAPI::KIDSNOW_OPENGL)
		return new GLRenderer();
	else if (graphicsAPI == SupportedAPI::KIDSNOW_OPENGL)
		return nullptr;
	
	LogDebug("This API is not supported.");
	return nullptr;
}

}