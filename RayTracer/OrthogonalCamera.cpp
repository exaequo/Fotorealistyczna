#include "stdafx.h"
#include "OrthogonalCamera.h"
#include "Ray.h"


OrthogonalCamera::OrthogonalCamera() : Camera(){}

OrthogonalCamera::OrthogonalCamera(int width, int height) : Camera(width,height){}

OrthogonalCamera::OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction) : Camera(width, height, position, direction){}

OrthogonalCamera::OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far):Camera(width,height,position,direction,near,far){}

OrthogonalCamera::OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far, int scale, Sampler * sampler) : Camera(width, height, position, direction, near, far, sampler, scale) {}

OrthogonalCamera::~OrthogonalCamera(){}

void OrthogonalCamera::render(std::vector<SceneObject*> &objectsToRender)
{
	//Ray ray;
	//Vector3 point;

	//float pixelCenterY = 0.0f, pixelCenterX = 0.0f;

	//float pixelWidth = 2.0f / image.Height();
	//float pixelHeight = 2.0f / image.Width();

	//float xAspect = 0.0f;
	//float yAspect = 0.0f;
	//if (aspectRatio > 1)
	//{
	//	xAspect = aspectRatio;
	//	yAspect = 1.0f;
	//}
	//else
	//{
	//	xAspect = 1.0f;
	//	yAspect = aspectRatio;
	//}

	//for (size_t i = 0; i < image.Height(); ++i)
	//{
	//	pixelCenterY = ((-1.0f / yAspect) + ((i + 0.5f) * pixelWidth) / yAspect) * scale;

	//	for (size_t j = 0; j < image.Width(); j++)
	//	{
	//		pixelCenterX = ((-1.0f * xAspect) + ((j + 0.5f) * pixelHeight) * xAspect) * scale;

	//		ray.reset(Vector3(pixelCenterX, pixelCenterY, position.Z() + nearPlane), direction, farPlane);
	//		
	//		image.SetPixel(i, j, Camera::backgroundColor);

	//		//gdyby lista by³a posortowana to mo¿naby przerywaæ po znalezieniu przeciêcia
	//		for (auto it = objectsToRender.begin(); it != objectsToRender.end(); ++it)
	//		{
	//			if ((*it)->checkIntersection(ray, point))
	//			{
	//				image.SetPixel(i, j, (*it)->RenderMaterial().MaterialColor());
	//			}
	//		}
	//	}
	//}

	//std::string filename = "sceneOrthogonal.bmp";
	//std::string error;
	//image.SaveImage(filename, error);


	Ray ray;
	Vector3 point;

	float pixelCenterY = 0.0f, pixelCenterX = 0.0f;

	float pixelWidth = 2.0f / image.Height();
	float pixelHeight = 2.0f / image.Width();

	float xAspect = 0.0f;
	float yAspect = 0.0f;
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

	sampler->GenerateSamples();
	int n = (int)sqrt((float)sampler->NumberOfSamples());
	Color L = Color::black;
	SceneObject *objPointer = nullptr;


	for (size_t i = 0; i < image.Height(); ++i)
	{

		for (size_t j = 0; j < image.Width(); j++)
		{
			L = Color::black;

			for (Vector2& sample : sampler->Samples())
			{
				pixelCenterY = scale * ((-1.0f / yAspect) + ((i + 0.5f - sample.Y() / n) * pixelWidth) / yAspect);
				pixelCenterX = scale * ((-1.0f * xAspect) + ((j + 0.5f - sample.X() / n) * pixelHeight) * xAspect);

				ray.reset(Vector3(pixelCenterX, pixelCenterY, position.Z()), direction, farPlane);

				for (auto it = objectsToRender.begin(); it != objectsToRender.end(); ++it)
				{
					if ((*it)->checkIntersection(ray, point))
					{
						objPointer = (*it);
					}
				}
				if (objPointer)
				{
					L += objPointer->RenderMaterial().MaterialColor();
					objPointer = nullptr;
				}
			}

			L /= static_cast<float>(sampler->NumberOfSamples());
			image.SetPixel(i, j, L);
		}
	}

	std::string filename = "sceneOrthogonal.bmp";
	std::string error;
	image.SaveImage(filename, error);
}
