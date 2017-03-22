#include "stdafx.h"
#include <math.h>
#include <string>
#include <sstream>

Vector3::Vector3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3::~Vector3(){}
const float Vector3::X(){
    return this->x;
}

void Vector3::setX(float value){
    this->x = value;
}
const float Vector3::Y(){
    return this->y;
}
void Vector3::setY(float value){
    this->y = value;
}
const float Vector3::Z(){
    return this->z;
}
void Vector3::setZ(float value){
    this->z = value;
}


float Vector3::magnitude(){
    float result;
    result = sqrt(x*x + y*y + z*z);
    return result;
}
float Vector3::distance(Vector3 &v1, Vector3 &v2) {
	return (v2 - v1).magnitude();
}
float Vector3::dot(Vector3 &l, Vector3 &r){
    return l.X()*r.X() + l.Y()*r.Y() + l.Z()*r.Z();
}
Vector3& Vector3::cross(Vector3 &a, Vector3 &b){
    Vector3* result = new Vector3(a.Y()*b.Z() - a.Z()*b.Y(), - a.X()*b.Z() + a.Z()*b.X(), a.X()*b.Y() - a.Y()*b.X());
    return *result;
}
void Vector3::normalize(){
    float n = magnitude();
    if(n!=0){
        (*this)=(*this)/n;
    }
}
Vector3 &Vector3::negate(){
    Vector3 *v = new Vector3(x,y,z);
    v->x = -x;
    v->y = -y;
    v->z = -z;
    return *v;
}

std::string Vector3::toString() {
    std::stringstream str;
    str <<"["<< X()<< ", "<< Y()<< ", "<< Z()<<"]";
    return str.str();
}
Vector3& Vector3::zero(){
    Vector3 &result = *(new Vector3(0,0,0));
    return result;
}
Vector3& Vector3::right(){
    Vector3 &result = *(new Vector3(1,0,0));
    return result;
}
Vector3& Vector3::forward(){
    Vector3 &result = *(new Vector3(0,0,1));
    return result;
}
Vector3& Vector3::up(){
    Vector3 &result = *(new Vector3(0,1,0));
    return result;
}

std::ostream & operator<<(std::ostream & Str, Vector3 & v){
  Str <<"["<< v.X()<< ", "<< v.Y()<< ", "<< v.Z()<<"]";
  return Str;
}

Vector3& Vector3::operator+=(Vector3& right)
{
	this->x += right.X();
	this->y += right.Y();
	this->z += right.Z();
	return *this;
}
Vector3& Vector3::operator-=(Vector3& right) {
	this->x -= right.X();
	this->y -= right.Y();
	this->z -= right.Z();
	return *this;
}
Vector3& Vector3::operator*=(Vector3& right) {
	this->x *= right.X();
	this->y *= right.Y();
	this->z *= right.Z();
	return *this;
}
Vector3& Vector3::operator/=(Vector3& right) {
	this->x /= right.X();
	this->y /= right.Y();
	this->z /= right.Z();
	return *this;
}

Vector3 operator+(Vector3& left, Vector3& right) {
	float x = left.X() + right.X();
	float y = left.Y() + right.Y();
	float z = left.Z() + right.Z();
	return Vector3(x, y, z);
}
Vector3 Vector3::operator-(Vector3& right) {
	float x = X() - right.X();
	float y = Y() - right.Y();
	float z = Z() - right.Z();
	return Vector3(x, y, z);
}
Vector3 Vector3::operator*(Vector3& right) {
	float x = X() * right.X();
	float y = Y() * right.Y();
	float z = Z() * right.Z();
	return Vector3(x, y, z);
}
Vector3& Vector3::operator/(Vector3& right) {
	float x, y, z;
	if (right.X() != 0) {
		x = X() / right.X();
	}
	else {
		x = INFINITY;
	}

	if (right.Y() != 0) {
		y = Y() / right.Y();
	}
	else {
		y = INFINITY;
	}
	if (right.Z() != 0) {
		z = Z() / right.Z();
	}
	else {
		z = INFINITY;
	}
	
	return *(new Vector3(x, y, z));
}

Vector3& Vector3::operator*(float value) {
	float x = X() * value;
	float y = Y() * value;
	float z = Z() * value;
	return *(new Vector3(x, y, z));
}
Vector3& Vector3::operator/(float value) {
	if (value != 0) {
		float x = X() / value;
		float y = Y() / value;
		float z = Z() / value;
		return *(new Vector3(x, y, z));
	}
	else {
		std::cout << "Dividing by zero\n";
		return *(new Vector3(INFINITY, INFINITY, INFINITY));
	}
}

bool Vector3::operator==(Vector3& right) {
	return (this->x == right.X() && this->y == right.Y() && this->z == right.Z());
}
bool Vector3::operator!=(Vector3& right) {
	return (this->x != right.X() && this->y != right.Y() && this->z != right.Z());
}
Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}
