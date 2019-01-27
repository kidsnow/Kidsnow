#pragma once

#define GLFW_INCLUDE_VULKAN
#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <glm/gtc/matrix_transform.hpp>
#ifdef __APPLE__
#include <vulkan/vulkan.h>
#endif
