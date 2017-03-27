#include "stdafx.h"
#include "PerspectiveCamera.h"
#include <math.h>

PerspectiveCamera::PerspectiveCamera():Camera(){}

PerspectiveCamera::PerspectiveCamera(int width, int height): PerspectiveCamera(width, height, 45, Vector3::zero, Vector3::forward, 0, 10000){}

PerspectiveCamera::PerspectiveCamera(int width, int height, Vector3 & position, Vector3 & direction) : PerspectiveCamera(width, height, 45, position, direction, 0, 10000){}

PerspectiveCamera::PerspectiveCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far) : PerspectiveCamera(width, height, 45, position, direction, near, far){}

PerspectiveCamera::PerspectiveCamera(int width, int height, float fov, Vector3 & position, Vector3 & direction, float near, float far) : Camera(width, height, position, direction, near, far) 
{
	this->fov = fov;
	calculateViewPlane();
	calculateUVW();
}

void PerspectiveCamera::calculateViewPlane()
{
	viewPlaneDistance = image.Width() / (2.0f * tan(static_cast<float>(fov * M_PI) / 180.0f * 0.5f));
}

void PerspectiveCamera::calculateUVW()
{
	w = -(direction.normalized());
	u = Vector3::cross(Vector3::up, w);
	u = -(u / u.magnitude());
	v = -Vector3::cross(w, u);
}

void PerspectiveCamera::render(std::vector<SceneObject*>& objectsToRender)
{
	Ray ray;
	Vector3 point;
	
	Vector3 a = (static_cast<float>(image.Height()) - (-static_cast<float>(image.Height()))) * v;
	Vector3 b = (static_cast<float>(image.Width()) - (-static_cast<float>(image.Width()))) * u;
	Vector3 c = (-static_cast<float>(image.Height())) * v + (-static_cast<float>(image.Width())) * u - (viewPlaneDistance * w);

	float xToA = 0.0f;
	float yToB = 0.0f;
	Vector3 pointOnViewPlane = Vector3::zero;

	for (size_t i = 0; i < image.Height(); ++i)
	{
		xToA = (i + 0.5f) / image.Height();
		for (size_t j = 0; j < image.Width(); ++j)
		{
			yToB = (j + 0.5f) / image.Width();
			pointOnViewPlane = c + (a * xToA) + (b * yToB);

			float Xv = (static_cast<float>(j) - (image.Width() * 0.5f) + pointOnViewPlane.X());
			float Yv = (static_cast<float>(i) - (image.Height() * 0.5f) + pointOnViewPlane.Y());

			Vector3 directionRay = u * Xv + v * Yv - viewPlaneDistance * w;
			directionRay.normalize();

			ray.reset(position, directionRay, farPlane);
			
			for (auto it = objectsToRender.begin(); it != objectsToRender.end(); ++it)
			{
				if ((*it)->checkIntersection(ray, point))
				{
					image.SetPixel(i, j, (*it)->RenderMaterial().MaterialColor());
				}
			}
		}
	}

	std::string filename = "scenePerspective.bmp";
	std::string error;
	image.SaveImage(filename, error);
}

float PerspectiveCamera::Fov()
{
	return fov;
}

Vector3 PerspectiveCamera::W()
{
	return w;
}

Vector3 PerspectiveCamera::V()
{
	return v;
}

float PerspectiveCamera::ViewPlaneDistance()
{
	return viewPlaneDistance;
}

Vector3 PerspectiveCamera::U()
{
	return u;
}

