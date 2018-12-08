#pragma once

#include "renderer.h"
#include "vkcommon.h"

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
	VkInstance m_instance;

private:
	bool checkValidationLayerSupport();
	bool createInstance();
	bool setupDebugCallback();
	bool createSurface();
	bool pickPhysicalDevice();
	bool createLogicalDevice();
	bool createSwapChain();
	bool createImageViews();
	bool createRenderPass();
	bool createGraphicsPipeline();
	bool createFramebuffers();
	bool createCommandPool();
	bool createCommandBuffers();
	bool createSyncObjects();
};

}