// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _USE_MATH_DEFINES
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include "Vector2.h"
#include "Vector3.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"
#include "Ray.h"
#include "Color.h"
#include "Material.h"
#include "Camera.h"
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "BMP.h"
#include "Image.h"


#include <iostream>
#include "fstream"
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#define EPSILON 0.000001f

float& ClampSingle(float &x, const float min, const float max);
float DegreesToRadians(const float& degrees);
float RadiansToDegrees(const float& radians);

template<typename T>
inline T sqr(T x)
{
	return (x * x);
}



// TODO: reference additional headers your program requires here
