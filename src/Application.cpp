#include "Application.h"

namespace kidsnow {
    
Application::Application(std::string appName)
{
    m_window = new Window(appName);
    m_renderer = new Renderer();
    m_window->Initialize();
}

Application::~Application()
{

}

void Application::Initialize()
{
    m_window->Initialize();
}

void Application::Run()
{
    while (!m_window->ShouldClose())
    {
        m_renderer->Render();

        m_window->SwapBuffers();
    }
}

}
