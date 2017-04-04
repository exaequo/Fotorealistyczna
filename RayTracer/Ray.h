#pragma once
#include "Vector3.h"
#include <iostream>

class Ray
{
public:
	Ray();
	Ray(const Vector3& origin, const Vector3& direction);
	~Ray();

	friend std::ostream &operator<<(std::ostream &os, const Ray &value);

	Vector3 Origin() const { return origin; }
	void Origin(Vector3 val) { origin = val; }
	Vector3 Direction() const { return direction; }
	void Direction(Vector3 val) { direction = val; }
	Vector3 Destination() const { return destination; }
	void Destination(Vector3 val) { destination = val; }
	Vector3 NormalInDestinationPoint() const { return normalInDestinationPoint; }
	void NormalInDestinationPoint(Vector3 val) { normalInDestinationPoint = val; }
	float Distance() const { return distance; }
	void Distance(float val) { distance = val; }
	bool Intersected() const { return intersected; }
	void Intersected(bool val) { intersected = val; }
	float ClippingValue() const { return clippingValue; }
	void ClippingValue(float val) { clippingValue = val; }
private:
	Vector3 origin;
	Vector3 direction;
	Vector3 destination;
	Vector3 normalInDestinationPoint;
	float clippingValue;
	float distance = 0.0f;
	bool intersected = false;
};
