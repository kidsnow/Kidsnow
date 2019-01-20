#include "glscene.h"
#include "camera.h"
#include "glmodel.h"

namespace kidsnow {

GLScene::GLScene() {}

GLScene::~GLScene() {}

bool GLScene::Initialize() { return true; }

void GLScene::Render()
{
	for (auto iter = m_targets.begin(); iter != m_targets.end(); iter++)
	{
		DrawTarget(*iter);
	}
}

void GLScene::RegisterTarget(GLModel* target)
{
	m_targets.push_back(target);
}

void GLScene::DrawTarget(GLModel* target)
{
	m_viewProjectionMatrix = m_camera->GetViewProjectionMatrix();

	target->Render(m_viewProjectionMatrix);
}

}