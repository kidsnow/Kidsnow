#pragma once

#include "graphics.h"

namespace kidsnow {

class GLContext {
public:
	GLContext();
	~GLContext();

public:
	bool Initialize();
	void Render();
};

} // end of kidsnow