#pragma once
#include "SceneObject.h"
#include "Vector3.h"
#include "Image.h"
#include <vector>
#include "Sampler.h"

class Camera
{
public:
	Camera();
	Camera(int width, int height);
	Camera(int width, int height, Vector3 & position, Vector3 & direction);
	Camera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far);
	Camera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far, Sampler *sampler, int scale);
	~Camera();
	virtual void render(std::vector<SceneObject*> &objectsToRender) = 0;
	
	int Width();
	void Width(int value);
	int Height();
	void Height(int value);
	float FarPlane();
	void FarPlane(float value);
	float NearPlane();
	void NearPlane(float value);
	Vector3 Position();
	void Position(Vector3 & value);
	Vector3 Direction();
	void Direction(Vector3 & value);

	static const Color backgroundColor;
protected:
	Sampler *sampler;
	int width;
	int height;
	float farPlane;
	float nearPlane;
	Vector3 position;
	Vector3 direction;
	float aspectRatio;
	int scale;
	Image image;
};

