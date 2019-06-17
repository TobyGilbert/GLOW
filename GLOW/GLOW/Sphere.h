#pragma once
#include <glm/glm.hpp>

#include "Geometry.h"

class Sphere : public Geometry
{
public:
	Sphere();
	Sphere(glm::vec3 _centre, float _radius) { m_centre = _centre; m_radius = _radius; }
	~Sphere();
	
	// Returns the closest hit distance
	float intersect(const Ray& _ray, float _tMin, float _tMax) const;
private:
	glm::vec3 m_centre;
	float m_radius;
};

