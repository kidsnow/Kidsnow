#pragma once

namespace kidsnow {

class Mesh;

class Parser {
public:
	Parser() {}

public:
	virtual Mesh* Parse(const char* fileName, Mesh* mesh) = 0;

protected:
	static constexpr unsigned int OBJ_LINE_SIZE = 1000;
	static constexpr char *WHITESPACE = " \t\n\r";
};

}