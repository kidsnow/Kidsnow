#include "application.h"
#include "helper.h"

#include "renderer.h"
#include "window.h"
#include "input.h"

namespace kidsnow {

Application::Application(std::string appName, int width, int height)
{
    m_appName = appName;
    m_window = new Window(m_appName, width, height);
    m_renderer = new Renderer();
	m_input = new Input();
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

	m_input->Initialize();

	if (!(m_renderer->Initialize(m_window->GetWidowWidth(), m_window->GetWidowHeight())))
	{
		LogInfo("Init renderer failed.");
		return false;
	}

    return true;
}

void Application::Run()
{
    while (!m_window->Finalize())
    {
        m_renderer->Render();
        m_window->Update(m_input);
    }
}

} // end of kidsnow
