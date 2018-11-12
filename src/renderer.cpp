#include "renderer.h"
#include "logger.h"

#include "glcontext.h"
#include "simpleshader.h"
#include "model.h"

namespace kidsnow {

Renderer::Renderer()
{
	m_context = new GLContext();
	m_simpleShader = new SimpleShader();
	m_model = new Model();
}

Renderer::~Renderer()
{
	delete m_model;
	delete m_simpleShader;
	delete m_context;
}

bool Renderer::Initialize(int width, int height)
{
	if (!m_context->Initialize()) return false;
	if (!m_simpleShader->Initialize("../../../src/resource/simple.vert", "../../../src/resource/simple.frag")) return false;
	if (!m_model->Initialize()) return false;

	return true;
}

void Renderer::Render()
{
	m_context->Render();
	m_model->Render();
	m_simpleShader->Render();
}

} // end of kidsnow
