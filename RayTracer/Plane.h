#pragma once
#include "Vector3.h"
#include "Primitive.h"

class Plane : public Primitive
{
public:
	Plane();
	Plane(const Vector3 &center, const Vector3 &normal);
	Plane(const Vector3 &center, const Vector3 &normal, const Material &material);
	~Plane();

	virtual bool Intersect(Ray &ray);
	virtual void IntersectionOutput(const Ray &ray);

	float IntersectReturnT(Ray &ray);

	friend std::ostream &operator<<(std::ostream &os, const Plane &value);

	Vector3 Normal() const { return normal; }
	void Normal(Vector3 val) { normal = val; }
private:
	Vector3 normal;
};