#pragma once

#include "renderer.h"

namespace kidsnow {

enum class SupportedAPI
{
	KIDSNOW_OPENGL,
	KIDSNOW_VULKAN,
};

class RendererFactory
{

public:
	RendererFactory() {};
	~RendererFactory() {};

public:
	Renderer* GetRenderer(SupportedAPI);
};

}