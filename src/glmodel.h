#pragma once

#include "glcommon.h"

namespace kidsnow {

class GLShader;

class GLModel
{
public:
	GLModel();
	~GLModel();

public:
	bool Initialize();
	bool Render();
	void RegisterShader(GLShader*);

private:
	GLuint m_triangleVBO, m_triangleVAO;
	GLShader* m_shader;
};

} // end of kidsnow
