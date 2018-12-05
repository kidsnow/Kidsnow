#pragma once

#include "graphics.h"

namespace kidsnow {

class GLModel
{
public:
	GLModel();
	~GLModel();

public:
	bool Initialize();
	bool Render();

private:
	GLuint m_triangleVBO, m_triangleVAO;
};

} // end of kidsnow
