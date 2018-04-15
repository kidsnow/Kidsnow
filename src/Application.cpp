#include "Application.h"
#include "log.h"

namespace kidsnow {

Application::Application(std::string appName, int width, int height)
{
    m_appName = appName;
    m_window = new Window(m_appName, width, height);
    m_renderer = new Renderer();
}

Application::~Application()
{
    LogInfo("Bye!");
}

bool Application::Initialize()
{
    if (!(m_window->Initialize()))
    {
        LogInfo("Init window failed.");
        return false;
    }
	if (!(m_renderer->Initialize()))
	{
		LogInfo("Init renderer failed.");
	}

    return true;
}

void Application::Run()
{
    while (!m_window->Finalize())
    {
        m_renderer->Render();
        m_window->Update();
    }
}

} // end of kidsnow
