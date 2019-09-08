#pragma once

#include "renderer.h"
#include "glcommon.h"

namespace kidsnow {

class GLShader;

class GLRenderer : public Renderer
{
public:
	GLRenderer();
	~GLRenderer();

public:
	bool initialize();
	void render(Camera* camera);
	void resize(int w, int h);

private:
	GLShader* m_shader;

	GLfloat* m_rectangleVertices;
	GLuint m_rectangleVAO;
	GLuint m_texture;

private:
	const float GRIDLENGTH = 100.0f;
	const int INDEX_VERTEX_POSITION = 0;
};

} // end of kidsnow
