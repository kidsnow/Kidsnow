#pragma once

namespace kidsnow {

class GLContext;
class Shader;
class Model;

class Renderer {
public:
    Renderer();
    ~Renderer();

public:
	bool Initialize(int width, int height);
    void Render();

private:
	GLContext* m_context;
	Shader* m_simpleShader;
	Model* m_model;

private:
	const float GRIDLENGTH = 100.0f;
	const int INDEX_VERTEX_POSITION = 0;
};

} // end of kidsnow
