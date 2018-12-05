#include "application.h"
#include "logger.h"

#include "rendererfactory.h"
#ifdef OS_TOS
#include "tos_window.h"
#else
#include "window.h"
#endif
#include "input.h"

namespace kidsnow {

Application::Application(std::string appName, int width, int height)
{
    m_appName = appName;
#ifdef OS_TOS
    m_window = new TOSWindow(m_appName, width, height);
#else
    m_window = new Window(m_appName, width, height);
#endif
	RendererFactory* rendererFactory = new RendererFactory();
    m_renderer = rendererFactory->GetRenderer(SupportedAPI::KIDSNOW_OPENGL);
	m_input = new Input();
}

Application::~Application()
{
	delete m_window;
	delete m_input;
	delete m_renderer;
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
        m_renderer->Render(m_input);
        m_window->Update(m_input);
    }
}

} // end of kidsnow
