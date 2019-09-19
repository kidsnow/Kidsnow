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

	m_window->MakeCurrent();

	m_renderer = m_window->GenerateRenderer();
	if (m_renderer == nullptr)
	{
		return false;
	}
	CHECKRESULT(m_renderer->Initialize());

	m_camera = new Camera();
	m_camera->SetPosition(0.0f, 0.0f, 3.0f);
	m_camera->SetRotation(0.0f, 0.0f, 0.0f);
	m_camera->SetUp();

	m_input = new Input();
	m_input->Initialize();

    return true;
}

void Application::CameraControl()
{
	if (m_input->IsKeyDown(KEYVALUE::KEY_W))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x, pos.y, pos.z - 0.1);
	}
	if (m_input->IsKeyDown(KEYVALUE::KEY_S))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x, pos.y, pos.z + 0.1);
	}
	if (m_input->IsKeyDown(KEYVALUE::KEY_A))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x - 0.1, pos.y, pos.z);
	}
	if (m_input->IsKeyDown(KEYVALUE::KEY_D))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x + 0.1, pos.y, pos.z);
	}
	if (m_input->IsKeyDown(KEYVALUE::KEY_Q))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x, pos.y - 0.1, pos.z);
	}
	if (m_input->IsKeyDown(KEYVALUE::KEY_E))
	{
		glm::vec4 pos = m_camera->GetPosition();
		m_camera->SetPosition(pos.x, pos.y + 0.1, pos.z);
	}
	m_camera->SetUp();
}

void Application::Run()
{
    while (true)
    {
		m_window->MakeCurrent();
        m_renderer->Render(m_camera);
        m_window->Update(m_input);

		CameraControl();

		if (m_window->Finalize())
		{
			return;
		}
    }
}

} // end of kidsnow
