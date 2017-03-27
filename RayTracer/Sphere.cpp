#include "stdafx.h"
#include "math.h"
#include "iostream"

Sphere::Sphere()
{
    center = Vector3(0,0,0);
    radius = 0;
}

Sphere::~Sphere()
{
    //dtor
}
Sphere::Sphere(Vector3& center, float radius){
    this->center = center;
    this->radius = radius;
}

Sphere::Sphere(Vector3 & center, float radius, Material & material):Sphere(center,radius)
{
	this->mat = material;
}

const Vector3& Sphere::Center(){
    return center;
}
const float& Sphere::Radius(){
    return radius;
}

int Sphere::intersect(Ray& ray, Vector3& hitpoint){
    int result = IntersectType::MISS;
    Vector3 v = ray.Origin() - center;
    float b = -Vector3::dot(v, ray.Direction());
    float det = (b*b) - Vector3::dot(v,v) + radius*radius;
    if(det >= 0){
        det = sqrt(det);
        float i1 = b - det;
        float i2 = b + det;
        if(i2>0){
            if(i1<0){
                if(i2<ray.Length()){
                    ray.Length(i2);
                    result = IntersectType::INSIDE;
                }

            }else{
                if(i1<ray.Length()){
					ray.Length(i1);
                    result = IntersectType::HIT;
                }
            }
            hitpoint = ray.Origin() + ray.Direction() * ray.Length();
        }

    }

//with: A = Xd^2 + Yd^2 + Zd^2
//B = 2 * (Xd * (X0 - Xc) + Yd * (Y0 - Yc) + Zd * (Z0 - Zc))
//C = (X0 - Xc)^2 + (Y0 - Yc)^2 + (Z0 - Zc)^2 - Sr^2
//
//Note: If |Rd| = 1 (normalized), then A = 1. So we can compute Sr^2 once.
//So with A = 1, the solution of the quadratic equation is
//
//t0, t1 = (- B + (B^2 - 4*C)^1/2) / 2 where t0 is for (-) and t1 is for (+)

//    ray.direction.normalize();
//    float det =
    return result;
}
