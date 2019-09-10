#pragma once

#include "parser.h"

namespace kidsnow {

class WavefrontParser : public Parser {
public:
	WavefrontParser() {}

public:
	virtual Mesh* parse(const char* fileName, Mesh* mesh);

private:
	inline int strequal(const char *s1, const char *s2);
	inline int contains(const char *haystack, const char *needle);
};

}