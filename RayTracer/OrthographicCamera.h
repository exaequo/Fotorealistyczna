#pragma once
#include "Camera.h"
#include "Vector2.h"

class OrthographicCamera :
	public Camera
{
public:
	OrthographicCamera();

	OrthographicCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler *sampler);

	OrthographicCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const unsigned int width,
		const unsigned int height,
		const float pixelScale,
		AdaptiveSampler *sampler);

	OrthographicCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const float &nearPlane,
		const float &farPlane,
		const float &fov,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler *sampler);

	OrthographicCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const float &nearPlane,
		const float &farPlane,
		const float &fov,
		const unsigned int width,
		const unsigned int height,
		const float pixelScale,
		AdaptiveSampler *sampler);

	~OrthographicCamera();

	virtual void RenderScene(vector<Primitive*> &primitives);
	virtual Color CalculateSingleSample(const Vector2 &coord, const int &row, const int &column, vector<Primitive *> &primitives);
private:
	float pixelScale;
	float xAspect;
	float yAspect;
	float pixelHeight;
	float pixelWidth;

	void CalculateAspectRatio();
};

