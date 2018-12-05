#pragma once

#include "window.h"

namespace kidsnow {

class VKWindow : public Window {
public:
	VKWindow(std::string windowName, int width, int height);
	~VKWindow();

public:
	virtual bool Initialize();
	virtual void Update(Input*);
	virtual bool Finalize();

private:
	virtual void Greetings();
};

} // end of kidsnow