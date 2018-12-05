#pragma once

#include "window.h"

namespace kidsnow {

enum class SupportedAPI;

class WindowFactory {
public:
	WindowFactory() {};
	~WindowFactory() {};

public:
	Window* GetWindow(std::string, int, int, SupportedAPI);
};

} // end of kidsnoaw