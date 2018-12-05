#include "glrenderer.h"
#include "logger.h"

#include "glcontext.h"
#include "simpleglshader.h"
#include "glmodel.h"
#include "input.h"

namespace kidsnow {

GLRenderer::GLRenderer()
{
	m_context = new GLContext();
	m_simpleShader = new SimpleGLShader();
	m_model = new GLModel();
}

GLRenderer::~GLRenderer()
{
	delete m_model;
	delete m_simpleShader;
	delete m_context;
}

bool GLRenderer::Initialize(int width, int height)
{
	if (!m_context->Initialize()) return false;
	if (!m_simpleShader->Initialize("resource/simple.vert", "resource/simple.frag")) return false;
	if (!m_model->Initialize()) return false;

	return true;
}

void GLRenderer::Render(Input* input)
{
	m_context->Render();
	m_model->Render();
	m_simpleShader->Render();
}

} // end of kidsnow
