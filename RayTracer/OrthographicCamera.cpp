#include "stdafx.h"
#include "OrthographicCamera.h"
#include "AdaptiveSampler.h"


OrthographicCamera::OrthographicCamera() :
	Camera()
{
	CalculateAspectRatio();
}

OrthographicCamera::OrthographicCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const float &nearPlane,
	const float &farPlane,
	const float &fov,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, nearPlane, farPlane, fov, width, height, sampler), pixelScale(1.0f)
{
	CalculateAspectRatio();
}

OrthographicCamera::OrthographicCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const float &nearPlane,
	const float &farPlane,
	const float &fov,
	const unsigned int width,
	const unsigned int height,
	const float pixelScale,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, nearPlane, farPlane, fov, width, height, sampler), pixelScale(pixelScale)
{
	CalculateAspectRatio();
}

OrthographicCamera::OrthographicCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, width, height, sampler), pixelScale(1.0f)
{
	CalculateAspectRatio();
}

OrthographicCamera::OrthographicCamera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const unsigned int width,
	const unsigned int height,
	const float pixelScale,
	AdaptiveSampler *sampler) :
	Camera(position, lookAtPoint, width, height, sampler), pixelScale(pixelScale)
{
	CalculateAspectRatio();
}

OrthographicCamera::~OrthographicCamera()
{ }

void OrthographicCamera::RenderScene(vector<Primitive*> &primitives)
{
	Ray ray = Ray(Vector3::zero, Vector3::zero);

	float pixelCenterY = 0.0f, pixelCenterX = 0.0f;

	Color L = Color::black;
	Primitive *wskaznikNaKolor = nullptr;

	for (size_t i = 0; i < image.Height(); ++i)
	{
		for (size_t j = 0; j < image.Width(); j++)
		{
			Vector2 centerOfPixel = Vector2(((j + 0.5f) * (1.0f / image.Width())), ((i + 0.5f) * (1.0f / image.Height())));

			if (sampler)
			{
				image.SetPixel(i, j,
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
						Color::undefined)
					);
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

	std::string filename = "sceneOrthographic.bmp";
	std::string error;
	image.SaveImage(filename, error);
}

Color OrthographicCamera::CalculateSingleSample(const Vector2 &coord, const int &row, const int &column, vector<Primitive *> &primitives)
{
	Ray ray = Ray(Vector3::zero, Vector3::zero);
	Primitive *intersectedPrimitive = nullptr;
	Color L = Color::black;

	float pixelCenterY = 0.0f, pixelCenterX = 0.0f;

	pixelCenterY = pixelScale * ((-1.0f / yAspect) + (coord.Y() * 2.0f) / yAspect);
	pixelCenterX = pixelScale * ((-1.0f * xAspect) + (coord.X() * 2.0f) * xAspect);

	ray.Origin(Vector3(pixelCenterX, pixelCenterY, position.Z()));
	ray.Direction(viewDirection);
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

void OrthographicCamera::CalculateAspectRatio()
{
	if (aspectRatio > 1.0f)
	{
		xAspect = aspectRatio;
		yAspect = 1.0f;
	}
	else
	{
		xAspect = 1.0f;
		yAspect = aspectRatio;
	}

	pixelHeight = 2.0f / image.Height();
	pixelWidth = 2.0f / image.Width();
}
