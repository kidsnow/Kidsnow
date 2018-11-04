#include "textureshader.h"

namespace kidsnow {

TextureShader::TextureShader()
{
}


TextureShader::~TextureShader()
{
}

bool TextureShader::Initialize(const char* vsFileName, const char* psFileName)
{
	Shader::Initialize(vsFileName, psFileName);

	m_locMVPMatrix = glGetUniformLocation(m_program, "u_ModelViewProjectionMatrix");
	m_locScale = glGetUniformLocation(m_program, "u_scale");

	return true;
}

bool TextureShader::SetShaderParameters()
{
	return true;
}

}