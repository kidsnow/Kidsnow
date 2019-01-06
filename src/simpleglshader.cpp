#include "simpleglshader.h"

namespace kidsnow {

SimpleGLShader::SimpleGLShader()
{
}


SimpleGLShader::~SimpleGLShader()
{
}

bool SimpleGLShader::Initialize(const char* vsFileName, const char* fsFileName)
{
	if (!GLShader::Initialize(vsFileName, fsFileName)) return false;
	
	/*m_locMVPMatrix = glGetUniformLocation(m_program, "u_ModelViewProjectionMatrix");
	m_locPrimitiveColor = glGetUniformLocation(m_program, "u_primitive_color");*/

	return true;
}

bool SimpleGLShader::SetShaderParameters()
{

	return true;
}

void SimpleGLShader::Render()
{
	glUseProgram(m_program);
	SetShaderParameters();
}

} // end of kidsnow
