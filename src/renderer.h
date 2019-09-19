#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_syswm.h"

namespace kidsnow {

class Camera;

class Renderer {
public:
	Renderer() {};
	virtual ~Renderer() {};

public:
	virtual bool Initialize() = 0;
    virtual void Render(Camera* camera) = 0;
	virtual void Resize(int w, int h) = 0;
};

} // end of kidsnow
