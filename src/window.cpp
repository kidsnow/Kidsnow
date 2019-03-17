#include "window.h"
#include "input.h"

namespace kidsnow {

Window::Window(uint32_t graphicsAPI, std::string windowName, int posX, int posY, int width, int height) :
	m_graphicsAPI(graphicsAPI), m_windowName(windowName), m_posX(posX), m_posY(posY), m_width(width), m_height(height), m_windowShouldClose(false) {}

Window::~Window() {}

bool Window::Initialize()
{
	if (SDL_VideoInit(NULL) < 0)
	{
		SDL_Log("Couldn't initialize video driver: %s\n", SDL_GetError());
		return false;
	}

	SDL_DisplayMode displayMode;
	uint32_t windowFlags;

	SDL_zero(displayMode);
	displayMode.format = SDL_PIXELFORMAT_RGB888;
	displayMode.refresh_rate = 0;

	windowFlags = 0;
	windowFlags |= SDL_WINDOW_RESIZABLE;
	windowFlags |= m_graphicsAPI;

	m_window = SDL_CreateWindow(m_windowName.c_str(), m_posX, m_posY, m_width, m_height, windowFlags);
	if (m_window == NULL)
	{
		SDL_Log("Couldn't create window: %s\n", SDL_GetError());
		return false;
	}
	
	int createdWindowWidth, createdWindowHeight;
	SDL_GetWindowSize(m_window, &createdWindowWidth, &createdWindowHeight);
	if (!(windowFlags & SDL_WINDOW_RESIZABLE) &&
		(createdWindowWidth != m_width || createdWindowHeight != m_height)) {
		printf("Window requested size %dx%d, got %dx%d\n",
			m_width, m_height, createdWindowWidth, createdWindowHeight);
		m_width = createdWindowWidth;
		m_height = createdWindowHeight;
	}

	SDL_ShowWindow(m_window);
	return true;
}

bool Window::Finalize()
{
	if (!m_windowShouldClose)
	{
		return false;
	}

	SDL_DestroyWindow(m_window);
	SDL_Quit();
	return true;
}

void Window::Update(Input* input)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_CLOSE:
				m_windowShouldClose = true;
				break;
			}
			break;
		case SDL_KEYDOWN:
			bool withControl = !!(event.key.keysym.mod & KMOD_CTRL);
			bool withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
			bool withAlt = !!(event.key.keysym.mod & KMOD_ALT);

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_windowShouldClose = true;
				break;
			}

			break;
		}
	}

	SDL_GL_SwapWindow(m_window);

	return;
}

} // end of kidsnow