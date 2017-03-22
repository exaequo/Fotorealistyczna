#include "stdafx.h"
#include <math.h>

Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

Vector2::~Vector2(){}

const float Vector2::X(){
    return this->x;
}

void Vector2::setX(float value){
    this->x = value;
}

const float Vector2::Y(){
    return this->y;
}

void Vector2::setY(float value){
    this->y = value;
}
float Vector2::magnitude(){
    float result;
    result = sqrt(x*x + y*y);
    return result;
}
float Vector2::dot(Vector2 &l, Vector2 &r){
    return l.X()*r.X() + l.Y()*r.Y();
}

void Vector2::normalize(){
    float n = magnitude();
    if(n!=0){
        (*this)=(*this)/n;
    }
}
void Vector2::negate(){
    x = -x;
    y = -y;
}
std::ostream & operator<<(std::ostream & Str, Vector2 & v){
  Str <<"["<< v.X()<< ", "<< v.Y()<< "]";
  return Str;
}
//Vector2& Vector2::cross(const Vector2 &l, const Vector2 &r){
//    Vector2* result = new Vector2()
//
//
//
//    return *result;
//}
