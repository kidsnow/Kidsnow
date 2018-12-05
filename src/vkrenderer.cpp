#include "vkrenderer.h"
#include "vkcommon.h"

#include "logger.h"

namespace kidsnow {

bool VKRenderer::Initialize(int width, int height)
{
	if (!glfwVulkanSupported())
	{
		LogDebug("Vulkan is not supported.");
		return false;
	}

	PFN_vkCreateInstance pfnCreateInstance = (PFN_vkCreateInstance)
		glfwGetInstanceProcAddress(NULL, "vkCreateInstance");

	return true;
}

void VKRenderer::Render(Input* input)
{
	
}

}