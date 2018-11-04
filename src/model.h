#pragma once

#ifdef _WIN32
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

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