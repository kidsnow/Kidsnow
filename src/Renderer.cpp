#include "Renderer.h"

namespace kidsnow {

    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    GLchar* Renderer::LoadShader()
    {
        return 0;
    }

    void Renderer::Render()
    {
        glClearColor(0.0, 1.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

}
