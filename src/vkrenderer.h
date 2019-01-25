#pragma once

#include "renderer.h"
#include "vkcommon.h"

#include <vector>

namespace kidsnow {

class VKRenderer : public Renderer
{
public:
	VKRenderer();
	~VKRenderer();

public:
	virtual bool Initialize(int width, int height);
	virtual void Render(Input* input);

private:
	const std::vector<const char*> m_validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};
	const bool m_enableValidationLayers = true;
	VkInstance m_instance;

private:
	bool CheckValidationLayerSupport();
	bool CreateInstance();
	bool SetupDebugCallback();
	bool CreateSurface();
	bool PickPhysicalDevice();
	bool CreateLogicalDevice();
	bool CreateSwapChain();
	bool CreateImageViews();
	bool CreateRenderPass();
	bool CreateGraphicsPipeline();
	bool CreateFramebuffers();
	bool CreateCommandPool();
	bool CreateCommandBuffers();
	bool CreateSyncObjects();
};

}