#pragma once

#include "window.h"

namespace kidsnow {

enum class SupportedAPI;

class WindowFactory {
public:
	WindowFactory() {};
	~WindowFactory() {};

public:
	Window* getWindow(std::string, int, int, int, int, SupportedAPI);
};

} // end of kidsnoaw