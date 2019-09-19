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
	inline void AddPosition(glm::vec4 position) { m_position.push_back(position); }
	inline void AddTexture(glm::vec3 texture) { m_texture.push_back(texture); }
	inline void AddNormal(glm::vec3 normal) { m_normal.push_back(normal); }
	inline void AddPositionToFace(glm::uvec3 position) { m_pFaces.push_back(position); }
	inline void AddTextureToFace(glm::uvec3 texture) { m_tFaces.push_back(texture); }
	inline void AddNormalToFace(glm::uvec3 normal) { m_nFaces.push_back(normal); }
	inline void AddPositionToLine(glm::uvec2 position) { m_pLines.push_back(position); }
	inline void AddTexureToLine(glm::uvec2 texture) { m_tLines.push_back(texture); }
	inline void AddNormalToLine(glm::uvec2 normal) { m_nLines.push_back(normal); }
	inline void AddPositionToPoint(glm::uint position) { m_pPoints.push_back(position); }
	inline void AddTexureToPoint(glm::uint texture) { m_tPoints.push_back(texture); }
	inline void AddNormalToPoint(glm::uint normal) { m_nPoints.push_back(normal); }
	inline void AddPosition(float x, float y, float z, float w = 1.0f) {
		m_position.push_back(glm::vec4(x, y, z, w));
	}
	inline void AddTexture(float u, float v = 0.0f, float w = 0.0f) {
		m_texture.push_back(glm::vec3(u, v, w));
	}
	inline void AddNormal(float i, float j, float k) {
		m_normal.push_back(glm::vec3(i, j, k));
	}
	inline void AddPositionToFace(unsigned int v1, unsigned int v2, unsigned int v3) {
		m_pFaces.push_back(glm::uvec3(v1, v2, v3));
	}
	inline void AddTextureToFace(unsigned int v1, unsigned int v2, unsigned int v3) {
		m_tFaces.push_back(glm::uvec3(v1, v2, v3));
	}
	inline void AddNormalToFace(unsigned int v1, unsigned int v2, unsigned int v3) {
		m_nFaces.push_back(glm::uvec3(v1, v2, v3));
	}
	inline void AddPositionToLine(unsigned int v1, unsigned int v2) {
		m_pLines.push_back(glm::uvec2(v1, v2));
	}
	inline void AddTexureToLine(unsigned int v1, unsigned int v2) {
		m_tLines.push_back(glm::uvec2(v1, v2));
	}
	inline void AddNormalToLine(unsigned int v1, unsigned int v2) {
		m_nLines.push_back(glm::uvec2(v1, v2));
	}
};

}