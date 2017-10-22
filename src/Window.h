#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace kidsnow {

    class Window {
        public:
            Window(std::string windowName, int width, int height);
            ~Window();

        public:
            bool Initialize();
            void Update();
            inline bool Finalize() { return glfwWindowShouldClose(m_window); }

        public:
            bool isKeyPressed(unsigned int keycode) const;
            bool isMouseBtnPressed(unsigned int button) const;
            void getMousePosition(double& x, double& y) const;

        private:
            void Greetings();

        private:
            GLFWwindow* m_window;
            std::string m_windowName;
            int m_width;
            int m_height;
    };

}
