#pragma once

#include "shader.h"

namespace kidsnow {

class SimpleShader : public Shader
{
public:
	SimpleShader();
	~SimpleShader();

public:
	virtual void Render();
	bool Initialize(const char*, const char*);

private:
	virtual bool SetShaderParameters();

private:
	GLuint m_locMVPMatrix, m_locPrimitiveColor;
};

} // end of kidsnow
