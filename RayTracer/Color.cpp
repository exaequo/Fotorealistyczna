#include "stdafx.h"
#include "Color.h"

const float Color::CLAMPED_MIN = 0.0;

const float Color::CLAMPED_MAX = 1.0;

const int Color::UNCLAMPED_MIN = 0;

const int Color::UNCLAMPED_MAX = 255;

Color Color::black = Color(0, 0, 0);

Color Color::blue = Color(0, 0, 1);;

Color Color::clear = Color(0, 0, 0, 0);

Color Color::cyan = Color(0, 1, 1);

Color Color::gray = Color(0.5, 0.5, 0.5);

Color Color::green = Color(0, 1, 0);

Color Color::magenta = Color(1, 0, 1);

Color Color::red = Color(1, 0, 0);

Color Color::white = Color(1, 1, 1);

Color Color::yellow = Color(1, 1, 0);

Color Color::undefined = Color(-1, -1, -1, -1);

Color::Color() :
	r(0.0f),
	g(0.0f),
	b(0.0f),
	a(0.0f)
{ }

Color::Color(const Color &color) :
	r(color.r),
	g(color.g),
	b(color.b),
	a(color.a)
{ }

Color::Color(const float &r, const float& g, const float &b) :
	r(r),
	g(g),
	b(b),
	a(1.0f)
{ }

Color::Color(const float &r, const float& g, const float &b, const float &a) :
	r(r),
	g(g),
	b(b),
	a(a)
{ }

Color::~Color()
{ }

Color Color::GetGrayscale(const Color &color)
{
	Color result;
	float inversedThree = 1.0f / 3.0f;

	result.r = (color.r + color.g + color.b) * inversedThree;
	result.g = (color.r + color.g + color.b) * inversedThree;
	result.b = (color.r + color.g + color.b) * inversedThree;
	result.a = color.a;

	return result;
}

Color Color::GetGrayscale()
{
	Color result;
	float inversedThree = 1.0f / 3.0f;

	result.r = (r + g + b) * inversedThree;
	result.g = (r + g + b) * inversedThree;
	result.b = (r + g + b) * inversedThree;
	result.a = a;

	return result;
}

Color& Color::Clamp(Color &color)
{
	color.r = ClampSingle(color.r, CLAMPED_MIN, CLAMPED_MIN);
	color.g = ClampSingle(color.g, CLAMPED_MIN, CLAMPED_MAX);
	color.b = ClampSingle(color.b, CLAMPED_MIN, CLAMPED_MAX);
	color.a = ClampSingle(color.a, CLAMPED_MIN, CLAMPED_MAX);

	return color;
}

void Color::Clamp()
{
	r = ClampSingle(r, CLAMPED_MIN, CLAMPED_MIN);
	g = ClampSingle(g, CLAMPED_MIN, CLAMPED_MAX);
	b = ClampSingle(b, CLAMPED_MIN, CLAMPED_MAX);
	a = ClampSingle(a, CLAMPED_MIN, CLAMPED_MAX);
}

int Color::UnclampedR(const Color &color)
{
	return static_cast<int>(color.r * UNCLAMPED_MAX);
}

int Color::UnclampedR()
{
	return static_cast<int>(r * UNCLAMPED_MAX);
}

int Color::UnclampedG(const Color &color)
{
	return static_cast<int>(color.g * UNCLAMPED_MAX);
}

int Color::UnclampedG()
{
	return static_cast<int>(g * UNCLAMPED_MAX);
}

int Color::UnclampedB(const Color &color)
{
	return static_cast<int>(color.b * UNCLAMPED_MAX);
}

int Color::UnclampedB()
{
	return static_cast<int>(b * UNCLAMPED_MAX);
}

int Color::UnclampedA(const Color &color)
{
	return static_cast<int>(color.a * UNCLAMPED_MAX);
}

int Color::UnclampedA()
{
	return static_cast<int>(a * UNCLAMPED_MAX);
}

Color& Color::operator-=(const Color &rhs)
{
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;

	return *this;
}

Color& Color::operator/=(const Color &rhs)
{
	r /= rhs.r;
	g /= rhs.g;
	b /= rhs.b;

	return *this;
}

Color& Color::operator*=(const Color &rhs)
{
	r *= rhs.r;
	g *= rhs.g;
	b *= rhs.b;

	return *this;
}

Color& Color::operator+=(const Color &rhs)
{
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;

	return *this;
}

Color& Color::operator=(const Color &rhs)
{
	r = rhs.r;
	g = rhs.g;
	b = rhs.b;
	a = rhs.a;

	return *this;
}

//template<typename T>
Color& Color::operator*=(const float &rhs)
{
	r *= rhs;
	g *= rhs;
	b *= rhs;

	return *this;
}

//template<typename T>
Color& Color::operator/=(const float &rhs)
{
	r /= rhs;
	g /= rhs;
	b /= rhs;

	return *this;
}

//template<typename T>
Color operator/(const Color &lhs, const float &rhs)
{
	Color result = lhs;

	result /= rhs;

	return result;
}


//template<typename T>
Color operator*(const Color &lhs, const float &rhs)
{
	Color result = lhs;

	result *= rhs;

	return result;
}

//template<typename T>
Color operator*(const float &lhs, const Color &rhs)
{
	Color result = rhs;

	result *= lhs;

	return result;
}

bool operator==(const Color &lhs, const Color &rhs)
{
	bool result = false;
	if (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a)
	{
		result = true;
	}

	return result;
}

bool operator!=(const Color &lhs, const Color &rhs)
{
	return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Color &value)
{
	os << "(" << value.r << ", " << value.g << ", " << value.b << ", " << value.a << ")";

	return os;
}

std::istream &operator >> (std::istream &is, Color &value)
{
	is >> value.r >> value.g >> value.b >> value.a;

	return is;
}

Color operator+(const Color &lhs, const Color &rhs)
{
	Color result = lhs;

	result += rhs;

	return result;
}

Color operator-(const Color &lhs, const Color &rhs)
{
	Color result = lhs;

	result -= rhs;

	return result;
}

Color operator*(const Color &lhs, const Color &rhs)
{
	Color result = lhs;

	result *= rhs;

	return result;
}

Color operator/(const Color &lhs, const Color &rhs)
{
	Color result = lhs;

	result /= rhs;

	return result;
}