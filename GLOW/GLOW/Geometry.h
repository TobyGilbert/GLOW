#pragma once

#include "Ray.h"

class Geometry
{
public:
	virtual float intersect(const Ray& _ray, float _tMin, float _tMax) const = 0;
};

