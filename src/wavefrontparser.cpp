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
			char* tokentoken;
			glm::vec3 pos, tex, nor;
			int curidx = 0;
			
			// - When # of points accumulated is more than 2,
			//     generate face for every incoming index.
			// - If there's more than 3 points, faces are accumulated like this...
			//     1 2 3, 1 3 4, 1 4 5, 1 5 6, ...

			token = strtok(nullptr, WHITESPACE);
			INDEX_TYPE indextype = checkIndexType(token);
			switch (indextype)
			{
			case INDEX_TYPE::P:
				parseface_P(token, mesh);
				break;
			case INDEX_TYPE::PT:
				parseface_PT(token, mesh);
				break;
			case INDEX_TYPE::PN:
				parseface_PN(token, mesh);
				break;
			case INDEX_TYPE::PTN:
				parseface_PTN(token, mesh);
				break;
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

void WavefrontParser::parseface_P(char *token, Mesh *mesh)
{
	int curidx = 0;
	int firstP = atoi(token);
	int recentP[2];

	while ((token = strtok(nullptr, WHITESPACE)) != nullptr)
	{
		curidx++;
		recentP[PREV] = recentP[CUR];
		recentP[CUR] = atoi(token);
		if (curidx > 1)
			mesh->addPositionToFace(glm::uvec3(firstP, recentP[PREV], recentP[CUR]));
	}
}

void WavefrontParser::parseface_PT(char *token, Mesh *mesh)
{
	int curidx = 0;
	int firstP = atoi(token);
	const char *tokentoken = strchr(token, '/') + 1;
	int firstT = atoi(tokentoken);
	int recentP[2], recentT[2];

	while ((token = strtok(nullptr, WHITESPACE)) != nullptr)
	{
		curidx++;

		recentP[PREV] = recentP[CUR];
		recentP[CUR] = atoi(token);

		tokentoken = strchr(token, '/') + 1;
		recentT[PREV] = recentT[CUR];
		recentT[CUR] = atoi(tokentoken);

		if (curidx > 1)
		{
			mesh->addPositionToFace(glm::uvec3(firstP, recentP[PREV], recentP[CUR]));
			mesh->addTextureToFace(glm::uvec3(firstT, recentT[PREV], recentT[CUR]));
		}
	}
}

void WavefrontParser::parseface_PN(char *token, Mesh *mesh)
{
	int curidx = 0;
	int firstP = atoi(token);
	const char *tokentoken = strchr(token, '/') + 2;
	int firstN = atoi(tokentoken);
	int recentP[2], recentN[2];

	while ((token = strtok(nullptr, WHITESPACE)) != nullptr)
	{
		curidx++;

		recentP[PREV] = recentP[CUR];
		recentP[CUR] = atoi(token);

		tokentoken = strchr(token, '/') + 2;
		recentN[PREV] = recentN[CUR];
		recentN[CUR] = atoi(tokentoken);

		if (curidx > 1)
		{
			mesh->addPositionToFace(glm::uvec3(firstP, recentP[PREV], recentP[CUR]));
			mesh->addNormalToFace(glm::uvec3(firstN, recentN[PREV], recentN[CUR]));
		}
	}
}

void WavefrontParser::parseface_PTN(char *token, Mesh *mesh)
{
	int curidx = 0;
	int firstP = atoi(token);
	const char *tokentoken = strchr(token, '/') + 1;
	int firstT = atoi(tokentoken);
	tokentoken = strchr(tokentoken, '/') + 1;
	int firstN = atoi(tokentoken);
	int recentP[2], recentT[2], recentN[2];

	while ((token = strtok(nullptr, WHITESPACE)) != nullptr)
	{
		curidx++;

		recentP[PREV] = recentP[CUR];
		recentP[CUR] = atoi(token);

		tokentoken = strchr(token, '/') + 1;
		recentT[PREV] = recentT[CUR];
		recentT[CUR] = atoi(tokentoken);

		tokentoken = strchr(tokentoken, '/') + 1;
		recentN[PREV] = recentN[CUR];
		recentN[CUR] = atoi(tokentoken);

		if (curidx > 1)
		{
			mesh->addPositionToFace(glm::uvec3(firstP, recentP[PREV], recentP[CUR]));
			mesh->addTextureToFace(glm::uvec3(firstT, recentT[PREV], recentT[CUR]));
			mesh->addNormalToFace(glm::uvec3(firstN, recentN[PREV], recentN[CUR]));
		}
	}
}

}