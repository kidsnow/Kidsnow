#include "glrenderer.h"
#include "logger.h"

#include "glscene.h"
#include "camera.h"
#include "simpleglshader.h"
#include "glmodel.h"
#include "input.h"

namespace kidsnow {

GLRenderer::GLRenderer(SDL_Window* window, SDL_GLContext context)
	: Renderer(window), m_context(context)
{
	m_scene = new GLScene();
	m_simpleShader = new SimpleGLShader();
	m_model = new GLModel();
	m_camera = new Camera();
}

GLRenderer::~GLRenderer()
{
	delete m_scene;
	delete m_camera;
	delete m_model;
	delete m_simpleShader;
}

bool GLRenderer::Initialize()
{
	SDL_GL_MakeCurrent(m_window, m_context);

	if (!m_simpleShader->Initialize("resource/simple.vert", "resource/simple.frag")) return false;
	if (!m_model->Initialize()) return false;

	m_camera->SetPosition(0.0f, 0.0f, -3.0f);
	m_camera->SetUp();

	m_scene->RegisterCamera(m_camera);

	m_model->DrawLikeThis(m_simpleShader);

	m_scene->RegisterTarget(m_model);

	glClearColor(0.4f, 0.4f, 1.0f, 1.0f); // CYAN
	glEnable(GL_DEPTH_TEST);

	return true;
}

void GLRenderer::Render(Input* input)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_scene->Render();
}

} // end of kidsnow
