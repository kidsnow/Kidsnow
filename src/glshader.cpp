#include "glshader.h"
#include "utilities.h"

#include <iostream>
#include "glm/gtc/type_ptr.hpp"

namespace kidsnow {

void GLShader::use()
{
	glUseProgram(this->m_id);
}

const GLchar* GLShader::readShader(const char* fileName) {
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
	const GLchar* vertexSource = readShader(vsFileName);
	if (vertexSource == NULL)
		return false;
	const GLchar* fragmentSource = readShader(psFileName);
	if (fragmentSource == NULL)
		return false;
	const GLchar* geometrySource = nullptr;
	if (gsFileName != nullptr)
	{
		geometrySource = readShader(gsFileName);
		if (geometrySource == NULL)
			return false;
	}

	GLuint vertexShader, fragmentShader, geometryShader;
	// Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	if (!checkCompileErrors(vertexShader, "VERTEX"))
		return false;
	// Fragment Shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	if (!checkCompileErrors(fragmentShader, "FRAGMENT"))
		return false;
	// If geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometryShader, 1, &geometrySource, NULL);
		glCompileShader(geometryShader);
		if (!checkCompileErrors(geometryShader, "GEOMETRY"))
			return false;
	}
	// Shader Program
	this->m_id = glCreateProgram();
	glAttachShader(this->m_id, vertexShader);
	glAttachShader(this->m_id, fragmentShader);
	if (geometrySource != nullptr)
		glAttachShader(this->m_id, geometryShader);
	glLinkProgram(this->m_id);
	if (!checkCompileErrors(this->m_id, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	if (geometrySource != nullptr)
		glDeleteShader(geometryShader);

	if (vertexSource != nullptr)
		delete vertexSource;
	if (fragmentSource != nullptr)
		delete fragmentSource;
	if (geometrySource != nullptr)
		delete geometrySource;

	return true;
}

bool GLShader::compileComputingShader(const char* csFileName)
{
	const GLchar* computeSource = readShader(csFileName);
	GLuint sCompute;
	// Vertex Shader
	sCompute = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(sCompute, 1, &computeSource, NULL);
	glCompileShader(sCompute);
	if (!checkCompileErrors(sCompute, "COMPUTE"))
		return false;

	// Shader Program
	this->m_id = glCreateProgram();
	glAttachShader(this->m_id, sCompute);
	glLinkProgram(this->m_id);
	if (!checkCompileErrors(this->m_id, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(sCompute);

	return true;
}

void GLShader::setFloat(const GLchar *name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform1f(glGetUniformLocation(this->m_id, name), value);
}
void GLShader::setInteger(const GLchar *name, GLint value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform1i(glGetUniformLocation(this->m_id, name), value);
}
void GLShader::setVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform2f(glGetUniformLocation(this->m_id, name), x, y);
}
void GLShader::setVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform2f(glGetUniformLocation(this->m_id, name), value.x, value.y);
}
void GLShader::setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->m_id, name), x, y, z);
}
void GLShader::setVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->m_id, name), value.x, value.y, value.z);
}
void GLShader::setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform4f(glGetUniformLocation(this->m_id, name), x, y, z, w);
}
void GLShader::setVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniform4f(glGetUniformLocation(this->m_id, name), value.x, value.y, value.z, value.w);
}
void GLShader::setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
{
	if (useShader)
		this->use();
	glUniformMatrix4fv(glGetUniformLocation(this->m_id, name), 1, GL_FALSE, glm::value_ptr(matrix));
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