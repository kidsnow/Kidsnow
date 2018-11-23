#pragma once

#include "graphics.h"
#include <string>

namespace kidsnow {

class Input;

class Window {
public:
    Window(std::string windowName, int width, int height);
    ~Window();

public:
    virtual bool Initialize();
    virtual void Update(Input*);
	virtual bool Finalize();

public:
	inline int GetWidowWidth() { return m_width; }
	inline int GetWidowHeight() { return m_height; }

protected:
    void Greetings();

protected:
	std::string m_windowName;
	int m_width;
	int m_height;

private:
    GLFWwindow* m_window;
};

} // end of kidsnoaw
