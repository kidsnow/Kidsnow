#pragma once

class GLFWwindow;

namespace kidsnow {

class Input;

class Renderer {
public:
	Renderer() {};
	virtual ~Renderer() {};

public:
	virtual bool Initialize(GLFWwindow* window) = 0;
    virtual void Render(Input* input) = 0;
};

} // end of kidsnow
