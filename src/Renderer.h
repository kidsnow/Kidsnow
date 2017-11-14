#pragma once

#include <GLFW/glfw3.h>

namespace kidsnow {

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
    void Render();

public:
    GLuint LoadShaders(ShaderInfo*);

};

} // end of kidsnow
