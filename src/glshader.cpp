#include "glshader.h"
#include "utilities.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include "glm/gtc/type_ptr.hpp"

namespace kidsnow {

void GLShader::Use()
{
	glUseProgram(this->m_id);
}

//const GLchar* GLShader::readShader(const char* fileName)
//{
//	FILE* infile = fopen(fileName, "rb");
//	if (!infile) {
//		std::cerr << "Unable to open file '" << fileName << "'" << std::endl;
//		return NULL;
//	}
//
//	fseek(infile, 0, SEEK_END);
//	int len = ftell(infile);
//	fseek(infile, 0, SEEK_SET);
//
//	GLchar* source = (GLchar*)malloc((len + 1) * sizeof(GLchar));
//
//	fread(source, 1, len, infile);
//	fclose(infile);
//
//	source[len] = 0;
//
//	return source;
//}
const GLchar* GLShader::ReadShader(const char* fileName)
{
	std::string shaderCode;
	std::ifstream shaderFile;
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		shaderFile.open(fileName);
		std::stringstream vShaderStream;
		// read file's buffer contents into streams
		vShaderStream << shaderFile.rdbuf();
		// close file handlers
		shaderFile.close();
		// convert stream into string
		shaderCode = vShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "ERROR::SHADER::File not successfully read" << std::endl;
		return nullptr;
	}

	GLchar* source = new GLchar[strlen(shaderCode.c_str()) + 1];
	strcpy(source, shaderCode.c_str());

	return source;
}

bool GLShader::CompileRenderingShader(const char* vsFileName, const char* psFileName, const char* gsFileName)
{
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

	GLuint vertexShader, fragmentShader, geometryShader;
	// Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	if (!CheckCompileErrors(vertexShader, "VERTEX"))
		return false;
	// Fragment Shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	if (!CheckCompileErrors(fragmentShader, "FRAGMENT"))
		return false;
	// If geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometryShader, 1, &geometrySource, NULL);
		glCompileShader(geometryShader);
		if (!CheckCompileErrors(geometryShader, "GEOMETRY"))
			return false;
	}
	// Shader Program
	this->m_id = glCreateProgram();
	glAttachShader(this->m_id, vertexShader);
	glAttachShader(this->m_id, fragmentShader);
	if (geometrySource != nullptr)
		glAttachShader(this->m_id, geometryShader);
	glLinkProgram(this->m_id);
	if (!CheckCompileErrors(this->m_id, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	if (geometrySource != nullptr)
		glDeleteShader(geometryShader);

	if (vertexSource != nullptr)
		delete[] vertexSource;
	if (fragmentSource != nullptr)
		delete[] fragmentSource;
	if (geometrySource != nullptr)
		delete[] geometrySource;

	return true;
}

bool GLShader::CompileComputingShader(const char* csFileName)
{
	const GLchar* computeSource = ReadShader(csFileName);
	GLuint sCompute;
	// Vertex Shader
	sCompute = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(sCompute, 1, &computeSource, NULL);
	glCompileShader(sCompute);
	if (!CheckCompileErrors(sCompute, "COMPUTE"))
		return false;

	// Shader Program
	this->m_id = glCreateProgram();
	glAttachShader(this->m_id, sCompute);
	glLinkProgram(this->m_id);
	if (!CheckCompileErrors(this->m_id, "PROGRAM"))
		return false;
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(sCompute);

	return true;
}

void GLShader::SetFloat(const GLchar *name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform1f(glGetUniformLocation(this->m_id, name), value);
}
void GLShader::SetInteger(const GLchar *name, GLint value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform1i(glGetUniformLocation(this->m_id, name), value);
}
void GLShader::SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->m_id, name), x, y);
}
void GLShader::SetVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->m_id, name), value.x, value.y);
}
void GLShader::SetVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->m_id, name), x, y, z);
}
void GLShader::SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->m_id, name), value.x, value.y, value.z);
}
void GLShader::SetVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->m_id, name), x, y, z, w);
}
void GLShader::SetVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->m_id, name), value.x, value.y, value.z, value.w);
}
void GLShader::SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->m_id, name), 1, GL_FALSE, glm::value_ptr(matrix));
}


bool GLShader::CheckCompileErrors(GLuint object, std::string type)
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