#pragma once
#include "Ray.h"
#include "Color.h"
#include "Material.h"

class Primitive
{
public:
	Primitive();
	Primitive(const Material &material);
	Primitive(const Vector3 center, const Material &material);
	~Primitive();

	virtual bool Intersect(Ray &ray) = 0;
	virtual void IntersectionOutput(const Ray &ray) = 0;
	void CalculateDistanceToCamera(Vector3& camPos);

	friend std::ostream &operator<<(std::ostream &os, const Primitive &value);

	Vector3 Center() const { return center; }
	void Center(Vector3 val) { center = val; }
	float DistanceToCamera() const { return distanceToCamera; }
	void DistanceToCamera(float val) { distanceToCamera = val; }
	Material CurrentMaterial() const { return material; }
	void CurrentMaterial(Material val) { material = val; }
protected:
	Vector3 center;
	Material material;
	float distanceToCamera;
};
