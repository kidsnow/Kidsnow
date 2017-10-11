#include "Renderer.h"

namespace kidsnow {

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::Render()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_CLOLOR_BUFFER_BIT);
}

}
