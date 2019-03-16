#pragma once

#include "window.h"

namespace kidsnow {

class Renderer;

class VKWindow : public Window {
public:
	VKWindow(std::string windowName, int posX, int posY, int width, int height);
	~VKWindow();

public:
	virtual bool Initialize();
	virtual void Update(Input*);
	virtual bool Finalize();
	virtual Renderer* GenerateRenderer();

private:
	virtual void Greetings();
};

} // end of kidsnow