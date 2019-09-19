#pragma once

#include "window.h"

namespace kidsnow {

class Renderer;

class GLWindow : public Window {
public:
	GLWindow(std::string windowName, int posX, int posY, int width, int height);
	~GLWindow();

public:
	virtual bool Initialize();
	virtual void MakeCurrent();
	virtual bool Finalize();
	virtual Renderer* GenerateRenderer();

private:
	virtual void Greetings();

private:
	SDL_GLContext m_context;
};

} // end of kidsnow