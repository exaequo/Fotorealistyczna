#include "stdafx.h"
#include "AdaptiveSampler.h"


AdaptiveSampler::AdaptiveSampler() :
	minSamplesPerPixel(1),
	maxSamplesPerPixel(4),
	spatialContrast(0.05f)
{ }

AdaptiveSampler::AdaptiveSampler(const int maxSamplesPerPixel) :
	minSamplesPerPixel(1),
	maxSamplesPerPixel(maxSamplesPerPixel),
	spatialContrast(0.05f)
{ }

AdaptiveSampler::AdaptiveSampler(const int minSamplesPerPixel, const int maxSamplesPerPixel) :
	minSamplesPerPixel(minSamplesPerPixel),
	maxSamplesPerPixel(maxSamplesPerPixel),
	spatialContrast(0.05f)
{ }

AdaptiveSampler::AdaptiveSampler(const int minSamplesPerPixel, const int maxSamplesPerPixel, const float spatialContrast) :
	minSamplesPerPixel(minSamplesPerPixel),
	maxSamplesPerPixel(maxSamplesPerPixel),
	spatialContrast(spatialContrast)
{ }

AdaptiveSampler::AdaptiveSampler(const AdaptiveSampler& r)
{ }

AdaptiveSampler::~AdaptiveSampler()
{ }

bool AdaptiveSampler::CheckSpatialContrast(const Color &value)
{
	if (value.R() < spatialContrast && value.G() < spatialContrast && value.B() < spatialContrast)
	{
		//cout << value << endl;
		return true;
	}

	return false;
}

Color AdaptiveSampler::AdaptiveAntiAliasing(Camera *camera, vector<Primitive*> primitives, const Vector2 &center, const int &row, const int &column, int level, Color leftDown, Color leftUp, Color rightUp, Color rightDown)
{
	Color centerOfPixel = camera->CalculateSingleSample(center, row, column, primitives);
	float pixelWidthOffset = camera->image.HalfPixelWidth() / level;
	float pixelHeightOffset = camera->image.HalfpixelHeight() / static_cast<float>(level);

	//cout << pixelWidthOffset << endl;

	if (leftDown == Color::undefined)
	{
		leftDown = camera->CalculateSingleSample(Vector2(center.X() - pixelWidthOffset, center.Y() + pixelHeightOffset), row, column, primitives);
	}
	if (leftUp == Color::undefined)
	{
		leftUp = camera->CalculateSingleSample(Vector2(center.X() - pixelWidthOffset, center.Y() - pixelHeightOffset), row, column, primitives);
	}
	if (rightUp == Color::undefined)
	{
		rightUp = camera->CalculateSingleSample(Vector2(center.X() + pixelWidthOffset, center.Y() - pixelHeightOffset), row, column, primitives);
	}
	if (rightDown == Color::undefined)
	{
		rightDown = camera->CalculateSingleSample(Vector2(center.X() + pixelWidthOffset, center.Y() + pixelHeightOffset), row, column, primitives);
	}

	//cout << "Center: " << centerOfPixel << endl;
	//cout << "LD: " << leftDown << endl;
	//cout << "LU: " << leftUp << endl;
	//cout << "RU: " << rightUp << endl;
	//cout << "RD: " << rightDown << endl;

	Color resultOfPixelColor = Color::black;

	if (level == maxSamplesPerPixel)
	{
		//cout << "tutaj" << endl;
		return 0.25f * ((leftDown + centerOfPixel)* 0.5f + (leftUp + centerOfPixel)* 0.5f + (rightUp + centerOfPixel)* 0.5f + (rightDown + centerOfPixel)* 0.5f);
	}

	if (CheckSpatialContrast(leftDown - centerOfPixel))
	{
		resultOfPixelColor += (leftDown + centerOfPixel)* 0.5f;
	}
	else
	{
		Vector2 centerSubPixel = Vector2(center.X() - (pixelWidthOffset / 2.0f), center.Y() + (pixelHeightOffset / 2.0f));
		resultOfPixelColor += AdaptiveAntiAliasing(camera, primitives, centerSubPixel, row, column, level + 1, leftDown, Color::undefined, centerOfPixel, Color::undefined);
	}

	if (CheckSpatialContrast(leftUp - centerOfPixel))
	{
		resultOfPixelColor += (leftUp + centerOfPixel)* 0.5f;
	}
	else
	{
		Vector2 centerSubPixel = Vector2(center.X() - (pixelWidthOffset / 2.0f), center.Y() - (pixelHeightOffset / 2.0f));
		resultOfPixelColor += AdaptiveAntiAliasing(camera, primitives, centerSubPixel, row, column, level + 1, Color::undefined, leftUp, Color::undefined, centerOfPixel);
	}

	if (CheckSpatialContrast(rightUp - centerOfPixel))
	{
		resultOfPixelColor += (rightUp + centerOfPixel)* 0.5f;
	}
	else
	{
		Vector2 centerSubPixel = Vector2(center.X() + (pixelWidthOffset / 2.0f), center.Y() - (pixelHeightOffset / 2.0f));
		resultOfPixelColor += AdaptiveAntiAliasing(camera, primitives, centerSubPixel, row, column, level + 1, centerOfPixel, Color::undefined, rightUp, Color::undefined);
	}

	if (CheckSpatialContrast(rightDown - centerOfPixel))
	{
		resultOfPixelColor += (rightDown + centerOfPixel)* 0.5f;
	}
	else
	{
		Vector2 centerSubPixel = Vector2(center.X() + (pixelWidthOffset / 2.0f), center.Y() + (pixelHeightOffset / 2.0f));
		resultOfPixelColor += AdaptiveAntiAliasing(camera, primitives, centerSubPixel, row, column, level + 1, Color::undefined, centerOfPixel, Color::undefined, rightDown);
	}

	return 0.25f * resultOfPixelColor;
}

