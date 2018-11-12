#pragma once

#include "context.h"

namespace kidsnow {

class GLContext : public Context {
public:
	GLContext();
	~GLContext();

public:
	virtual bool Initialize();
	virtual void Render();
};

} // end of kidsnow