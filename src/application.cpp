#include "application.h"
#include "utilities.h"

#include "kidsnow.h"
#include "windowfactory.h"
#include "renderer.h"
#include "camera.h"
#include "input.h"

namespace kidsnow {

Application::Application(std::string appName, int posX, int posY, int width, int height)
	: m_appName(appName), m_posX(posX), m_posY(posY), m_width(width), m_height(height) {}

Application::~Application()
{
	delete m_input;
	delete m_camera;
	delete m_renderer;
	delete m_window;
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
	CHECKRESULT(m_window->Initialize());

	m_renderer = m_window->GenerateRenderer();
	if (m_renderer == nullptr)
	{
		return false;
	}
	CHECKRESULT(m_renderer->Initialize());

	m_camera = new Camera();

	m_input = new Input();
	m_input->Initialize();

    return true;
}

void Application::Run()
{
    while (true)
    {
        m_renderer->Render(m_camera, m_input);
        m_window->Update(m_input);
		if (m_window->Finalize())
		{
			return;
		}
    }
}

} // end of kidsnow
