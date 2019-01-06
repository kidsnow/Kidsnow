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

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	glm::vec4 GetPosition();
	glm::vec4 GetRotation();

	void Render();
	void GetViewMatrix(glm::mat4x4&);

private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	glm::mat4x4 m_viewMatrix;
};

}