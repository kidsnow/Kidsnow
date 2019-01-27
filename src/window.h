#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace kidsnow {

class Input;

class Window {
public:
	Window(std::string windowName, int width, int height) :
		m_windowName(windowName), m_width(width), m_height(height) {}
	virtual ~Window() {}

public:
    virtual bool Initialize() = 0;
    virtual void Update(Input*) = 0;
	virtual bool Finalize() = 0;

protected:
	virtual void Greetings() = 0;

public:
	inline GLFWwindow* GetNativeWindow() { return m_window; }
	inline int GetWidowWidth() { return m_width; }
	inline int GetWidowHeight() { return m_height; }

protected:
	std::string m_windowName;
	int m_width;
	int m_height;
    GLFWwindow* m_window;
};

} // end of kidsnoaw
