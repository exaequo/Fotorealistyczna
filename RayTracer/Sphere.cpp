#include "stdafx.h"
#include "Sphere.h"

using namespace std;

Sphere::Sphere() :
	Primitive(),
	radius(0.0f),
	squaredRadius(0.0f)
{ }


Sphere::Sphere(const Vector3 &center, float radius) :
	Primitive(),
	radius(radius)
{
	SquaredRadius();
	InversedRadius();
}

Sphere::Sphere(const Vector3 &center, float radius, const Material &material) :
	Primitive(center, material),
	radius(radius)
{
	SquaredRadius();
	InversedRadius();
}

Sphere::~Sphere()
{
}

float Sphere::SquaredRadius()
{
	squaredRadius = sqr(radius);
	return squaredRadius;
}

float Sphere::InversedRadius()
{
	inversedRadius = 1.0f / radius;
	return inversedRadius;
}

bool Sphere::Intersect(Ray &ray)
{
	float A = sqr(ray.Direction().X()) + sqr(ray.Direction().Y()) + sqr(ray.Direction().Z());
	float B = 2 * (ray.Direction().X() * (ray.Origin().X() - center.X()) + ray.Direction().Y() * (ray.Origin().Y() - center.Y()) + ray.Direction().Z() * (ray.Origin().Z() - center.Z()));
	float C = sqr((ray.Origin().X() - center.X())) + sqr((ray.Origin().Y() - center.Y())) + sqr((ray.Origin().Z() - center.Z())) - squaredRadius;

	float delta = sqr(B) - 4 * A * C;
	float t0, t1;
	float *tResult = nullptr;
	float inversedDoubledA = 1.0f / (2 * A);

	if (delta >= 0.0f)
	{
		t0 = (-B - sqrt(delta)) * inversedDoubledA;

		if (t0 < 0.0f)
		{
			t1 = (-B + sqrt(delta)) * inversedDoubledA;

			if (t1 > 0.0f)
			{
				tResult = &t1;
			}
			else
			{
				ray.Intersected(false);
				return false;
			}
		}
		else
		{
			tResult = &t0;
		}

		ray.Destination(Vector3(
			ray.Origin().X() + ray.Direction().X() * (*tResult),
			ray.Origin().Y() + ray.Direction().Y() * (*tResult),
			ray.Origin().Z() + ray.Direction().Z() * (*tResult)));

		ray.NormalInDestinationPoint(Vector3(
			(ray.Destination().X() - center.X()) * inversedRadius,
			(ray.Destination().Y() - center.Y()) * inversedRadius,
			(ray.Destination().Z() - center.Z()) * inversedRadius));
		ray.NormalInDestinationPoint().Normalize();


		ray.Distance(Vector3::Distance(ray.Origin(), ray.Destination()));
		if (ray.Distance() < ray.ClippingValue())
		{
			ray.ClippingValue(ray.Distance());
			ray.Intersected(true);
			return true;
		}
		else
		{
			ray.Intersected(false);
			return false;
		}
	}

	ray.Intersected(false);
	return false;
}

void Sphere::IntersectionOutput(const Ray &ray)
{
	cout << "Intersection between Sphere & Ray" << endl << *this << ray << endl;
	if (ray.Intersected())
	{
		cout << "Intersetion Point: " << ray.Destination() << endl;
		cout << "Normal Vector in intersetion point: " << ray.NormalInDestinationPoint() << endl;
		cout << "Distance form origin to destination: " << ray.Distance() << endl;
	}
	else
	{
		cout << "There is no intersetion point between them!" << endl;
	}
	cout << endl;
}

std::ostream & operator<<(std::ostream &os, const Sphere &value)
{
	os << "Sphere - " << "center: (" << value.center.X() << ", " << value.center.Y() << ", " << value.center.Z() << "), "
		<< "radius: " << value.radius << std::endl;

	return os;
}
