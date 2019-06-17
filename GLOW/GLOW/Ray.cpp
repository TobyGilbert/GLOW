#include "Ray.h"

Ray::Ray()
{

}

Ray::~Ray()
{

}

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	m_origin = _origin; 
	m_direction = normalize(_direction);
}

