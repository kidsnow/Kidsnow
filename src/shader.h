#pragma once

#include "graphics.h"

namespace kidsnow {

class Shader
{
public:
	Shader();
	~Shader();

public:
	bool Initialize(const char*, const char*);
	bool ShutDown();

protected:
	GLuint m_program;
};

} // end of kidsnow
