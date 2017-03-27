#include "stdafx.h"

#include "Plane.h"
#include "Vector3.h"
#include <iostream>

Plane::Plane() : Plane(Vector3::zero, Vector3::right){}
Plane::Plane(Vector3 &point, Vector3 &normal){
    this->point = point;
    this->normal = normal;

    this->normal.normalize();

    dist = Vector3::dot(point, normal);
    std::cout<<"P: origin: "<<point<<", normal: "<<this->normal<<std::endl;
}

Plane::Plane(Vector3 & point, Vector3 & normal, Material & material) : Plane(point, normal)
{
	this->mat = material;
}

Plane::~Plane()
{
    //dtor
}
int Plane::intersect(Ray& ray, Vector3& hitpoint){
    int result = IntersectType::MISS;
    //float dot1 = (dist - Vector3::dot(normal, ray.Origin()));
	float dot1 = Vector3::dot(normal, point - ray.Origin());
    float dot2 = Vector3::dot(normal,ray.Direction());
    if(dot2 != 0){
        float t = dot1/dot2;
        if(t>=0){
            if(t<ray.Length()){
                result = IntersectType::HIT;
                //dist = t;
				ray.Length(t);
                hitpoint = ray.Origin() + ray.Direction() * t;
            }
            if(dot2>0){
                ray.normalOfHit = normal;
            }else{
				ray.normalOfHit = -normal;
            }
        }else{
            //Przeciecie przed punktem startu promienia
        }
    }else{
        //Wektory s¹ prostopad³e
    }

    return result;
}

float Plane::Distance(){
    return dist;
}
