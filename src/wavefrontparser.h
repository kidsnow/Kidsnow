#pragma once

#include "parser.h"
#include <string.h>

namespace kidsnow {

class WavefrontParser : public Parser {
public:
	enum class INDEX_TYPE
	{
		P,
		PT,
		PN,
		PTN
	};

public:
	WavefrontParser() {}

public:
	virtual Mesh* Parse(const char *fileName, Mesh *mesh);

private:
	static constexpr unsigned int PREV = 0;
	static constexpr unsigned int CUR = 1;
	void Parseface_P(char *token, Mesh *mesh);
	void Parseface_PT(char *token, Mesh *mesh);
	void Parseface_PN(char *token, Mesh *mesh);
	void Parseface_PTN(char *token, Mesh *mesh);

private:
	inline INDEX_TYPE CheckIndexType(const char* token)
	{
		const char *tokentoken;

		if (contains(token, "//"))
		{
			return INDEX_TYPE::PN;
		}
		else if (contains(token, "/"))
		{
			tokentoken = strchr(token, '/');
			tokentoken++;
			if (contains(tokentoken, "/"))
			{
				return INDEX_TYPE::PTN;
			}
			return INDEX_TYPE::PT;
		}
		return INDEX_TYPE::P;
	}

	inline int strequal(const char *s1, const char *s2)
	{
		if (strcmp(s1, s2) == 0)
			return 1;
		return 0;
	}

	inline int contains(const char *haystack, const char *needle)
	{
		if (strstr(haystack, needle) == nullptr)
			return 0;
		return 1;
	}
};

}