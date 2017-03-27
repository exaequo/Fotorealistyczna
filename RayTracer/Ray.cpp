#include "stdafx.h"

Ray::Ray():Ray(Vector3::zero, Vector3::zero, 0)
{
    //ctor
}
Ray::Ray(Vector3 origin, Vector3 direction, float maxLength)
{
    this->direction = direction;
    this->direction.normalize();
    this->origin = origin;
	this->length = maxLength;
}

Ray::~Ray()
{
    //dtor
}
Vector3 Ray::Origin(){
    return this->origin;
}
Vector3 Ray::Direction(){
    return this->direction;
}

float Ray::Length()
{
	return this->length;
}

void Ray::Length(float value)
{
	length = value;
}

void Ray::reset(Vector3 origin, Vector3 direction, float maxLength)
{
	this->origin = origin;
	direction.normalize();
	this->direction = direction;
	length = maxLength;
	normalOfHit = Vector3::zero;
}
