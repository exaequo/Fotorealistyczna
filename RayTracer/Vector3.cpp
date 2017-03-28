#include "stdafx.h"
#include <math.h>
#include <string>
#include <sstream>

Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::left = Vector3(-1, 0, 0);
Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::back = Vector3(0, 0, -1);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::down = Vector3(0, -1, 0);

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
Vector3 Vector3::normalized()
{
	Vector3 result;
	float n = magnitude();
	if (n != 0) {
		result = (*this)/n;
	}
	return result;
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


Vector3& Vector3::operator=(const Vector3 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

Vector3& Vector3::operator/=(const Vector3 &rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

Vector3 Vector3::operator-() const
{
	Vector3 value;

	value.x = -x;
	value.y = -y;
	value.z = -z;

	return value;
}

Vector3& Vector3::operator+=(const Vector3 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
	Vector3 result = lhs;

	result += rhs;

	return result;
}

Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
	Vector3 result = lhs;

	result -= rhs;

	return result;
}

Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs)
{
	Vector3 result = lhs;

	result *= rhs;

	return result;
}

Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs)
{
	Vector3 result = lhs;

	result /= rhs;

	return result;
}

std::ostream & operator<<(std::ostream &os, const Vector3 &value)
{
	os << "(" << value.x << ", " << value.y << ", " << value.z << ")";

	return os;
}


bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
	bool result = false;
	if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
	{
		result = true;
	}

	return result;
}

bool operator!=(const Vector3 &lhs, const Vector3 &rhs)
{
	return !(lhs == rhs);
}

Vector3& Vector3::operator*=(const float &rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;
}

Vector3& Vector3::operator/=(const float &rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;
}

Vector3 operator*(const Vector3 &lhs, const float& rhs)
{
	Vector3 result = lhs;

	result *= rhs;

	return result;
}

Vector3 operator*(const float& lhs, const Vector3 &rhs)
{
	Vector3 result = rhs;

	result *= lhs;

	return result;
}

Vector3 operator/(const Vector3 &lhs, const float& rhs)
{
	Vector3 result = lhs;

	result /= rhs;

	return result;
}