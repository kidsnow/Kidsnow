#include "Application.h"

int main(void)
{
    kidsnow::Application* app = new kidsnow::Application("Hello", 640, 480);
    app->Initialize();
    app->Run();
    delete app;

    return 0;
}
