#include "tos_window.h"

/*
#include <stdio.h>

#define EGL_EGLEXT_PROTOTYPES 1
#define GL_GLEXT_PROTOTYPES 1

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <GL/gl.h>
#include <GL/glext.h>

#include <twk/views/widget/widget.h>
#include <twk/display/display_manager.h>
#include <twk/surface/default_surface_gl.h>
#include <tgk/core/SkColor.h>
#include <eventloop/event_loop.h>

#include "base/logging.h"

#include <pthread.h>

#include <twk/views/view.h>
#include <twk/views/widget/widget_delegate.h>
*/

#include <twk/views/widget/widget.h>

namespace kidsnow {

TOSWindow::TOSWindow(std::string windowName, int width, int height)
	: Window(windowName, width, height) {}

TOSWindow::~TOSWindow() {}

bool TOSWindow::Initialize()
{
    views::Widget* widget = new views::Widget();
    widget->init();

	return true;
}

void TOSWindow::Update(Input* input)
{

}

bool TOSWindow::Finalize()
{

	return true;
}

} // end of kidsnow
