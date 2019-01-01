#include "vkrenderer.h"
#include <vector>

#include "logger.h"

namespace kidsnow {

VKRenderer::VKRenderer() {};

VKRenderer::~VKRenderer()
{
	//vkDestroyInstance(m_instance, nullptr);
};

bool VKRenderer::CheckValidationLayerSupport()
{
	return true;
}

bool VKRenderer::CreateInstance()
{
/*
    VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS) {
		return false;
	}
*/
	return true;
}
bool VKRenderer::SetupDebugCallback() {
	return true;
}
bool VKRenderer::CreateSurface() {
	return true;
}
bool VKRenderer::PickPhysicalDevice() {
	return true;
}
bool VKRenderer::CreateLogicalDevice() {
	return true;
}
bool VKRenderer::CreateSwapChain() {
	return true;
}
bool VKRenderer::CreateImageViews() {
	return true;
}
bool VKRenderer::CreateRenderPass() {
	return true;
}
bool VKRenderer::CreateGraphicsPipeline() {
	return true;
}
bool VKRenderer::CreateFramebuffers() {
	return true;
}
bool VKRenderer::CreateCommandPool() {
	return true;
}
bool VKRenderer::CreateCommandBuffers() {
	return true;
}
bool VKRenderer::CreateSyncObjects() {
	return true;
}

bool VKRenderer::Initialize(int width, int height)
{
	CreateInstance();
	SetupDebugCallback();
	CreateSurface();
	PickPhysicalDevice();
	CreateLogicalDevice();
	CreateSwapChain();
	CreateImageViews();
	CreateRenderPass();
	CreateGraphicsPipeline();
	CreateFramebuffers();
	CreateCommandPool();
	CreateCommandBuffers();
	CreateSyncObjects();

	return true;
}

void VKRenderer::Render(Input* input)
{
	
}

}
