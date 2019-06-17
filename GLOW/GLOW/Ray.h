#pragma once

#include <glm/glm.hpp>

class Ray
{
public:
	Ray();
	~Ray();
	Ray(glm::vec3 _origin, glm::vec3 _direction);
	
	inline glm::vec3 getOrigin() const { return m_origin; }
	inline glm::vec3 getDirection() const { return m_direction; }
	inline glm::vec3 pointAtParameter(float t) const {return m_origin + t * m_direction;}

private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
};

	