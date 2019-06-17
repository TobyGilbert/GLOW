#include "Sphere.h"

Sphere::Sphere()
{
	m_centre = glm::vec3(0.0f);
	m_radius = 1.0f;
}

Sphere::~Sphere()
{

}

float Sphere::intersect(const Ray& _ray, float _tMin, float _tMax) const
{
	glm::vec3 oc = _ray.getOrigin() - m_centre;
	float a = dot(_ray.getDirection(), _ray.getDirection());
	float b = 2.0f * dot(oc, _ray.getDirection());
	float c = dot(oc, oc) - m_radius * m_radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant > 0)
	{
		float temp = (-b - sqrt(discriminant)) / (2.0f * a);
		if (temp < _tMax && temp > _tMin)
		{
			return temp;
		}
		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < _tMax && temp > _tMin)
		{
			return temp;
		}
	}
	return std::numeric_limits<float>::max();

}