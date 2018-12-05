#pragma once

#include "glshader.h"

namespace kidsnow {

class SimpleGLShader : public GLShader
{
public:
	SimpleGLShader();
	~SimpleGLShader();

public:
	virtual void Render();
	bool Initialize(const char*, const char*);

private:
	virtual bool SetShaderParameters();

private:
	GLuint m_locMVPMatrix, m_locPrimitiveColor;
};

} // end of kidsnow
