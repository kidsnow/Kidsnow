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

void SimpleShader::BeginScene()
{
	glUseProgram(m_program);
	SetShaderParameters();
}

void SimpleShader::EndScene()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

} // end of kidsnow