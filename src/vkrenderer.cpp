#include "vkrenderer.h"
#include <vector>

#include "logger.h"

namespace kidsnow {

VKRenderer::VKRenderer() {};

VKRenderer::~VKRenderer()
{
	vkDestroyInstance(m_instance, nullptr);
};

bool VKRenderer::checkValidationLayerSupport()
{
	return true;
}

bool VKRenderer::createInstance()
{
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

	return true;
}
bool VKRenderer::setupDebugCallback() {
	return true;
}
bool VKRenderer::createSurface() {
	return true;
}
bool VKRenderer::pickPhysicalDevice() {
	return true;
}
bool VKRenderer::createLogicalDevice() {
	return true;
}
bool VKRenderer::createSwapChain() {
	return true;
}
bool VKRenderer::createImageViews() {
	return true;
}
bool VKRenderer::createRenderPass() {
	return true;
}
bool VKRenderer::createGraphicsPipeline() {
	return true;
}
bool VKRenderer::createFramebuffers() {
	return true;
}
bool VKRenderer::createCommandPool() {
	return true;
}
bool VKRenderer::createCommandBuffers() {
	return true;
}
bool VKRenderer::createSyncObjects() {
	return true;
}

bool VKRenderer::Initialize(int width, int height)
{
	createInstance();
	setupDebugCallback();
	createSurface();
	pickPhysicalDevice();
	createLogicalDevice();
	createSwapChain();
	createImageViews();
	createRenderPass();
	createGraphicsPipeline();
	createFramebuffers();
	createCommandPool();
	createCommandBuffers();
	createSyncObjects();

	return true;
}

void VKRenderer::Render(Input* input)
{
	
}

}