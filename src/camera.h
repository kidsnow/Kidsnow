#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

namespace kidsnow {

class Camera
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	void setPosition(float, float, float);
	void setRotation(float, float, float);

	glm::vec4 getPosition();
	glm::vec4 getRotation();

	void setUp();
	glm::mat4x4 getViewProjectionMatrix();

private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	glm::mat4x4 m_viewMatrix, m_projectionMatrix;
};

}