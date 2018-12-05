#include "textureglshader.h"

namespace kidsnow {

TextureGLShader::TextureGLShader()
{
}


TextureGLShader::~TextureGLShader()
{
}

bool TextureGLShader::Initialize(const char* vsFileName, const char* psFileName)
{
	GLShader::Initialize(vsFileName, psFileName);

	m_locMVPMatrix = glGetUniformLocation(m_program, "u_ModelViewProjectionMatrix");
	m_locScale = glGetUniformLocation(m_program, "u_scale");

	return true;
}

bool TextureGLShader::SetShaderParameters()
{
	return true;
}

}