#include "renderer.h"
#include "helper.h"

#include "simpleshader.h"
#include "model.h"

namespace kidsnow {

Renderer::Renderer()
{
	m_simpleShader = new SimpleShader();
	m_model = new Model();
}

Renderer::~Renderer()
{

}

bool Renderer::Initialize(int width, int height)
{
#ifdef _WIN32
	glewExperimental = true; // Needed for core profile
	GLint result = glewInit();
	if (GLEW_OK != result)
	{
		LogDebug("%s", glewGetErrorString(result));
		exit(EXIT_FAILURE);
	}
#endif

	glClearColor(0.4f, 0.4f, 1.0f, 1.0f); // CYAN
	glEnable(GL_DEPTH_TEST);

	if (!m_simpleShader->Initialize("../../../src/resource/simple.vert", "../../../src/resource/simple.frag")) return false;
	if (!m_model->Initialize()) return false;

	return true;
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_model->Render();
	m_simpleShader->Render();
}

} // end of kidsnow
