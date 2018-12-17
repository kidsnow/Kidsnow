#include "glcontext.h"
#include "glcommon.h"
#include "logger.h"

namespace kidsnow {

GLContext::GLContext() {};
GLContext::~GLContext() {};

bool GLContext::Initialize()
{
	gladLoadGL();
	glClearColor(0.4f, 0.4f, 1.0f, 1.0f); // CYAN
	glEnable(GL_DEPTH_TEST);
	return true;
}

void GLContext::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

} // end of kidsnow