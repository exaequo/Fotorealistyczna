#include "stdafx.h"

Ray::Ray():Ray(Vector3::zero, Vector3::zero)
{
    //ctor
}
Ray::Ray(Vector3 origin, Vector3 direction)
{
    this->direction = direction;
    this->direction.normalize();
    this->origin = origin;
}

Ray::~Ray()
{
    //dtor
}
Vector3& Ray::Origin(){
    return this->origin;
}
Vector3& Ray::Direction(){
    return this->direction;
}
