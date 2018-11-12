#pragma once

namespace kidsnow {

class Context {
public:
	Context() {};
	~Context() {};

public:
	virtual bool Initialize() = 0;
	virtual void Render() = 0;
};

} // end of kidsnow