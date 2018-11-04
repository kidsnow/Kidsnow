#include "model.h"

#ifdef _WIN32
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

namespace kidsnow {


Model::Model()
{
}


Model::~Model()
{
}

bool Model::Initialize()
{
	static const GLfloat triangleVertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	// Initialize vertex buffer object.
	glGenBuffers(1, &m_triangleVBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

	// Initialize vertex array object.
	glGenVertexArrays(1, &m_triangleVAO);
	glBindVertexArray(m_triangleVAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return true;
}

bool Model::Render()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_triangleVBO);

	return true;
}

} // end of kidsnow