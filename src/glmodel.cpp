#include "glmodel.h"
#include "glshader.h"

namespace kidsnow {


GLModel::GLModel()
{
}


GLModel::~GLModel()
{
}

bool GLModel::Initialize()
{
	static const GLfloat triangleVertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	// Initialize vertex array object.
	glGenVertexArrays(1, &m_triangleVAO);
	glBindVertexArray(m_triangleVAO);

	// Initialize vertex buffer object.
	glGenBuffers(1, &m_triangleVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

	// glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	// glEnableVertexAttribArray(0);

	// glBindBuffer(GL_ARRAY_BUFFER, 0);
	// glBindVertexArray(0);

	return true;
}

void GLModel::DrawLikeThis(GLShader* shader)
{
	m_shader = shader;
}

bool GLModel::Render(glm::mat4x4 viewProjectionMatrix)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	m_shader->Render();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	return true;
}

} // end of kidsnow
