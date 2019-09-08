#include "application.h"

int main(void)
{
    kidsnow::Application* app = new kidsnow::Application("Hello", 100, 100, 1440, 810);
	
	if (!app->initialize())
		return 0;

    app->run();
    
	delete app;

    return 0;
}
