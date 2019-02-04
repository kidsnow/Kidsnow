#include "application.h"
#include "logger.h"

#include "kidsnow.h"
#include "rendererfactory.h"
#include "windowfactory.h"
#include "input.h"

namespace kidsnow {

Application::Application(std::string appName, int width, int height)
{
    m_appName = appName;

	WindowFactory* windowFactory = new WindowFactory();
	m_window = windowFactory->GetWindow(m_appName, width, height, SupportedAPI::VULKAN);

	if (m_window == nullptr)
		exit(0);

	RendererFactory* rendererFactory = new RendererFactory();
    m_renderer = rendererFactory->GetRenderer(SupportedAPI::VULKAN);

	if (m_renderer == nullptr)
		exit(0);

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

	if (!(m_renderer->Initialize(m_window->GetNativeWindow())))
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
