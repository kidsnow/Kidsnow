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
	virtual bool Initialize();
	virtual void MakeCurrent() = 0;
	virtual void Update(Input*);
	virtual bool Finalize();
	virtual Renderer* GenerateRenderer() = 0;

protected:
	virtual void Greetings() = 0;

public:
	inline SDL_Window* GetNativeWindow() { return m_window; }
	inline int GetWidowWidth() { return m_width; }
	inline int GetWidowHeight() { return m_height; }

protected:
	uint32_t m_graphicsAPI;
	std::string m_windowName;
	int m_posX, m_posY;
	int m_width, m_height;
	SDL_Window* m_window;
	bool m_windowShouldClose;
};

} // end of kidsnoaw
