#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Image.h"
#include "Primitive.h"
#include <vector>

class Camera
{
public:
	friend class AdaptiveSampler;
	Camera();

	Camera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler* sampler
		);

	Camera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const float &nearPlane,
		const float &farPlane,
		const float &fov,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler* sampler
		);

	Camera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const Vector3 &up,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler* sampler
		);

	Camera(
		const Vector3 &position,
		const Vector3 &lookAtPoint,
		const Vector3 &up,
		const float &nearPlane,
		const float &farPlane,
		const float &fov,
		const unsigned int width,
		const unsigned int height,
		AdaptiveSampler* sampler
		);
	~Camera();

	static Vector3 CalculateViewVector(const Vector3 &origin, const Vector3 &destination);

	void CalculateViewVector();
	void CalculateUpVector();
	void CalculateRightVector();

	virtual void RenderScene(vector<Primitive*> &primitives) = 0;
	virtual Color CalculateSingleSample(const Vector2 &coord, const int &row, const int &column, vector<Primitive*> &primitives) = 0;

	Vector3 Position() const { return position; }
	void Position(Vector3 val) { position = val; }
	Vector3 LookAtPoint() const { return lookAtPoint; }
	void LookAtPoint(Vector3 val) { lookAtPoint = val; }
	Vector3 ViewDirection() const { return viewDirection; }
	void ViewDirection(Vector3 val) { viewDirection = val; }
	Vector3 Up() const { return up; }
	void Up(Vector3 val) { up = val; }
	Vector3 Right() const { return right; }
	void Right(Vector3 val) { right = val; }
	float NearPlane() const { return nearPlane; }
	void NearPlane(float val) { nearPlane = val; }
	float FarPlane() const { return farPlane; }
	void FarPlane(float val) { farPlane = val; }
	float Fov() const { return fov; }
	void Fov(float val) { fov = val; }

protected:
	AdaptiveSampler *sampler;
	Image image;
	Vector3 position;
	Vector3 lookAtPoint;
	Vector3 viewDirection;
	Vector3 up;
	Vector3 right;
	float nearPlane;
	float farPlane;
	float fov;
	float aspectRatio;
};

