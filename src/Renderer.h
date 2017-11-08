#pragma once

#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <glm/vec3.hpp>

namespace kidsnow {

    class Renderer {
        public:
            Renderer();
            ~Renderer();

        public:
            GLchar* LoadShader();
            void Render();

        private:

    };

}
