#pragma once

namespace kidsnow {

class GLContext {
public:
	GLContext();
	~GLContext();

public:
	bool Initialize();
	void Render();
};

} // end of kidsnow