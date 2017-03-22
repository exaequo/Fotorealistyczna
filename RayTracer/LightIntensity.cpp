#include "stdafx.h"
#include "LightIntensity.h"
#include <math.h>
#include <iostream>

LightIntensity::LightIntensity():LightIntensity(0,0,0){}

LightIntensity::LightIntensity(float r, float g, float b)
{
	this->r = clamp01(r);
	this->g = clamp01(g);
	this->b = clamp01(b);
}

LightIntensity::LightIntensity(float r, float g) : LightIntensity(r,g,0){}

LightIntensity::LightIntensity(float r) : LightIntensity(r, 0, 0) {}


LightIntensity::~LightIntensity()
{
}

float LightIntensity::R()
{
	return r;
}

void LightIntensity::R(float value)
{
	r = clamp01(value);
}

float LightIntensity::G()
{
	return g;
}

void LightIntensity::G(float value)
{
	g = clamp01(value);
}

float LightIntensity::B()
{
	return b;
}

void LightIntensity::B(float value)
{
	b = clamp01(value);
}

void LightIntensity::add(double R, double G, double B)
{
	this->R(r + R);
	this->G(g + G);
	this->B(b + B);
}

void LightIntensity::operator()(float R, float G, float B)
{
	this->R(R);
	this->G(G);
	this->B(B);
}

void LightIntensity::operator()(float R, float G)
{
	this->R(R);
	this->G(G);
	this->b = 0;
}

void LightIntensity::operator()(float R)
{
	this->R(R);
	this->g = 0;
	this->b = 0;
}

LightIntensity& LightIntensity::operator+(LightIntensity & li)
{
	return LightIntensity(r + li.R(), g + li.G(), b + li.B());
}

LightIntensity& LightIntensity::operator-(LightIntensity & li)
{
	return LightIntensity(r - li.R(), g - li.G(), b - li.B());
}

LightIntensity& LightIntensity::operator/(float num)
{
	if (num != 0) {
		return LightIntensity(r / num, g / num, b / num);
	}
	else {
		return LightIntensity(1, 1, 1);
		std::cout << "Dividin light intensity by 0\n";
	}
}

LightIntensity & LightIntensity::operator+=(LightIntensity & li)
{
	this->R(r + li.R());
	this->G(g + li.G());
	this->B(b + li.B());
	return *this;
}

LightIntensity & LightIntensity::operator-=(LightIntensity & li)
{
	this->R(r - li.R());
	this->G(g - li.G());
	this->B(b - li.B());
	return *this;
}

LightIntensity & LightIntensity::operator*=(float num)
{
	this->R(r * num);
	this->G(g * num);
	this->B(b * num);
	return *this;
}

LightIntensity & LightIntensity::operator/=(float num)
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

LightIntensity & operator*(float num, LightIntensity & li)
{
	return LightIntensity(li.R() * num, li.G() * num, li.B() * num);
}

LightIntensity & operator*(LightIntensity & li, float num)
{
	return LightIntensity(li.R() * num, li.G() * num, li.B() * num);
}

std::ostream & operator<<(std::ostream & str, LightIntensity & li)
{
	str << "(R:" << li.R() << ", G:" << li.G() << ", B:" << li.B() << ")";
	return str;
}
