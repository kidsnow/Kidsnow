#pragma once

#include "glshader.h"

namespace kidsnow {

class TextureGLShader : public GLShader
{
public:
	TextureGLShader();
	~TextureGLShader();

private:
	bool Initialize(const char*, const char*);
	virtual bool SetShaderParameters();

private:
	GLuint m_locMVPMatrix, m_locScale;
};

}
