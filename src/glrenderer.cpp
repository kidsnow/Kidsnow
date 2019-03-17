#include "glrenderer.h"
#include "utilities.h"

#include "glshader.h"
#include "camera.h"
#include "input.h"

namespace kidsnow {

GLRenderer::GLRenderer(SDL_Window* window, SDL_GLContext context)
	: Renderer(window), m_context(context) {}

GLRenderer::~GLRenderer()
{
	delete m_shader;
}

bool GLRenderer::Initialize()
{
	SDL_GL_MakeCurrent(m_window, m_context);

	m_shader = new GLShader();
	if (!m_shader->CompileRenderingShader("resource/simple.vert", "resource/simple.frag")) return false;
	
	m_rectangleVertices = new GLfloat[30]
	{
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,	// lower left
		 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,	// lower right
		-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,	// upper left
		-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,	// upper left
		 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,	// lower right
		 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,	// upper right
	};

	// Initialize vertex array object.
	glGenVertexArrays(1, &m_rectangleVAO);
	glBindVertexArray(m_rectangleVAO);

	// Initialize vertex buffer object.
	GLuint rectangleVBO;
	glGenBuffers(1, &rectangleVBO);
	glBindBuffer(GL_ARRAY_BUFFER, rectangleVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 5, m_rectangleVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, rectangleVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, rectangleVBO);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Initialize source texture.
	int width, height;
	unsigned char *data = LoadImageFile("resource/PolygonPlanet.png", width, height);
	if (data)
	{
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		glFinish();
	}
	else
	{
		std::cerr << "Failed to load texture." << std::endl;
		return false;
	}

	FreeImageBuffer(data);

	return true;
}

void GLRenderer::Render(Camera* camera,Input* input)
{
	glClearColor(0.4f, 0.4f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(m_rectangleVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	m_shader->Use();

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glFinish();
}

} // end of kidsnow
