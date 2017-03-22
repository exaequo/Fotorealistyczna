// stdafx.cpp : source file that includes just the standard includes
// RayTracer.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

float clamp01(float value)
{
	float result = value;
	if (result < 0) {
		result = 0;
	}
	if (result > 1) {
		result = 1;
	}
	return result;
}
