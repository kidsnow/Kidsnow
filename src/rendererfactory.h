#pragma once

#include "renderer.h"

namespace kidsnow {

enum class SupportedAPI;

class RendererFactory
{

public:
	RendererFactory() {};
	~RendererFactory() {};

public:
	Renderer* GetRenderer(SupportedAPI);
};

}