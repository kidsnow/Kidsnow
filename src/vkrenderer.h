#pragma once

#include "renderer.h"

namespace kidsnow {

class VKRenderer : public Renderer
{
public:
	VKRenderer() {};
	~VKRenderer() {};

public:
	virtual bool Initialize(int width, int height);
	virtual void Render(Input* input);
};

}