#pragma once

#include "renderer.h"

namespace kidsnow {

class GLScene;
class Camera;
class GLShader;
class GLModel;

class GLRenderer : public Renderer
{
public:
	GLRenderer();
	~GLRenderer();

public:
	bool Initialize(int width, int height);
	void Render(Input* input);

private:
	GLScene* m_scene;
	GLShader* m_simpleShader;
	GLModel* m_model;
	Camera* m_camera;

private:
	const float GRIDLENGTH = 100.0f;
	const int INDEX_VERTEX_POSITION = 0;
};

} // end of kidsnow
