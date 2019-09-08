#include "glshader.h"
#include "utilities.h"

#include <iostream>
#include "glm/gtc/type_ptr.hpp"

namespace kidsnow {

GLShader &GLShader::use()
{
	glUseProgram(this->ID);
	return *this;
}

GLchar* ReadShader(const char* fileName) {
	FILE* infile = fopen(fileName, "rb");
	if (!infile) {
		std::cerr << "Unable to open file '" << fileName << "'" << std::endl;
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

bool GLShader::compileRenderingShader(const char* vsFileName, const char* psFileName, const char* gsFileName)
{
	GLuint sVertex, sFragment, gShader;

	const GLchar* vertexSource = ReadShader(vsFileName);
	if (vertexSource == NULL)
		return false;
	const GLchar* fragmentSource = ReadShader(psFileName);
	if (fragmentSource == NULL)
		return false;
	const GLchar* geometrySource = nullptr;
	if (gsFileName != nullptr)
	{
		geometrySource = ReadShader(gsFileName);
		if (geometrySource == NULL)
			return false;
	}

	// Vertex Shader
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	if (!checkCompileErrors(sVertex, "VERTEX"))
		return false;
	// Fragment Shader
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	if (!checkCompileErrors(sFragment, "FRAGMENT"))
		return false;
	// If geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &geometrySource, NULL);
		glCompileShader(gShader);
		if (!checkCompileErrors(gShader, "GEOMETRY"))
			return false;
	}
	// Shader Program
	this->ID = glCreateProgram();
	glAttachShader(this->ID, sVertex);
	glAttachShader(this->ID, sFragment);
	if (geometrySource != nullptr)
		glAttachShader(this->ID, gShader);
	glLinkProgram(this->ID);
	if (!checkCompileErrors(this->ID, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geometrySource != nullptr)
		glDeleteShader(gShader);

	return true;
}

bool GLShader::compileComputingShader(const char* csFileName)
{
	const GLchar* computeSource = ReadShader(csFileName);
	GLuint sCompute;
	// Vertex Shader
	sCompute = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(sCompute, 1, &computeSource, NULL);
	glCompileShader(sCompute);
	if (!checkCompileErrors(sCompute, "COMPUTE"))
		return false;

	// Shader Program
	this->ID = glCreateProgram();
	glAttachShader(this->ID, sCompute);
	glLinkProgram(this->ID);
	if (!checkCompileErrors(this->ID, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(sCompute);

	return true;
}

void GLShader::setFloat(const GLchar *name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}
void GLShader::setInteger(const GLchar *name, GLint value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}
void GLShader::setVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}
void GLShader::setVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
}
void GLShader::setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}
void GLShader::setVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}
void GLShader::setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}
void GLShader::setVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
}
void GLShader::setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
}


bool GLShader::checkCompileErrors(GLuint object, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
			return false;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
			return false;
		}
	}
	return true;
}

}