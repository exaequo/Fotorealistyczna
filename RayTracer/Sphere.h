#pragma once
#include "Vector3.h"
#include "Ray.h"
#include "Color.h"
#include "Primitive.h"

class Sphere : public Primitive
{
public:
	Sphere();
	Sphere(const Vector3 &center, float radius);
	Sphere(const Vector3 &center, float radius, const Material &material);
	~Sphere();
	float SquaredRadius();
	float InversedRadius();

	virtual bool Intersect(Ray &ray);
	virtual void IntersectionOutput(const Ray &ray);

	friend std::ostream &operator<<(std::ostream &os, const Sphere &value);

	float Radius() const { return radius; }
	void Radius(float val) { radius = val; }
	float SquaredRadius() const { return squaredRadius; }
	void SquaredRadius(float val) { squaredRadius = val; }
	float InversedRadius() const { return inversedRadius; }
	void InversedRadius(float val) { inversedRadius = val; }
private:
	float radius;
	float squaredRadius;
	float inversedRadius;
};