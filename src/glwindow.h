#pragma once

#include "window.h"

namespace kidsnow {

class GLWindow : public Window {
public:
	GLWindow(std::string windowName, int width, int height);
	~GLWindow();

public:
	virtual bool Initialize();
	virtual void Update(Input*);
	virtual bool Finalize();

private:
	virtual void Greetings();
};

} // end of kidsnow