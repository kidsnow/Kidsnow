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
	virtual bool initialize() = 0;
    virtual void render(Camera* camera) = 0;
	virtual void resize(int w, int h) = 0;
};

} // end of kidsnow
