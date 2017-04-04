// stdafx.cpp : source file that includes just the standard includes
// RayTracer.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


float& ClampSingle(float &x, const float min, const float max)
{
	if (x < min)
	{
		x = min;
	}
	else if (x > max)
	{
		x = max;
	}

	return x;
}

float DegreesToRadians(const float& degrees)
{
	return (static_cast<float>(degrees * M_PI) / 180.0f);
}

float RadiansToDegrees(const float& radians)
{
	return radians * 180.0f / static_cast<float>(M_PI);
}
