#pragma once

namespace kidsnow {

class Input;

class Renderer {
public:
	Renderer() {};
	~Renderer() {};

public:
	virtual bool Initialize(int width, int height) = 0;
    virtual void Render(Input* input) = 0;
};

} // end of kidsnow
