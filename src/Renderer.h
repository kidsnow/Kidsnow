#pragma once

#ifdef _WIN32
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

namespace kidsnow {

class Shader;

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

public:
    GLuint LoadShaders(ShaderInfo*);

private:
	Shader *m_simpleShader;
	Shader *m_textureShader;
	GLuint m_simpleShaderProgram, m_textureShaderProgram;
	GLuint m_locSimpleMVPMatrix, m_locTextureMVPMatrix;
	GLuint m_locPrimitiveColor, m_locScale;

	glm::mat4 m_simpleViewMatrix;
	glm::mat4 m_simpleProjectionMatrix;
	glm::mat4 m_simpleViewProjectionMatrix;

	glm::mat4 m_textureViewMatrix;
	glm::mat4 m_textureProjectionMatrix;
	glm::mat4 m_textureViewProjectionMatrix;

	GLuint m_axesVBO, m_axesVAO;

private:
	bool LoadWaveShaders();
	void InitializeMatrices(int width, int height);
	void LoadModels();

private:
	const float GRIDLENGTH = 100.0f;
	const int INDEX_VERTEX_POSITION = 0;
};

} // end of kidsnow
