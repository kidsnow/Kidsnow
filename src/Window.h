#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace kidsnow {

class Input;

class Window {
public:
    Window(std::string windowName, int width, int height);
    ~Window();

public:
    bool Initialize();
    void Update(Input*);
	bool Finalize();

public:
	inline int GetWidowWidth() { return m_width; }
	inline int GetWidowHeight() { return m_height; }

private:
    void Greetings();

private:
    GLFWwindow* m_window;
    std::string m_windowName;
    int m_width;
    int m_height;
};

} // end of kidsnoaw
