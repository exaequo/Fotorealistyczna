#include "stdafx.h"
#include "Camera.h"
#include "AdaptiveSampler.h"


Camera::Camera() :
	position(Vector3(0.0f, 0.0f, 0.0f)),
	lookAtPoint(Vector3(0.0f, 0.0f, 0.0f)),
	viewDirection(Vector3(0.0f, 0.0f, 0.0f)),
	up(Vector3::up),
	right(Vector3::right),
	nearPlane(0.0f),
	farPlane(0.0f),
	fov(0.0f),
	image(Image(0, 0)),
	sampler(new AdaptiveSampler())
{ }

Camera::Camera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler* sampler
	) :
	position(position),
	lookAtPoint(lookAtPoint),
	up(Vector3::up),
	right(Vector3::right),
	nearPlane(0.1f),
	farPlane(1000.0f),
	fov(45.0f),
	aspectRatio(static_cast<float>(width) / static_cast<float>(height)),
	image(Image(width, height)),
	sampler(sampler)
{
	CalculateViewVector();
}

Camera::Camera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const float &nearPlane,
	const float &farPlane,
	const float &fov,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler* sampler
	) :
	position(position),
	lookAtPoint(lookAtPoint),
	up(Vector3::up),
	right(Vector3::right),
	nearPlane(nearPlane),
	farPlane(farPlane),
	fov(fov),
	aspectRatio(static_cast<float>(width) / static_cast<float>(height)),
	image(Image(width, height)),
	sampler(sampler)
{
	CalculateViewVector();
}

Camera::Camera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const Vector3 &up,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler* sampler
	) :
	position(position),
	lookAtPoint(lookAtPoint),
	up(up),
	right(Vector3::right),
	nearPlane(nearPlane),
	farPlane(farPlane),
	fov(fov),
	aspectRatio(static_cast<float>(width) / static_cast<float>(height)),
	image(Image(width, height)),
	sampler(sampler)
{
	CalculateViewVector();
}

Camera::Camera(
	const Vector3 &position,
	const Vector3 &lookAtPoint,
	const Vector3 &up,
	const float &nearPlane,
	const float &farPlane,
	const float &fov,
	const unsigned int width,
	const unsigned int height,
	AdaptiveSampler* sampler
	) :
	position(position),
	lookAtPoint(lookAtPoint),
	up(up),
	right(Vector3::right),
	nearPlane(nearPlane),
	farPlane(farPlane),
	fov(fov),
	aspectRatio(static_cast<float>(width) / static_cast<float>(height)),
	image(Image(width, height)),
	sampler(sampler)
{
	CalculateViewVector();
}

Camera::~Camera()
{ }

void Camera::CalculateViewVector()
{
	viewDirection = Vector3(lookAtPoint.X() - position.X(), lookAtPoint.Y() - position.Y(), lookAtPoint.Z() - position.Z());

	viewDirection.Normalize();
}

Vector3 Camera::CalculateViewVector(const Vector3 &origin, const Vector3 &destination)
{
	Vector3 result;
	result = Vector3(destination.X() - origin.X(), destination.Y() - origin.Y(), destination.Z() - origin.Z());

	result.Normalize();
	return result;
}

void Camera::CalculateUpVector()
{
	CalculateRightVector();

	up = Vector3::Cross((-viewDirection), right);
	up.Normalize();
}

void Camera::CalculateRightVector()
{
	CalculateViewVector();

	right = Vector3::Cross(up, (-viewDirection));
	right.Normalize();
}
