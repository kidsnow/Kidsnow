#include "shader.h"
#include "logger.h"

#include "graphics.h"

#include <cstdio>

namespace kidsnow {

Shader::Shader()
{
}


Shader::~Shader()
{
}

GLchar* ReadShader(const char* fileName) {
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

bool CompileShader(const char* shaderFileName, GLenum shaderType, GLuint& shader)
{
	shader = glCreateShader(shaderType);
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
		GLsizei asdf;
		GLchar* infoLog = new GLchar[10000];
		glGetShaderInfoLog(shader, 10000, &asdf, infoLog);
		glDeleteShader(shader);
		return false;
	}

	return true;
}

bool Shader::Initialize(const char* vsFileName, const char* fsFileName)
{
	m_program = glCreateProgram();
	if (m_program == NULL)
	{
		LogDebug("Failed to create m_program object.");
		return false;
	}

	GLuint vertexShader, fragmentShader;
	if (!CompileShader(vsFileName, GL_VERTEX_SHADER, vertexShader)) return false;
	if (!CompileShader(fsFileName, GL_FRAGMENT_SHADER, fragmentShader)) return false;
	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);

	glLinkProgram(m_program);
	GLint linked;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linked);
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
	return true;
}

} // end of kidsnow
