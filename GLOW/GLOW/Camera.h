#pragma once

#include <glm/glm.hpp>

#include "Ray.h"

class Camera
{

public:
	Camera(float _aspect) :
		m_lowerLeft(-1.0f * _aspect, -1.0f, -1.0f),
		m_horizontal(2.0f * _aspect, 0.0f, 0.0f),
		m_vertical(0.0f, 2.0f, 0.0f),
		m_origin(0.0f)
	{
	}

	virtual ~Camera() {};
	Ray getRay(float _u, float _v) { return Ray(m_origin, m_lowerLeft + _u * m_horizontal + _v * m_vertical - m_origin); }
private:
	glm::vec3 m_origin;
	glm::vec3 m_lowerLeft;
	glm::vec3 m_horizontal;
	glm::vec3 m_vertical;
};

