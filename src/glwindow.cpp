#include "glwindow.h"
#include "glrenderer.h"
#include "input.h"
#include "utilities.h"

#include "glad/glad.h"

namespace kidsnow {

GLWindow::GLWindow(std::string windowName, int posX, int posY, int width, int height)
	: Window(SDL_WINDOW_OPENGL, windowName, posX, posY, width, height) {}

GLWindow::~GLWindow() {}

bool GLWindow::Initialize()
{
	if (Window::Initialize())
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		m_context = SDL_GL_CreateContext(m_window);
		if (!m_context)
		{
			LogDebug("Failed to create GL context.");
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
		{
			LogDebug("Failed to initialize GLAD.");
			return false;
		}
		Greetings();

		SDL_GL_MakeCurrent(m_window, NULL);

		return true;
	}

	return false;
}

void GLWindow::MakeCurrent()
{
	SDL_GL_MakeCurrent(m_window, m_context);
}

bool GLWindow::Finalize()
{
	if (!Window::Finalize())
	{
		return false;
	}

	SDL_GL_DeleteContext(m_context);
	return true;
}

void GLWindow::Greetings()
{
	LogInfo(glGetString(GL_VENDOR));
	LogInfo(glGetString(GL_RENDERER));
	LogInfo(glGetString(GL_VERSION));

	return;
}

Renderer* GLWindow::GenerateRenderer()
{
	GLRenderer* renderer = new GLRenderer();
	
	return renderer;
}

} // end of kidsnow