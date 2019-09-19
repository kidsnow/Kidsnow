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
	bool withControl = false;
	bool withShift = false;
	bool withAlt = false; 

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
			withControl = !!(event.key.keysym.mod & KMOD_CTRL);
			withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
			withAlt = !!(event.key.keysym.mod & KMOD_ALT);

			if (withControl)
			{
				input->KeyDown(KEYVALUE::SPECIAL_CONTROL);
			}
			if (withShift)
			{
				input->KeyDown(KEYVALUE::SPECIAL_SHIFT);
			}
			if (withAlt)
			{
				input->KeyDown(KEYVALUE::SPECIAL_ALT);
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_windowShouldClose = true;
				break;
			case SDLK_w:
				input->KeyDown(KEYVALUE::KEY_W);
				break;
			case SDLK_a:
				input->KeyDown(KEYVALUE::KEY_A);
				break;
			case SDLK_s:
				input->KeyDown(KEYVALUE::KEY_S);
				break;
			case SDLK_d:
				input->KeyDown(KEYVALUE::KEY_D);
				break;
			case SDLK_q:
				input->KeyDown(KEYVALUE::KEY_Q);
				break;
			case SDLK_e:
				input->KeyDown(KEYVALUE::KEY_E);
				break;
			}

			break;
		case SDL_KEYUP:
			withControl = !!(event.key.keysym.mod & KMOD_CTRL);
			withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
			withAlt = !!(event.key.keysym.mod & KMOD_ALT);

			if (!withControl)
			{
				input->KeyUp(KEYVALUE::SPECIAL_CONTROL);
			}
			if (!withShift)
			{
				input->KeyUp(KEYVALUE::SPECIAL_SHIFT);
			}
			if (!withAlt)
			{
				input->KeyUp(KEYVALUE::SPECIAL_ALT);
			}

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_windowShouldClose = true;
				break;
			case SDLK_w:
				input->KeyUp(KEYVALUE::KEY_W);
				break;
			case SDLK_a:
				input->KeyUp(KEYVALUE::KEY_A);
				break;
			case SDLK_s:
				input->KeyUp(KEYVALUE::KEY_S);
				break;
			case SDLK_d:
				input->KeyUp(KEYVALUE::KEY_D);
				break;
			case SDLK_q:
				input->KeyUp(KEYVALUE::KEY_Q);
				break;
			case SDLK_e:
				input->KeyUp(KEYVALUE::KEY_E);
				break;
			}

			break;
		}
	}

	SDL_GL_SwapWindow(m_window);

	return;
}

} // end of kidsnow