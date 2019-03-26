#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_syswm.h"

namespace kidsnow {

class Camera;

class Renderer {
public:
	Renderer(SDL_Window* window) : m_window(window) {};
	virtual ~Renderer() {};

public:
	virtual bool Initialize() = 0;
    virtual void Render(Camera* camera) = 0;

protected:
	SDL_Window* m_window;
};

} // end of kidsnow
