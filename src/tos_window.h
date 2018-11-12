#pragma once

#include "window.h"
#include <string>

namespace kidsnow {

	class Input;

	class TOSWindow : public Window {
	public:
		TOSWindow(std::string windowName, int width, int height);
		~TOSWindow();

	public:
		virtual bool Initialize();
		virtual void Update(Input*);
		virtual bool Finalize();

	public:
		inline int GetWidowWidth() { return m_width; }
		inline int GetWidowHeight() { return m_height; }
	};

} // end of kidsnoaw