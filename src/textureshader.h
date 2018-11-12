#pragma once

#include "shader.h"

namespace kidsnow {

class TextureShader : public Shader
{
public:
	TextureShader();
	~TextureShader();

private:
	bool Initialize(const char*, const char*);
	virtual bool SetShaderParameters();

private:
	GLuint m_locMVPMatrix, m_locScale;
};

}
