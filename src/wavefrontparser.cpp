#include <stdio.h>

#include "glm/glm.hpp"

#include "wavefrontparser.h"
#include "mesh.h"

namespace kidsnow {

Mesh* WavefrontParser::parse(const char* fileName, Mesh* mesh)
{
	FILE* obj_file_stream;
	int current_material = -1;
	char *current_token = nullptr;
	char current_line[OBJ_LINE_SIZE];
	int line_number = 0;

	obj_file_stream = fopen(fileName, "r");
	if (obj_file_stream == 0)
	{
		printf("Error reading file: %s\n", fileName);
		return 0;
	}

	// Parser loop
	while (fgets(current_line, OBJ_LINE_SIZE, obj_file_stream))
	{
		current_token = strtok(current_line, WHITESPACE);
		line_number++;

		// Skip comments
		if (current_token == nullptr || current_token[0] == '#')
			continue;

		// Parse objects
		else if (strequal(current_token, "v")) // Vertex
		{
			float x, y, z, w;
			char *token;
			x = atof(strtok(nullptr, WHITESPACE));
			y = atof(strtok(nullptr, WHITESPACE));
			z = atof(strtok(nullptr, WHITESPACE));

			token = strtok(nullptr, WHITESPACE);
			if (token != nullptr)
				w = atof(token);
			else
				w = 1.0f;
			glm::vec4 position(x, y, z, w);
			mesh->addPosition(position);
		}

		else if (strequal(current_token, "vt")) // Texture
		{
			float u, v, w;
			char *token;
			u = atof(strtok(nullptr, WHITESPACE));

			token = strtok(nullptr, WHITESPACE);
			if (token != nullptr)
				v = atof(token);
			else
				v = 0.0f;
			token = strtok(nullptr, WHITESPACE);
			if (token != nullptr)
				w = atof(token);
			else
				w = 0.0f;
			glm::vec3 texture(u, v, w);
			mesh->addTexture(texture);
		}

		else if (strequal(current_token, "vn")) // Normal
		{
			float i, j, k;
			i = atof(strtok(nullptr, WHITESPACE));
			j = atof(strtok(nullptr, WHITESPACE));
			k = atof(strtok(nullptr, WHITESPACE));
			glm::vec3 normal(i, j, k);
			mesh->addNormal(normal);
		}

		else if (strequal(current_token, "f")) // Face
		{
			char* token;
			char* str;
			while ((token = strtok(nullptr, WHITESPACE)) != nullptr)
			{
				
				if (contains(token, "//")) // Position//Normal
				{
					str = strchr(token, '/');
				}
				else if (contains(token, "/")) // Position/Texture
				{
					if (contains(str, "/")) // Position/Texture/Normal
					{

					}
				}
			}
		}

		else if (strequal(current_token, "l")) // Line
		{
			// notimpl
		}

		else if (strequal(current_token, "p")) // Point
		{
			// notimpl
		}
	}
}

int WavefrontParser::strequal(const char *s1, const char *s2)
{
	if (strcmp(s1, s2) == 0)
		return 1;
	return 0;
}

int WavefrontParser::contains(const char *haystack, const char *needle)
{
	if (strstr(haystack, needle) == nullptr)
		return 0;
	return 1;
}

}