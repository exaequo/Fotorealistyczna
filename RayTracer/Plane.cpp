#include "stdafx.h"
#include "Plane.h"

using namespace std;

Plane::Plane() :
	Primitive(),
	normal(Vector3::zero)
{ }


Plane::Plane(const Vector3 &center, const Vector3 &normal) :
	Primitive(),
	normal(normal)
{
	this->normal.Normalize();
}

Plane::Plane(const Vector3 &center, const Vector3 &normal, const Material &material) :
	Primitive(center, material),
	normal(normal)
{
	this->normal.Normalize();
}

Plane::~Plane()
{ }

bool Plane::Intersect(Ray &ray)
{
	float Vd = Vector3::Dot(normal, ray.Direction());
	float Vo = 0.0f;
	float t = 0.0f;

	if (Vd < EPSILON && Vd > -EPSILON)
	{
		ray.Intersected(false);
		return false;
	}
	else
	{
		Vo = Vector3::Dot(normal, (center - ray.Origin())); // lnijka w której matematyka - Królowa Nauk siê myli i ma byæ tak jak ze stack overflow

		t = Vo / Vd;

		if (t >= EPSILON)
		{
			ray.Destination(Vector3(
				ray.Origin().X() + ray.Direction().X() * t,
				ray.Origin().Y() + ray.Direction().Y() * t,
				ray.Origin().Z() + ray.Direction().Z() * t));

			if (Vd > EPSILON)
			{
				ray.NormalInDestinationPoint(-normal);
			}
			else
			{
				ray.NormalInDestinationPoint(normal);
			}

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
	}

	ray.Intersected(false);
	return false;
}

void Plane::IntersectionOutput(const Ray &ray)
{
	cout << "Intersection between Plane & Ray" << endl << *this << ray;
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

float Plane::IntersectReturnT(Ray &ray)
{
	float Vd = Vector3::Dot(normal, ray.Direction());
	float Vo = 0.0f;
	float t = 0.0f;

	if (Vd < EPSILON && Vd > -EPSILON)
	{
		return -1;
	}
	else
	{
		Vo = Vector3::Dot(normal, (center - ray.Origin())); // lnijka w której matematyka - Królowa Nauk siê myli i ma byæ tak jak ze stack overflow

		t = Vo / Vd;

		if (t >= EPSILON)
		{
			return t;
		}
	}

	return -1;
}

std::ostream & operator<<(std::ostream &os, const Plane &value)
{
	os << "Plane - point: " << value.center << ", normal: " << value.normal << std::endl;

	return os;
}
