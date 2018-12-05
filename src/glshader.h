#pragma once

#include "glcommon.h"

namespace kidsnow {

class GLShader
{
public:
	GLShader();
	~GLShader();

public:
	bool Initialize(const char*, const char*);
	bool ShutDown();
	virtual void Render() = 0;

protected:
	GLuint m_program;
};

} // end of kidsnow
