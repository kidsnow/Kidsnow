#pragma once

#include <vector>
#include "glm/glm.hpp"

namespace kidsnow {

class Mesh {
public:
	Mesh();


private:
	// Vertex info.
	std::vector<glm::vec4> m_position;
	std::vector<glm::vec3> m_texture;
	std::vector<glm::vec3> m_normal;

	// Indices.
	std::vector<glm::uvec3> m_pFaces;
	std::vector<glm::uvec3> m_tFaces;
	std::vector<glm::uvec3> m_nFaces;
	std::vector<glm::uvec2> m_pLines;
	std::vector<glm::uvec2> m_tLines;
	std::vector<glm::uvec2> m_nLines;
	std::vector<glm::uint> m_pPoints;
	std::vector<glm::uint> m_tPoints;
	std::vector<glm::uint> m_nPoints;


public:
	inline void addPosition(glm::vec4 position) { m_position.push_back(position); }
	inline void addTexture(glm::vec3 texture) { m_texture.push_back(texture); }
	inline void addNormal(glm::vec3 normal) { m_normal.push_back(normal); }
	inline void addPositionToFace(glm::uvec3 position) { m_pFaces.push_back(position); }
	inline void addTextureToFace(glm::uvec3 texture) { m_tFaces.push_back(texture); }
	inline void addNormalToFace(glm::uvec3 normal) { m_nFaces.push_back(normal); }
	inline void addPositionToLine(glm::uvec2 position) { m_pLines.push_back(position); }
	inline void addTexureToLine(glm::uvec2 texture) { m_tLines.push_back(texture); }
	inline void addNormalToLine(glm::uvec2 normal) { m_nLines.push_back(normal); }
	inline void addPositionToPoint(glm::uint position) { m_pPoints.push_back(position); }
	inline void addTexureToPoint(glm::uint texture) { m_tPoints.push_back(texture); }
	inline void addNormalToPoint(glm::uint normal) { m_nPoints.push_back(normal); }
};

}