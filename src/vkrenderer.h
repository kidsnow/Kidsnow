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