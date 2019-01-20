#pragma once

#include "glshader.h"
#include "glcommon.h"

namespace kidsnow {

class SimpleGLShader : public GLShader
{
public:
	SimpleGLShader();
	~SimpleGLShader();

public:
	virtual void Render();
	void SetParameters(glm::mat4x4);
	bool Initialize(const char*, const char*);

private:
	GLuint m_MVPMatLoc;
	glm::mat4x4 m_MVPMat;
};

} // end of kidsnow
