#pragma once

#include "graphics.h"

namespace kidsnow {

class Model
{
public:
	Model();
	~Model();

public:
	bool Initialize();
	bool Render();

private:
	GLuint m_triangleVBO, m_triangleVAO;
};

} // end of kidsnow
