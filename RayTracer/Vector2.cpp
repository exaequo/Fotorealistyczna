#include "stdafx.h"
#include "Vector2.h"

Vector2 Vector2::down = Vector2(0, -1);
Vector2 Vector2::left = Vector2(-1, 0);
Vector2 Vector2::right = Vector2(1, 0);
Vector2 Vector2::up = Vector2(0, 1);
Vector2 Vector2::zero = Vector2(0, 0);
Vector2 Vector2::one = Vector2(1, 1);

Vector2::Vector2() :
	x(0.0f),
	y(0.0f)
{ }

Vector2::Vector2(float x, float y) :
	x(x),
	y(y)
{ }

Vector2::Vector2(const Vector2 &value) :
	x(value.x),
	y(value.y)
{ }

Vector2::~Vector2()
{ }

double Vector2::Angle(Vector2 &rhs)
{
	return acos(Dot(rhs) / (Magnitude() * rhs.Magnitude())) * 180.0f / M_PI;
}

double Vector2::Angle(Vector2 &from, Vector2 &to)
{
	return acos(Dot(from, to) / (from.Magnitude() * to.Magnitude())) * 180.0f / M_PI;
}

float Vector2::Distance(Vector2 &rhs)
{
	return sqrt(sqr(x - rhs.x) + sqr(y - rhs.y));
}

float Vector2::Distance(Vector2 &from, Vector2 &to)
{
	return sqrt(sqr(from.x - to.x) + sqr(from.y - to.y));
}

float Vector2::Dot(Vector2 &rhs)
{
	return ((x * rhs.x) + (y * rhs.y));
}

float Vector2::Dot(Vector2 &a, Vector2 &b)
{
	return ((a.x * b.x) + (a.y * b.y));
}

float Vector2::Magnitude()
{
	return sqrt(sqr(x) + sqr(y));
}

float Vector2::Magnitude(Vector2 &value)
{
	return sqrt(sqr(value.x) + sqr(value.y));
}

float Vector2::SqrMagnitude()
{
	return sqr(x) + sqr(y);
}

float Vector2::SqrMagnitude(Vector2 &value)
{
	return sqr(value.x) + sqr(value.y);
}

void Vector2::Normalize()
{
	float length = Magnitude();

	x /= length;
	y /= length;
}

Vector2 Vector2::Normalize(Vector2 &value)
{
	float length = Magnitude(value);

	value.x /= length;
	value.y /= length;

	return value;
}

Vector2 Vector2::Normalized()
{
	return Normalize(*this);
}

void Vector2::Scale(Vector2 scale)
{
	x *= scale.x;
	y *= scale.y;
}

void Vector2::Set(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
}

Vector2& Vector2::operator/=(const Vector2 &rhs)
{
	x /= rhs.x;
	y /= rhs.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2 Vector2::operator-() const
{
	Vector2 value;

	value.x = -x;
	value.y = -y;

	return value;
}

Vector2& Vector2::operator+=(const Vector2 &rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Vector2& Vector2::operator=(const Vector2 &rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
{
	Vector2 result = lhs;

	result += rhs;

	return result;
}

Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
{
	Vector2 result = lhs;

	result -= rhs;

	return result;
}

Vector2 operator*(const Vector2 &lhs, const Vector2 &rhs)
{
	Vector2 result = lhs;

	result *= rhs;

	return result;
}

Vector2 operator/(const Vector2 &lhs, const Vector2 &rhs)
{
	Vector2 result = lhs;

	result /= rhs;

	return result;
}

std::ostream & operator<<(std::ostream &os, const Vector2 &value)
{
	os << "(" << value.x << ", " << value.y << ")";

	return os;
}

std::istream & operator>>(std::istream &is, Vector2 &value)
{
	is >> value.x >> value.y;

	return is;
}

bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
	bool result = false;

	if (lhs.x == rhs.x && lhs.y == rhs.y)
	{
		result = true;
	}

	return result;

}

bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
	return !(lhs == rhs);
}

template<typename T>
Vector2& Vector2::operator/=(const T &rhs)
{
	x /= rhs;
	y /= rhs;

	return *this;
}

template<typename T>
Vector2& Vector2::operator*=(const T &rhs)
{
	x *= rhs;
	y *= rhs;

	return *this;
}

template<typename T>
Vector2 operator*(const Vector2 &lhs, const T rhs)
{
	Vector2 result = lhs;

	result *= rhs;

	return result;
}

template<typename T>
Vector2 operator*(const T lhs, const Vector2 &rhs)
{
	Vector2 result = rhs;

	result *= lhs;

	return result;
}

template<typename T>
Vector2 operator/(const Vector2 &lhs, const T rhs)
{
	Vector2 result = lhs;

	result /= rhs;

	return result;
}