#pragma once

#include <string>

namespace kidsnow {

class Window;
class Renderer;
class Input;

class Application {
public:
    Application(std::string appName, int width, int height);
    ~Application();

public:
    bool Initialize();
    void Run();

private:
    std::string m_appName;
    Window* m_window;
    Renderer* m_renderer;
	Input *m_input;
};

} // end of kidsnow
