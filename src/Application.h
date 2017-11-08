#pragma once

#include <string>
#include "Window.h"
#include "Renderer.h"

namespace kidsnow {

    class Application {
        public:
            Application(std::string appName, int width, int height);
            ~Application();

        public:
            bool Initialize();
            void Run();


        private:
            std::string m_appName;
            Window* m_window;
            Renderer* m_renderer;
    };

}
