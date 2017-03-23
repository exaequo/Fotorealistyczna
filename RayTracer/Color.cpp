#include "stdafx.h"

#include <math.h>
#include <iostream>

Color Color::black = Color(0, 0, 0);
Color Color::white = Color(1, 1, 1);
Color Color::blue = Color(0, 0, 1);
Color Color::red = Color(1, 0, 0);
Color Color::green = Color(0, 1, 0);
Color Color::yellow = Color(1, 1, 0);
Color Color::purple = Color(1, 0, 1);

Color::Color():Color(0,0,0){}

Color::Color(float r, float g, float b)
{
	this->r = clamp01(r);
	this->g = clamp01(g);
	this->b = clamp01(b);
}

Color::Color(float r, float g) : Color(r,g,0){}

Color::Color(float r) : Color(r, 0, 0) {}


Color::~Color()
{
}

float Color::R()
{
	return r;
}

void Color::R(float value)
{
	r = clamp01(value);
}

float Color::G()
{
	return g;
}

void Color::G(float value)
{
	g = clamp01(value);
}

float Color::B()
{
	return b;
}

void Color::B(float value)
{
	b = clamp01(value);
}

void Color::add(float R, float G, float B)
{
	this->R(r + R);
	this->G(g + G);
	this->B(b + B);
}

void Color::operator()(float R, float G, float B)
{
	this->R(R);
	this->G(G);
	this->B(B);
}

void Color::operator()(float R, float G)
{
	this->R(R);
	this->G(G);
	this->b = 0;
}

void Color::operator()(float R)
{
	this->R(R);
	this->g = 0;
	this->b = 0;
}

Color& Color::operator+(Color & li)
{
	return Color(r + li.R(), g + li.G(), b + li.B());
}

Color& Color::operator-(Color & li)
{
	return Color(r - li.R(), g - li.G(), b - li.B());
}

//Color& Color::operator/(float num)
//{
//	if (num != 0) {
//		return Color(r / num, g / num, b / num);
//	}
//	else {
//		return Color(1, 1, 1);
//		std::cout << "Dividin light intensity by 0\n";
//	}
//}

Color & Color::operator+=(Color & li)
{
	this->R(r + li.R());
	this->G(g + li.G());
	this->B(b + li.B());
	return *this;
}

Color & Color::operator-=(Color & li)
{
	this->R(r - li.R());
	this->G(g - li.G());
	this->B(b - li.B());
	return *this;
}

Color & Color::operator*=(float num)
{
	this->R(r * num);
	this->G(g * num);
	this->B(b * num);
	return *this;
}

Color & Color::operator/=(float num)
{
	if (num != 0) {
		this->R(r / num);
		this->G(g / num);
		this->B(b / num);
	}
	else {
		r = 1;
		g = 1;
		b = 1;
	}
	return *this;
}

Color & Color::operator=(Color & c)
{
	r = c.R();
	g = c.G();
	b = c.B();
	return *this;
}

Color & operator*(float num, Color & li)
{
	return *(new Color(li.R() * num, li.G() * num, li.B() * num));
}

Color & operator*(Color & li, float num)
{
	return *(new Color(li.R() * num, li.G() * num, li.B() * num));
}

Color & operator/(float num, Color & li)
{
	return *(new Color(li.R() / num, li.G() / num, li.B() / num));
}

Color & operator/(Color & li, float num)
{
	return *(new Color(li.R() / num, li.G() / num, li.B() / num));
}

std::ostream & operator<<(std::ostream & str, Color & li)
{
	str << "(R:" << li.R() << ", G:" << li.G() << ", B:" << li.B() << ")";
	return str;
}
