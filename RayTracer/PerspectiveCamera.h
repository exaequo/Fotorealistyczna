#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Camera.h"


class PerspectiveCamera
	: public Camera
{
public:
	friend class AdaptiveSampler;

	PerspectiveCamera();

	PerspectiveCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const Vector3 &up,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler *sampler);

	PerspectiveCamera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const Vector3 &up,
		const float &nearPlane,
		const float &farPlane,
		const float &fov,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler *sampler);

	~PerspectiveCamera();

	virtual void RenderScene(vector<Primitive*> &primitives);
	virtual Color CalculateSingleSample(const Vector2 &coord, const int &row, const int &column, vector<Primitive *> &primitives);

private:
	float viewPlaneOffset;
	Vector3 w, u, v;
	Vector3 a, b, c;

	void CalculateViewPlaneOffsetFromFoV();
	void CalculateUVW();
	void CalculateViewPlaneVectors();
};

