#include "glrenderer.h"
#include "logger.h"

#include "simpleglshader.h"
#include "glmodel.h"
#include "input.h"

namespace kidsnow {

GLRenderer::GLRenderer()
{
	m_simpleShader = new SimpleGLShader();
	m_model = new GLModel();
}

GLRenderer::~GLRenderer()
{
	delete m_model;
	delete m_simpleShader;
}

bool GLRenderer::Initialize(int width, int height)
{
	gladLoadGL();

	if (!m_simpleShader->Initialize("resource/simple.vert", "resource/simple.frag")) return false;
	if (!m_model->Initialize()) return false;

	glClearColor(0.4f, 0.4f, 1.0f, 1.0f); // CYAN
	glEnable(GL_DEPTH_TEST);

	return true;
}

void GLRenderer::Render(Input* input)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_model->Render();
	m_simpleShader->Render();
}

} // end of kidsnow
