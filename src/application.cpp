#include "application.h"
#include "logger.h"

#include "kidsnow.h"
#include "windowfactory.h"
#include "renderer.h"
#include "input.h"

namespace kidsnow {

Application::Application(std::string appName, int posX, int posY, int width, int height)
	: m_appName(appName), m_posX(posX), m_posY(posY), m_width(width), m_height(height) {}

Application::~Application()
{
	/*delete m_window;
	delete m_input;
	delete m_renderer;*/
    LogInfo("Bye!");
}

bool Application::Initialize()
{
	WindowFactory* windowFactory = new WindowFactory();
	m_window = windowFactory->GetWindow(m_appName, m_posX, m_posY, m_width, m_height, SupportedAPI::OPENGL);
	if (m_window == nullptr)
	{
		return false;
	}
	delete windowFactory;
	m_window->Initialize();

	m_renderer = m_window->GenerateRenderer();
	if (m_renderer == nullptr)
	{
		return false;
	}
	m_renderer->Initialize();

	m_input = new Input();
	m_input->Initialize();

    return true;
}

void Application::Run()
{
    while (true)
    {
        m_renderer->Render(m_input);
        m_window->Update(m_input);
		if (m_window->Finalize())
		{
			return;
		}
    }
}

} // end of kidsnow
