#pragma once

#include "SDL/SDL.h"
#include <string>

namespace kidsnow {

class Input;
class Renderer;

class Window {
public:
	Window(uint32_t graphicsAPI, std::string windowName, int posX, int posY, int width, int height);
	virtual ~Window();

public:
	virtual bool initialize();
	virtual void makeCurrent() = 0;
	virtual void update(Input*);
	virtual bool finalize();
	virtual Renderer* generateRenderer() = 0;

protected:
	virtual void greetings() = 0;

public:
	inline SDL_Window* getNativeWindow() { return m_window; }
	inline int getWidowWidth() { return m_width; }
	inline int getWidowHeight() { return m_height; }

protected:
	uint32_t m_graphicsAPI;
	std::string m_windowName;
	int m_posX, m_posY;
	int m_width, m_height;
	SDL_Window* m_window;
	bool m_windowShouldClose;
};

} // end of kidsnoaw
