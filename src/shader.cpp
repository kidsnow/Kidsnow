#include "shader.h"
#include "helper.h"

namespace kidsnow {

Shader::Shader()
{
}


Shader::~Shader()
{
}

bool Shader::CompileShader(const char* shaderFileName, GLenum shaderType, GLuint& shader)
{
	GLuint shader = glCreateShader(GL_VERTEX_SHADER);
	if (shader == NULL)
	{
		LogDebug("Failed to create shader object.");
		return false;
	}

	GLchar* source = ReadShader(shaderFileName);
	if (source == NULL)
	{
		glDeleteShader(shader);
		return false;
	}

	glShaderSource(shader, 1, &source, NULL);
	free(source);

	glCompileShader(shader);

	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		glDeleteShader(shader);
		return false;
	}

	return true;
}

bool Shader::Initialize(const char* vsFileName, const char* psFileName)
{
	GLuint program = glCreateProgram();
	if (program == NULL)
	{
		LogDebug("Failed to create program object.");
		return false;
	}

	GLuint vertexShader, fragmentShader;
	if (!CompileShader(vsFileName, GL_VERTEX_SHADER, vertexShader)) return false;
	if (!CompileShader(psFileName, GL_FRAGMENT_SHADER, fragmentShader)) return false;
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		return false;
	}

	return true;
}

bool Shader::ShutDown()
{

}

GLchar* Shader::ReadShader(const char* fileName) {
	FILE* infile = fopen(fileName, "rb");

	if (!infile) {
		LogDebug("Unable to open file '%s'", fileName);
		return NULL;
	}

	fseek(infile, 0, SEEK_END);
	int len = ftell(infile);
	fseek(infile, 0, SEEK_SET);

	GLchar* source = (GLchar*)malloc((len + 1) * sizeof(GLchar));

	fread(source, 1, len, infile);
	fclose(infile);

	source[len] = 0;

	return source;
}

} // end of kidsnow