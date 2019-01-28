#pragma once

#include "renderer.h"
#include "vkcommon.h"

#include <iostream>
#include <vector>

namespace kidsnow {

class VKRenderer : public Renderer
{
public:
	VKRenderer();
	~VKRenderer();

public:
	virtual bool Initialize(GLFWwindow* nativeWindow, int width, int height);
	virtual void Render(Input* input);

private:
	const std::vector<const char*> m_validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};
	const bool m_enableValidationLayers = true;
	VkInstance m_instance;
	VkDebugUtilsMessengerEXT m_debugMessenger;
	VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
	VkDevice m_device;
	VkQueue m_graphicsQueue;
	VkQueue m_presentQueue;
	VkSurfaceKHR m_surface;

	struct QueueFamilyIndices {
		uint32_t graphicsFamily = UINT_MAX;
		uint32_t presentFamily = UINT_MAX;

		bool IsComplete() {
			return graphicsFamily != UINT_MAX && presentFamily != UINT_MAX;
		}
	};
private:
	bool CheckValidationLayerSupport();
	std::vector<const char*> GetRequiredExtensions();
	VkResult CreateDebugUtilsMessengerEXT(
		VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(
		VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger,
		const VkAllocationCallbacks* pAllocator);
	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData) {
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
		return VK_FALSE;
	}
	bool CreateInstance();
	bool SetupDebugMessenger();
	bool CreateSurface(GLFWwindow* nativeWindow);
	bool PickPhysicalDevice();
	// Implement this method when you wanna filter physical devices.
	bool IsDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
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