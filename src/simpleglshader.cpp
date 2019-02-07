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
	
	m_MVPMatLoc = glGetUniformLocation(m_program, "u_MVPMat");

	return true;
}

void SimpleGLShader::SetParameters(glm::mat4x4 MVPMat)
{
	m_MVPMat = MVPMat;
}

void SimpleGLShader::Render()
{
	glUseProgram(m_program);
	glProgramUniformMatrix4fv(m_program, m_MVPMatLoc, 1, GL_FALSE, &m_MVPMat[0][0]);
}

} // end of kidsnow
