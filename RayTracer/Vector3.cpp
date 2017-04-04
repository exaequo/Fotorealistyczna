#include "stdafx.h"
#include "Vector3.h"

Vector3 Vector3::back = Vector3(0, 0, -1);
Vector3 Vector3::down = Vector3(0, -1, 0);
Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::left = Vector3(-1, 0, 0);
Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::one = Vector3(1, 1, 1);

Vector3::Vector3() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{ }

Vector3::Vector3(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{ }

Vector3::Vector3(int x, int y, int z) :
	x(static_cast<float>(x)),
	y(static_cast<float>(y)),
	z(static_cast<float>(z))
{ }

Vector3::Vector3(float x, float y) :
	x(x),
	y(y),
	z(0.0f)
{ }

Vector3::Vector3(const Vector3 &value) : x(value.x), y(value.y), z(value.z)
{ }

Vector3::~Vector3()
{ }

float Vector3::Magnitude()
{
	return sqrt(sqr(x) + sqr(y) + sqr(z));
}

float Vector3::Magnitude(Vector3 &value)
{
	return sqrt(sqr(value.x) + sqr(value.y) + sqr(value.z));
}

float Vector3::SqrMagnitude()
{
	return sqr(x) + sqr(y) + sqr(z);
}

float Vector3::SqrMagnitude(Vector3 &value)
{
	return sqr(value.x) + sqr(value.y) + sqr(value.z);
}

void Vector3::Normalize()
{
	float length = Magnitude();

	x /= length;
	y /= length;
	z /= length;
}

Vector3 Vector3::Normalize(Vector3 &value)
{
	float length = Magnitude(value);

	value.x /= length;
	value.y /= length;
	value.z /= length;

	return value;
}

Vector3 Vector3::Reflect(Vector3 &normal)
{
	Vector3 reflectedVector;
	reflectedVector = 2.0f * Dot(normal) * normal;
	reflectedVector -= *this;
	return reflectedVector;
}

Vector3 Vector3::Reflect(Vector3 &direction, Vector3 &normal)
{
	return Vector3((2.0f * Dot(direction, normal) * normal) - direction);
}

void Vector3::Reverse()
{
	x = -x;
	y = -y;
	z = -z;
}

Vector3 Vector3::Reverse(const Vector3 &value)
{
	Vector3 result = Vector3::zero;

	result.x = -value.x;
	result.y = -value.y;
	result.z = -value.z;

	return result;
}

Vector3 Vector3::Normalized()
{
	return Normalize(*this);
}

void Vector3::Scale(Vector3 scale)
{
	x *= scale.x;
	y *= scale.y;
	z *= scale.z;
}

void Vector3::Set(float new_x, float new_y, float new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

float Vector3::Angle(Vector3 &from, Vector3 &to)
{

	return RadiansToDegrees(acos(Dot(from, to) / (from.Magnitude() * to.Magnitude())));
}

float Vector3::Angle(Vector3 &rhs)
{
	return RadiansToDegrees(acos(Dot(rhs) / (Magnitude() * rhs.Magnitude())));
}

Vector3 Vector3::Cross(Vector3 &a, Vector3 &b)
{
	return Vector3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));
}

Vector3 Vector3::Cross(Vector3 &rhs)
{
	return Vector3((y * rhs.z - z * rhs.y), (z * rhs.x - x * rhs.z), (x * rhs.y - y * rhs.x));
}

float Vector3::Distance(Vector3 &from, Vector3 &to)
{
	return sqrt(sqr(from.x - to.x) + sqr(from.y - to.y) + sqr(from.z - to.z));
}

float Vector3::Distance(Vector3 &rhs)
{
	return sqrt(sqr(x - rhs.x) + sqr(y - rhs.y) + sqr(z - rhs.z));
}

float Vector3::Dot(Vector3 &a, Vector3 &b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

float Vector3::Dot(Vector3 &rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
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

Vector3 operator-(const Vector3 &lhs, const float &rhs)
{
	Vector3 result;

	result.X(lhs.X() - rhs);
	result.Y(lhs.Y() - rhs);
	result.Z(lhs.Z() - rhs);

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

std::istream & operator>>(std::istream &is, Vector3 &value)
{
	is >> value.x >> value.y >> value.z;

	return is;
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