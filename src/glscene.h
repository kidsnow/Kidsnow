#include "glcommon.h"
#include <vector>

namespace kidsnow {

class Camera;
class GLModel;

class GLScene
{
public:
	GLScene();
	~GLScene();

public:
	bool Initialize();
	void RegisterCamera(Camera* cam) { m_camera = cam; }
	void RegisterTarget(GLModel*);
	void Render();

private:
	void DrawTarget(GLModel*);

private:
	Camera *m_camera;
	glm::mat4x4 m_viewProjectionMatrix;
	std::vector<GLModel*> m_targets;
};

}