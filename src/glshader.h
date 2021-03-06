#pragma once

#include "glcommon.h"
#include <string>

namespace kidsnow {

class GLShader
{
public:
	// State
	GLuint ID;
	// Constructor
	GLShader() { }
	// Sets the current shader as active
	GLShader &Use();
	// Compiles the shader from given source code
	bool    CompileRenderingShader(const char *vsFileName, const char *psFileName, const char *gsFileName = nullptr); // Note: geometry source code is optional 
	bool	CompileComputingShader(const char *csFileName);
	// Utility functions
	void    SetFloat(const GLchar *name, GLfloat value, GLboolean useShader = false);
	void    SetInteger(const GLchar *name, GLint value, GLboolean useShader = false);
	void    SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void    SetVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader = false);
	void    SetVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void    SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader = false);
	void    SetVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void    SetVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
	void    SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);
private:
	// Checks if compilation or linking failed and if so, print the error logs
	bool    CheckCompileErrors(GLuint object, std::string type);
};

} // end of kidsnow
