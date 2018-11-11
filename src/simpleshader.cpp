#include "simpleshader.h"

namespace kidsnow {

SimpleShader::SimpleShader()
{
}


SimpleShader::~SimpleShader()
{
}

bool SimpleShader::Initialize(const char* vsFileName, const char* fsFileName)
{
	if (!Shader::Initialize(vsFileName, fsFileName)) return false;

	/*m_locMVPMatrix = glGetUniformLocation(m_program, "u_ModelViewProjectionMatrix");
	m_locPrimitiveColor = glGetUniformLocation(m_program, "u_primitive_color");*/

	return true;
}

bool SimpleShader::SetShaderParameters()
{

	return true;
}

void SimpleShader::Render()
{
	glUseProgram(m_program);
	SetShaderParameters();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

} // end of kidsnow