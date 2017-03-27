
#include "stdafx.h"
#include "Ray.h"

Primitive::Primitive()
{
}

Primitive::~Primitive()
{
    //dtor
}

bool Primitive::checkIntersection(Ray & ray, Vector3 & point)
{
	int result = intersect(ray, point);
	return result != 0;
}

