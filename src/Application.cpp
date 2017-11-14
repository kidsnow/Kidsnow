#include "Application.h"
#include <GLFW/glfw3.h>
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
    LogInfo("Finalizing application...");
    glfwTerminate();
    LogInfo("Bye!");
}

bool Application::Initialize()
{
    if (!glfwInit())
    {
        LogDebug("GLFW initialize failed!");
        return false;
    }

    if (!(m_window->Initialize()))
    {
        glfwTerminate();
        return false;
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
