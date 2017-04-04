#pragma once
#include "Primitive.h"
#include "Plane.h"
#include <array>

class Triangle :
	public Primitive
{
public:
	Triangle();
	Triangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &normal, const Material &material);
	~Triangle();

	virtual bool Intersect(Ray &ray) override;
	virtual void IntersectionOutput(const Ray &ray) override;

	friend std::ostream &operator<<(std::ostream &os, const Triangle &value);

	std::array<Vector3, 3> Vertices() const { return vertices; }
	void Vertices(std::array<Vector3, 3> val) { vertices = val; }
	float SurfaceArea() const { return surfaceArea; }
	void SurfaceArea(float val) { surfaceArea = val; }
	Vector3 Normal() const { return normal; }
	void Normal(Vector3 val) { normal = val; }
private:
	Plane surfacePlane;
	Vector3 normal;
	std::array<Vector3, 3> vertices;
	std::array<float, 3> barycentric;
	float surfaceArea;

	void CalculateSurfaceArea();
};

