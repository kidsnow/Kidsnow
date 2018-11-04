#pragma once

#ifdef _WIN32
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace kidsnow {

class SimpleShader;
class Model;

typedef struct {
    GLenum       type;
    const char*  filename;
    GLuint       shader;
} ShaderInfo;

class Renderer {
public:
    Renderer();
    ~Renderer();

public:
	bool Initialize(int width, int height);
    void Render();

private:
	SimpleShader* m_simpleShader;
	Model* m_model;

private:
	const float GRIDLENGTH = 100.0f;
	const int INDEX_VERTEX_POSITION = 0;
};

} // end of kidsnow
