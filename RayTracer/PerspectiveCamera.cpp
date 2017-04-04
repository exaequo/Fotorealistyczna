#include "stdafx.h"
#include "PerspectiveCamera.h"
#include "Vector2.h"
#include "AdaptiveSampler.h"


PerspectiveCamera::PerspectiveCamera()
{
}

PerspectiveCamera::PerspectiveCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const Vector3 &up,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, up, 0.01f, 1000.0f, 90.0f, width, height, sampler), viewPlaneOffset(0.0f)
{
	CalculateViewPlaneOffsetFromFoV();
}

PerspectiveCamera::PerspectiveCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const Vector3 &up,
	const float &nearPlane,
	const float &farPlane,
	const float &fov,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, up, nearPlane, farPlane, fov, width, height, sampler), viewPlaneOffset(0.0f)
{
	CalculateViewPlaneOffsetFromFoV();
}

PerspectiveCamera::~PerspectiveCamera()
{
}

void PerspectiveCamera::CalculateViewPlaneOffsetFromFoV()
{
	viewPlaneOffset = image.Width() / (2.0f * tan(DegreesToRadians(fov) * 0.5f));
}

void PerspectiveCamera::CalculateUVW()
{
	w = -(viewDirection.Normalized());
	u = -Vector3::Cross(up, w);
	u.Normalize();
	v = -Vector3::Cross(w, u);
}

void PerspectiveCamera::CalculateViewPlaneVectors()
{
	a = (static_cast<float>(image.Height()) - (-static_cast<float>(image.Height()))) * v;
	b = (static_cast<float>(image.Width()) - (-static_cast<float>(image.Width()))) * u;
	c = (-static_cast<float>(image.Height())) * v + (-static_cast<float>(image.Width())) * u - (viewPlaneOffset * w);
}

void PerspectiveCamera::RenderScene(vector<Primitive*> &primitives)
{
	Ray ray = Ray(Vector3::zero, Vector3::zero);
	Vector3 pointOnViewPlane = Vector3::zero;
	Vector3 rayDirection = Vector3::zero;

	CalculateUVW();
	CalculateViewPlaneVectors();

	float yToA = 0.0f;
	float xToB = 0.0f;

	for (size_t i = 0; i < image.Height(); ++i)
	{
		yToA = (i + 0.5f) / image.Height();
		for (size_t j = 0; j < image.Width(); ++j)
		{
			xToB = (j + 0.5f) / image.Width();
			Vector2 centerOfPixel = Vector2(xToB, yToA);


			if (sampler)
			{
				image.SetPixel(
					i,
					j,
					sampler->AdaptiveAntiAliasing(
						this,
						primitives,
						centerOfPixel,
						i,
						j,
						1,
						Color::undefined,
						Color::undefined,
						Color::undefined,
						Color::undefined
						));
			}
			else
			{
				image.SetPixel(
					i,
					j,
					CalculateSingleSample(centerOfPixel, i, j, primitives)
					);
			}
		}
	}

	std::string filename = "scenePerspective.bmp";
	std::string error;
	image.SaveImage(filename, error);
}

Color PerspectiveCamera::CalculateSingleSample(const Vector2 &coord, const int &row, const int &column, vector<Primitive *> &primitives)
{
	Primitive* intersectedPrimitive = nullptr;
	Color L = Color::black;
	Vector3 pointOnViewPlane = c + (coord.Y() * a) + (coord.X() * b);

	float Xv = (static_cast<float>(column) - (0.5f * image.Width()) + pointOnViewPlane.X());
	float Yv = (static_cast<float>(row) - (0.5f * image.Height()) + pointOnViewPlane.Y());

	Vector3 rayDirection = Xv * u + Yv * v - viewPlaneOffset * w;
	rayDirection.Normalize();

	Ray ray = Ray(Vector3::zero, Vector3::zero);
	ray.Origin(position);
	ray.Direction(rayDirection);
	ray.ClippingValue(farPlane);

	for (auto it = primitives.begin(); it != primitives.end(); ++it)
	{
		if ((*it)->Intersect(ray))
		{
			intersectedPrimitive = (*it);
		}
	}
	if (intersectedPrimitive)
	{
		L += intersectedPrimitive->CurrentMaterial().ColorAmbient();
		intersectedPrimitive = nullptr;
	}

	delete intersectedPrimitive;
	return L;
}
