#pragma once

#include "renderer.h"
#include "vkcommon.h"

#include <iostream>
#include <vector>
#include <fstream>

namespace kidsnow {

class VKRenderer : public Renderer
{
public:
	VKRenderer(SDL_Window* window);
	~VKRenderer();

public:
	virtual bool Initialize();
	virtual void Render(Camera* camera, Input* input);

private:
	SDL_Window* m_window;

	const int MAX_FRAMES_IN_FLIGHT = 2;

	const std::vector<const char*> m_validationLayers =
	{
		"VK_LAYER_LUNARG_standard_validation"
	};
	
	const std::vector<const char*> deviceExtensions =
	{
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
	
	const bool m_enableValidationLayers = true;

	VkInstance m_instance;
	VkDebugUtilsMessengerEXT m_debugMessenger;
	VkSurfaceKHR m_surface;

	VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
	VkDevice m_device;

	VkQueue m_graphicsQueue;
	VkQueue m_presentQueue;
	
	VkSwapchainKHR m_swapChain;
	std::vector<VkImage> m_swapChainImages;
	VkFormat m_swapChainImageFormat;
	VkExtent2D m_swapChainExtent;
	std::vector<VkImageView> m_swapChainImageViews;
	std::vector<VkFramebuffer> m_swapChainFramebuffers;

	VkRenderPass m_renderPass;
	VkPipelineLayout m_pipelineLayout;
	VkPipeline m_graphicsPipeline;

	VkCommandPool m_commandPool;
	std::vector<VkCommandBuffer> m_commandBuffers;

	std::vector<VkSemaphore> m_imageAvailableSemaphores;
	std::vector<VkSemaphore> m_renderFinishedSemaphores;
	std::vector<VkFence> m_inFlightFences;
	size_t m_currentFrame = 0;

	bool m_framebufferResized = false;

private:
	struct QueueFamilyIndices
	{
		uint32_t graphicsFamily = UINT_MAX;
		uint32_t presentFamily = UINT_MAX;

		bool IsComplete()
		{
			return graphicsFamily != UINT_MAX && presentFamily != UINT_MAX;
		}
	};
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

private:
	bool CheckValidationLayerSupport();
	std::vector<const char*> GetRequiredExtensions();
	bool CreateInstance();
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
		void* pUserData)
	{
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
		return VK_FALSE;
	}
	bool SetupDebugMessenger();
	bool CreateSurface();
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
	// Implement this method when you wanna filter physical devices.
	bool IsDeviceSuitable(VkPhysicalDevice device);
	bool PickPhysicalDevice();
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	bool CreateLogicalDevice();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	bool CreateSwapChain();
	bool CreateImageViews();
	bool CreateRenderPass();
	static std::vector<char> ReadFile(const std::string& filename)
	{
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file!");
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}
	VkShaderModule CreateShaderModule(const std::vector<char>& code);
	bool CreateGraphicsPipeline();
	bool CreateFramebuffers();
	bool CreateCommandPool();
	bool CreateCommandBuffers();
	bool CreateSyncObjects();
	bool CleanupSwapChain();
	bool Cleanup();
	bool RecreateSwapChain();
};

}