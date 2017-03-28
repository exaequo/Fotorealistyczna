#include "stdafx.h"
#include "Camera.h"
#include "Sampler.h"
#include "RegularSampler.h"

const Color Camera::backgroundColor = Color::black;

Camera::Camera():Camera(256,256,Vector3::zero,Vector3::forward,0,10000, new RegularSampler(), 1){}

Camera::Camera(int width, int height):Camera(width,height,Vector3::zero,Vector3::forward,0,10000, new RegularSampler(), 1){}

Camera::Camera(int width, int height, Vector3 & position, Vector3 & direction):Camera(width,height,position,direction,0,10000, new RegularSampler(), 1){}

Camera::Camera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far) : Camera(width, height, position, direction, near, far, new RegularSampler(),1){}

Camera::Camera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far, Sampler* sampler, int scale)
{
	this->width = width;
	this->height = height;
	this->nearPlane = near;
	this->farPlane = far;
	this->position = position;
	this->direction = direction;
	this->scale = scale;
	this->sampler = sampler;

	this->image = *(new Image(width, height));
	this->direction.normalize();
	aspectRatio = (static_cast<float>(width) / static_cast<float>(height));
}



Camera::~Camera(){}

int Camera::Width()
{
	return width;
}

void Camera::Width(int value)
{
	width = value;
}

int Camera::Height()
{
	return height;
}

void Camera::Height(int value)
{
	height = value;
}

float Camera::FarPlane()
{
	return farPlane;
}

void Camera::FarPlane(float value)
{
	farPlane = value;
}

float Camera::NearPlane()
{
	return nearPlane;
}

void Camera::NearPlane(float value)
{
	nearPlane = value;
}

Vector3 Camera::Position()
{
	return position;
}

void Camera::Position(Vector3 & value)
{
	position = value;
}

Vector3 Camera::Direction()
{
	return direction;
}

void Camera::Direction(Vector3 & value)
{
	direction = value;
}