//Color AdaptiveSampler::CalculateSingleSample(PerspectiveCamera &camera, const Vector2 &coord, const int &row, const int &column, vector<Primitive*> &primitives)
//{
//	Primitive* intersectedPrimitive = nullptr;
//	Color L = Color::black;
//	Vector3 pointOnViewPlane = camera.c + (coord.Y() * camera.a) + (coord.X() * camera.b);
//
//	float Xv = (static_cast<float>(column) - (0.5f * camera.image.Width()) + pointOnViewPlane.X());
//	float Yv = (static_cast<float>(row) - (0.5f * camera.image.Height()) + pointOnViewPlane.Y());
//
//	Vector3 rayDirection = Xv * camera.u + Yv * camera.v - camera.viewPlaneOffset * camera.w;
//	rayDirection.Normalize();
//
//	Ray ray = Ray(Vector3::zero, Vector3::zero);
//	ray.Origin(camera.position);
//	ray.Direction(rayDirection);
//	ray.ClippingValue(camera.farPlane);
//
//	for (auto it = primitives.begin(); it != primitives.end(); ++it)
//	{
//		if ((*it)->Intersect(ray))
//		{
//			intersectedPrimitive = (*it);
//		}
//	}
//	if (intersectedPrimitive)
//	{
//		L += intersectedPrimitive->MaterialColor();
//		intersectedPrimitive = nullptr;
//	}
//
//	delete intersectedPrimitive;
//	return L;
//}

//Color AdaptiveSampler::CalculateSingleSample(OrthographicCamera &camera, const Vector2 &coord, const int &row, const int &column, vector<Primitive*> &primitives)
//{
//	return Color::black;
//}

AdaptiveSampler& AdaptiveSampler::operator=(const AdaptiveSampler& rhs)
{
	minSamplesPerPixel = rhs.MinSamplesPerPixel();
	maxSamplesPerPixel = rhs.MaxSamplesPerPixel();
	spatialContrast = rhs.SpatialContrast();

	return *this;
}

