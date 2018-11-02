#include "application.h"

int main(void)
{
    kidsnow::Application* app = new kidsnow::Application("Hello", 640, 480);
	
	if (!app->Initialize())
		return 0;

    app->Run();
    
	delete app;

    return 0;
}
