#pragma once

#include "SDL/SDL.h"
#include <string>

namespace kidsnow {

class Input;

class Window {
public:
	Window(std::string windowName, int width, int height);
	virtual ~Window();

public:
	virtual bool Initialize();
	virtual void Update(Input*);
	virtual bool Finalize();

protected:
	virtual void Greetings();

public:
	inline SDL_Window* GetNativeWindow() { return m_window; }
	inline int GetWidowWidth() { return m_width; }
	inline int GetWidowHeight() { return m_height; }

protected:
	std::string m_windowName;
	int m_width;
	int m_height;
	SDL_Window* m_window;
	bool m_windowShouldClose;
};

} // end of kidsnoaw
