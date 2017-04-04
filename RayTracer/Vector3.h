#pragma once
#include <iostream>
#include <cmath>

class Vector3
{
public:
#pragma region Static & Const
	const float epsilon = 1E-05F;
	static Vector3 back;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 left;
	static Vector3 right;
	static Vector3 up;
	static Vector3 zero;
	static Vector3 one;

	static float Angle(Vector3 &from, Vector3 &to);
	static Vector3 Cross(Vector3 &a, Vector3 &b);
	static float Distance(Vector3 &from, Vector3 &to);
	static float Dot(Vector3 &a, Vector3 &b);
	static float Magnitude(Vector3 &value);
	static float SqrMagnitude(Vector3 &value);
	static Vector3 Normalize(Vector3 &value);
	static Vector3 Reflect(Vector3 &direction, Vector3 &normal);
	static Vector3 Reverse(const Vector3 &value);
#pragma endregion Static & Const

#pragma region Member Functions & Constructors
	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	Vector3(int x, int y, int z);
	Vector3(const Vector3 &value);
	~Vector3();

	float Angle(Vector3 &rhs);
	float Distance(Vector3 &rhs);
	float Magnitude();
	float SqrMagnitude();
	float Dot(Vector3 &rhs);
	Vector3 Cross(Vector3 &rhs);
	void Normalize();
	Vector3 Normalized();
	Vector3 Reflect(Vector3 &normal);
	void Reverse();
	void Scale(Vector3 scale);
	void Set(float new_x, float new_y, float new_z);
#pragma endregion Member Functions & Constructors

#pragma region Overloaded Operators
	Vector3& operator=(const Vector3 &rhs);
	Vector3& operator+=(const Vector3 &rhs);
	Vector3& operator-=(const Vector3 &rhs);
	Vector3 operator-() const;
	Vector3& operator*=(const Vector3 &rhs);
	Vector3& operator/=(const Vector3 &rhs);
	Vector3& operator*=(const float &rhs);
	Vector3& operator/=(const float &rhs);

	friend bool operator==(const Vector3 &lhs, const Vector3 &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Vector3 &value);
	friend std::istream &operator>>(std::istream &is, Vector3 &value);
#pragma endregion Overloaded Operators

#pragma region Getters & Setters
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
	float Z() const { return z; }
	void Z(float val) { z = val; }
#pragma endregion Getters & Setters
private:
	float x;
	float y;
	float z;
};

Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator-(const Vector3 &lhs, const float &rhs);
Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs);
bool operator!=(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator*(const Vector3 &lhs, const float &rhs);
Vector3 operator*(const float &lhs, const Vector3 &rhs);
Vector3 operator/(const Vector3 &lhs, const float &rhs);