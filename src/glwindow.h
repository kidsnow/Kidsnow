#pragma once

#include "window.h"

namespace kidsnow {

class Renderer;

class GLWindow : public Window {
public:
	GLWindow(std::string windowName, int posX, int posY, int width, int height);
	~GLWindow();

public:
	virtual bool initialize();
	virtual void makeCurrent();
	virtual bool finalize();
	virtual Renderer* generateRenderer();

private:
	virtual void greetings();

private:
	SDL_GLContext m_context;
};

} // end of kidsnow