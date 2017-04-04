#include "stdafx.h"
#include "Ray.h"
#include <iostream>
#include<vector>


Ray::Ray() :
	origin(Vector3::zero),
	direction(Vector3::zero),
	destination(Vector3::zero),
	distance(0.0f),
	clippingValue(100000.0f)
{ }


Ray::Ray(const Vector3& origin, const Vector3& direction) :
	origin(origin), direction(direction),
	destination(Vector3::zero),
	normalInDestinationPoint(Vector3::zero),
	distance(0.0f),
	clippingValue(100000.0f)
{
	this->direction.Normalize();
}

Ray::~Ray()
{ }

std::ostream & operator<<(std::ostream &os, const Ray &value)
{
	os << "Ray - " << "origin: " << value.origin << ", direction: " << value.direction << std::endl;

	return os;
}
