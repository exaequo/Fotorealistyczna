#pragma once
#include "Camera.h"
#include "Sampler.h"

class PerspectiveCamera :
	public Camera
{
public:
	PerspectiveCamera();
	PerspectiveCamera(int width, int height);
	PerspectiveCamera(int width, int height, Vector3 & position, Vector3 & direction);
	PerspectiveCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far);
	PerspectiveCamera(int width, int height, float fov, Vector3 & position, Vector3 & direction, float near, float far, Sampler *sampler);

	void render(std::vector<SceneObject*> &objectsToRender);
	float Fov();
	Vector3 U();
	Vector3 W();
	Vector3 V();
	float ViewPlaneDistance();
protected:
	float fov;
	float viewPlaneDistance;

	Vector3 w, u, v;

	void calculateViewPlane();
	void calculateUVW();
};

