#include "renderer.h"
#include "helper.h"

#include "shader.h"

namespace kidsnow {

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

bool Renderer::LoadWaveShaders()
{

	ShaderInfo shader_info[3] = {
		{ GL_VERTEX_SHADER, "../../../src/resource/simple.vert" },
		{ GL_FRAGMENT_SHADER, "../../../src/resource/simple.frag" },
		{ GL_NONE, NULL }
	};

	m_simpleShaderProgram = LoadShaders(shader_info);
	if (m_simpleShaderProgram == 0)
		return false;

	m_locSimpleMVPMatrix = glGetUniformLocation(m_simpleShaderProgram, "u_ModelViewProjectionMatrix");
	m_locPrimitiveColor = glGetUniformLocation(m_simpleShaderProgram, "u_primitive_color");

	ShaderInfo cs_shader_info[2] = {
		{ GL_COMPUTE_SHADER, "../../../src/resource/wecs.comp" },
		{ GL_NONE, NULL }
	};

	ShaderInfo shader_info_texture[3] = {
		{ GL_VERTEX_SHADER, "../../../src/resource/texture.vert" },
		{ GL_FRAGMENT_SHADER, "../../../src/resource/texture.frag" },
		{ GL_NONE, NULL }
	};

	m_textureShaderProgram = LoadShaders(shader_info_texture);
	if (m_textureShaderProgram == 0)
		return false;
	m_locTextureMVPMatrix = glGetUniformLocation(m_textureShaderProgram, "u_ModelViewProjectionMatrix");
	m_locScale = glGetUniformLocation(m_textureShaderProgram, "u_scale");

	return true;
}

void Renderer::InitializeMatrices(int width, int height)
{
	float aspectRatio = (float)(width/height);
	m_simpleViewMatrix = glm::lookAt(glm::vec3(200.0f, 100.0f, 200.0f), glm::vec3(GRIDLENGTH / 2, 0.0f, GRIDLENGTH / 2),
		glm::vec3(0.0f, 1.0f, 0.0f));
	m_simpleProjectionMatrix = glm::perspective(15.0f*0.01745329252f, aspectRatio, 1.0f, 1000.0f);
	m_simpleViewProjectionMatrix = m_simpleProjectionMatrix * m_simpleViewMatrix;

	m_textureViewMatrix = glm::lookAt(glm::vec3(48.4375f, 100.0f, 48.4375f), glm::vec3(48.4375f, 0.0f, 48.4375f),
		glm::vec3(-1.0f, 0.0f, 0.0f));
	m_textureProjectionMatrix = glm::ortho(-48.4375f, 48.4375f, -48.4375f, 48.4375f);
	m_textureProjectionMatrix[2][2] = 0.0;
	m_textureViewProjectionMatrix = m_textureProjectionMatrix * m_textureViewMatrix;
}

void Renderer::LoadModels()
{
	GLfloat axesVertices[6][3] = {
		{ 0.0f, 0.0f, 0.0f },{ 1.0f, 0.0f, 0.0f },{ 0.0f, 0.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },{ 0.0f, 0.0f, 1.0f }
	};

	// Initialize vertex buffer object.
	glGenBuffers(1, &m_axesVBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_axesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axesVertices), &axesVertices[0][0], GL_STATIC_DRAW);

	// Initialize vertex array object.
	glGenVertexArrays(1, &m_axesVAO);
	glBindVertexArray(m_axesVAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_axesVBO);
	glVertexAttribPointer(INDEX_VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
	glEnableVertexAttribArray(INDEX_VERTEX_POSITION);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

bool Renderer::Initialize(int width, int height)
{
	GLint result = glewInit();
	if (GLEW_OK != result)
	{
		LogDebug("%s", glewGetErrorString(result));
		exit(EXIT_FAILURE);
	}

	glClearColor(0.4f, 0.4f, 1.0f, 1.0f); // CYAN
	glEnable(GL_DEPTH_TEST);

	m_simpleShader = new Shader();
	if (!m_simpleShader->Initialize("../../../src/resource/simple.vert", "../../../src/resource/simple.frag")) return false;
	m_textureShader = new Shader();
	if (!m_textureShader->Initialize("../../../src/resource/texture.vert", "../../../src/resource/texture.frag")) return false;

	InitializeMatrices(width, height);

	LoadModels();

	return true;
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_simpleShaderProgram);

	glm::mat4 modelViewProjectionMatrix = m_simpleViewProjectionMatrix;
	glUniformMatrix4fv(m_locSimpleMVPMatrix, 1, GL_FALSE, &modelViewProjectionMatrix[0][0]);

	GLfloat axesColor[3][3] = { { 1.0f, 0.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 0.0f, 0.0f, 1.0f } };
	glBindVertexArray(m_axesVAO);
	glUniform3fv(m_locPrimitiveColor, 1, axesColor[0]);
	glDrawArrays(GL_LINES, 0, 2);
	glUniform3fv(m_locPrimitiveColor, 1, axesColor[1]);
	glDrawArrays(GL_LINES, 2, 2);
	glUniform3fv(m_locPrimitiveColor, 1, axesColor[2]);
	glDrawArrays(GL_LINES, 4, 2);
	glBindVertexArray(0);
}

GLchar* ReadShader(const char* filename) {

	FILE* infile = fopen(filename, "rb");

	if (!infile) {
		LogDebug("Unable to open file '%s'", filename);
		return NULL;
	}

	fseek(infile, 0, SEEK_END);
	int len = ftell(infile);
	fseek(infile, 0, SEEK_SET);

	GLchar* source = (GLchar*)malloc((len + 1) * sizeof(GLchar));

	fread(source, 1, len, infile);
	fclose(infile);

	source[len] = 0;

	return source;
}

GLuint Renderer::LoadShaders(ShaderInfo* shaders) {
	if (shaders == NULL) { return 0; }

	GLuint program = glCreateProgram();
    if (program == NULL)
    {
        LogDebug("Failed to create program object.");
        return 0;
    }

	ShaderInfo* entry = shaders;
	while (entry->type != GL_NONE) {
		GLuint shader = glCreateShader(entry->type);
        if (shader == NULL)
        {
            LogDebug("Failed to create shader object.");
            return 0;
        }

		entry->shader = shader;

		GLchar* source = ReadShader(entry->filename);
		if (source == NULL) {
			for (entry = shaders; entry->type != GL_NONE; ++entry) {
				glDeleteShader(entry->shader);
				entry->shader = 0;
			}

			return 0;
		}

		glShaderSource(shader, 1, &source, NULL);
		free(source);

		glCompileShader(shader);

		GLint compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
#ifdef _DEBUG
			GLsizei len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

			GLchar* log = (GLchar*)malloc((len + 1) * sizeof(GLchar));
			glGetShaderInfoLog(shader, len, &len, log);
			LogDebug("Shader compilation failed: %s", log);
			free(log);
#endif /* DEBUG */

			return 0;
		}

		glAttachShader(program, shader);

		++entry;
	}

	glLinkProgram(program);

	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
#ifdef _DEBUG
		GLsizei len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

		GLchar* log = (GLchar*)malloc((len + 1) * sizeof(GLchar));
		glGetProgramInfoLog(program, len, &len, log);
		LogDebug("Shader linking failed: %s", log);
		free(log);
#endif /* DEBUG */

		for (entry = shaders; entry->type != GL_NONE; ++entry) {
			glDeleteShader(entry->shader);
			entry->shader = 0;
		}

		return 0;
	}

	return program;
}

} // end of kidsnow
