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

bool Application::initialize()
{
	WindowFactory* windowFactory = new WindowFactory();
	m_window = windowFactory->getWindow(m_appName, m_posX, m_posY, m_width, m_height, SupportedAPI::OPENGL);
	if (m_window == nullptr)
	{
		return false;
	}
	delete windowFactory;
	CHECKRESULT(m_window->initialize());

	m_window->makeCurrent();

	m_renderer = m_window->generateRenderer();
	if (m_renderer == nullptr)
	{
		return false;
	}
	CHECKRESULT(m_renderer->initialize());

	m_camera = new Camera();
	m_camera->setPosition(0.0f, 0.0f, 3.0f);
	m_camera->setRotation(0.0f, 0.0f, 0.0f);
	m_camera->setUp();

	m_input = new Input();
	m_input->initialize();

    return true;
}

void Application::cameraControl()
{
	if (m_input->isKeyDown(KEYVALUE::KEY_W))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x, pos.y, pos.z - 0.1);
	}
	if (m_input->isKeyDown(KEYVALUE::KEY_S))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x, pos.y, pos.z + 0.1);
	}
	if (m_input->isKeyDown(KEYVALUE::KEY_A))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x - 0.1, pos.y, pos.z);
	}
	if (m_input->isKeyDown(KEYVALUE::KEY_D))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x + 0.1, pos.y, pos.z);
	}
	if (m_input->isKeyDown(KEYVALUE::KEY_Q))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x, pos.y - 0.1, pos.z);
	}
	if (m_input->isKeyDown(KEYVALUE::KEY_E))
	{
		glm::vec4 pos = m_camera->getPosition();
		m_camera->setPosition(pos.x, pos.y + 0.1, pos.z);
	}
	m_camera->setUp();
}

void Application::run()
{
    while (true)
    {
		m_window->makeCurrent();
        m_renderer->render(m_camera);
        m_window->update(m_input);

		cameraControl();

		if (m_window->finalize())
		{
			return;
		}
    }
}

} // end of kidsnow
