#include "stdafx.h"
#include "Primitive.h"

Primitive::Primitive() : center(Vector3::zero), material(Material()), distanceToCamera(0.0f)
{ }

Primitive::Primitive(const Vector3 center, const Material &material) : center(center), material(material), distanceToCamera(0.0f)
{ }

Primitive::Primitive(const Material &material) : center(Vector3::zero), material(material), distanceToCamera(0.0f)
{ }

Primitive::~Primitive()
{ }

void Primitive::CalculateDistanceToCamera(Vector3& camPos)
{
	distanceToCamera = Vector3::Distance(center, camPos);
}

std::ostream & operator<<(std::ostream &os, const Primitive &value)
{
	os << "center: " << value.center << ", distance: " << value.distanceToCamera << ", color ambient material: " << value.CurrentMaterial().ColorAmbient();

	return os;
}
