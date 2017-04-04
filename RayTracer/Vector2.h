#pragma once
#include <iostream>
#include <cmath>

class Vector2
{
public:
#pragma region Static & Const
	const float epsilon = 1E-05F;
	static Vector2 down;
	static Vector2 left;
	static Vector2 right;
	static Vector2 up;
	static Vector2 zero;
	static Vector2 one;

	static double Angle(Vector2 &from, Vector2 &to);
	static float Distance(Vector2 &from, Vector2 &to);
	static float Dot(Vector2 &a, Vector2 &b);
	static float Magnitude(Vector2 &value);
	static float SqrMagnitude(Vector2 &value);
	static Vector2 Normalize(Vector2 &value);
#pragma endregion Static & Const

#pragma region Member Functions & Constructors
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2 &value);
	~Vector2();

	double Angle(Vector2 &rhs);
	float Distance(Vector2 &rhs);
	float Magnitude();
	float SqrMagnitude();
	float Dot(Vector2 &rhs);
	void Normalize();
	Vector2 Normalized();
	void Scale(Vector2 scale);
	void Set(float new_x, float new_y);
#pragma endregion Member Functions & Constructors

#pragma region Overloaded Operators
	Vector2& operator=(const Vector2 &rhs);
	Vector2& operator+=(const Vector2 &rhs);
	Vector2& operator-=(const Vector2 &rhs);
	Vector2 operator-() const;
	Vector2& operator*=(const Vector2 &rhs);
	Vector2& operator/=(const Vector2 &rhs);
	template<typename T>
	Vector2& operator*=(const T &rhs);
	template<typename T>
	Vector2& operator/=(const T &rhs);

	friend bool operator==(const Vector2 &lhs, const Vector2 &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Vector2 &value);
	friend std::istream &operator >> (std::istream &is, Vector2 &value);
	friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator*(const Vector2 &lhs, const Vector2 &rhs);
	friend Vector2 operator/(const Vector2 &lhs, const Vector2 &rhs);
	friend bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
	template<typename T>
	friend Vector2 operator*(const Vector2 &lhs, const T rhs);
	template<typename T>
	friend Vector2 operator*(const T lhs, const Vector2 &rhs);
	template<typename T>
	friend Vector2 operator/(const Vector2 &lhs, const T rhs);
#pragma endregion Overloaded Operators

#pragma region Getters & Setters
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
#pragma endregion Getters & Setters
private:
	float x;
	float y;
};