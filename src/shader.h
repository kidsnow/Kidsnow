#pragma once

#ifdef _WIN32
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace kidsnow {

class Shader
{
public:
	Shader();
	~Shader();

	bool Initialize(const char*, const char*);
	bool ShutDown();

private:
	bool CompileShader(const char*, GLenum, GLuint&);
	GLchar* Shader::ReadShader(const char*);

private:
	GLuint m_program;
};

} // end of kidsnow