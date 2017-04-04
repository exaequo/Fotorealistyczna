#include "stdafx.h"
#include "Triangle.h"

Triangle::Triangle() :
	vertices({ Vector3::zero, Vector3::zero, Vector3::zero }),
	barycentric({ 0.0f, 0.0f, 0.0f }),
	normal(Vector3::up)

{
	CalculateSurfaceArea();
}


Triangle::Triangle(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3, const Vector3 &normal, const Material &material) :
	Primitive(material),
	vertices({ v1, v2, v3 }),
	barycentric({ 0.0f, 0.0f, 0.0f }),
	normal(normal)
{
	CalculateSurfaceArea();

	surfacePlane = Plane(v1, normal, material);
}

Triangle::~Triangle()
{ }

void Triangle::CalculateSurfaceArea()
{
	Vector3 firstVec = vertices[0] - vertices[1];
	Vector3 secondVec = vertices[2] - vertices[1];

	surfaceArea = 0.5f * firstVec.Magnitude() * secondVec.Magnitude() * sin(DegreesToRadians(Vector3::Angle(firstVec, secondVec)));
}

// PLANE & NEXT CHECK ANGLES
//bool Triangle::Intersect(Ray &ray)
//{
//	float t = surfacePlane.IntersectReturnT(ray);
//	if (t >= EPSILON)
//	{
//		Vector3 fa, fb, fc;
//		Vector3 x;
//		Vector3 point = ray.Origin() + ray.Direction() * t;
//
//		fa = vertices[0] - point;
//		fb = vertices[1] - point;
//		fc = vertices[2] - point;
//
//
//		x = Vector3::Cross(fa, fb);
//		x.Normalize();
//
//		if (Vector3::Dot(x, normal) < -EPSILON)
//		{
//			return false;
//		} 
//		else
//		{
//			x = Vector3::Cross(fb, fc);
//			x.Normalize();
//			if (Vector3::Dot(x, normal) < -EPSILON)
//			{
//				return false;
//			} 
//			else
//			{
//				x = Vector3::Cross(fc, fa);
//				x.Normalize();
//				if (Vector3::Dot(x, normal) < -EPSILON)
//				{
//					return false;
//				}
//				else
//				{
//					ray.Destination(point);					
//					ray.Distance(Vector3::Distance(ray.Origin(), ray.Destination()));
//					if (ray.Distance() < ray.ClippingValue())
//					{
//						ray.ClippingValue(ray.Distance());
//						ray.Intersected(true);
//						return true;
//					}
//					else
//					{
//						ray.Intersected(false);
//						return false;
//					}
//				}
//			}
//		}
//	}
//
//	return false;
//}

// BARYCENTRIC
bool Triangle::Intersect(Ray &ray)
{
	float t = surfacePlane.IntersectReturnT(ray);
	if (t > EPSILON)
	{
		Vector3 &P = ray.Origin() + ray.Direction() * t;
		Vector3 &P0 = vertices[0], &P1 = vertices[1], &P2 = vertices[2];
		float &w0 = barycentric[0], &w1 = barycentric[1], &w2 = barycentric[2];

		Vector3 R = P - P0;
		Vector3 Q1 = P1 - P0;
		Vector3 Q2 = P2 - P0;
		float Q1Q2 = Vector3::Dot(Q1, Q2);
		float SQR_Q1Q2 = Q1Q2 * Q1Q2;
		float SQR_Q1 = Vector3::Dot(Q1, Q1);
		float SQR_Q2 = Vector3::Dot(Q2, Q2);

		float RQ1 = Vector3::Dot(R, Q1);
		float RQ2 = Vector3::Dot(R, Q2);

		float A = SQR_Q1 * SQR_Q2 - SQR_Q1Q2;
		float X1 = RQ1 * SQR_Q2 - (Q1Q2 * RQ2);
		float X2 = SQR_Q1 * RQ2 - (RQ1 * Q1Q2);

		w1 = X1 / A;
		w2 = X2 / A;
		w0 = 1.0f - w2 - w1;

		if (w0 >= 0.0f && w1 >= 0.0f && w2 >= 0.0f && (w1 + w2) <= 1.0f)
		{
			ray.Destination(P);
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
	return false;
}


// MOLLER COS TAM
//bool Triangle::Intersect(Ray &ray)
//{
//	Vector3 e1, e2;
//	Vector3 P, Q, T;
//	float delta, invDelta, u, v;
//	float t;
//
//	e1 = vertices[1] - vertices[0];
//	e2 = vertices[2] - vertices[1];
//
//	P = Vector3::Cross(ray.Direction(), e2);
//
//	delta = Vector3::Dot(e1, P);
//
//	if (delta > -EPSILON && delta < EPSILON)
//	{
//		return false;
//	}
//	invDelta = 1.0f / delta;
//
//	T = ray.Origin() - vertices[0];
//	u = Vector3::Dot(T, P) * invDelta;
//
//	if (u < 0.0f || u > 1.0f)
//	{
//		return false;
//	}
//
//	Q = Vector3::Cross(T, e1);
//
//	v = Vector3::Dot(ray.Direction(), Q) * invDelta;
//	
//	if (v < 0.0f || v > 1.0f)
//	{
//		return false;
//	}
//
//	t = Vector3::Dot(e2, Q) * invDelta;
//
//	if (t > EPSILON)
//	{
//
//		ray.Destination(Vector3(
//			ray.Origin().X() + ray.Direction().X() * t,
//			ray.Origin().Y() + ray.Direction().Y() * t,
//			ray.Origin().Z() + ray.Direction().Z() * t));
//
//		//ray.NormalInDestinationPoint(Vector3(
//		//	(ray.Destination().X() - center.X()) * inversedRadius,
//		//	(ray.Destination().Y() - center.Y()) * inversedRadius,
//		//	(ray.Destination().Z() - center.Z()) * inversedRadius));
//		//ray.NormalInDestinationPoint().Normalize();
//
//
//		ray.Distance(Vector3::Distance(ray.Origin(), ray.Destination()));
//		if (ray.Distance() < ray.ClippingValue())
//		{
//			ray.ClippingValue(ray.Distance());
//			ray.Intersected(true);
//			return true;
//		}
//		else
//		{
//			ray.Intersected(false);
//			return false;
//		}
//	}
//
//	return false;
//}

void Triangle::IntersectionOutput(const Ray &ray)
{
	cout << "Intersection between Triangle & Ray" << endl << *this << ray;
	if (ray.Intersected())
	{
		cout << "Intersetion Point: " << ray.Destination() << endl;
		cout << "Intersetion Point(barycentric): " << barycentric[0] * vertices[0] + barycentric[1] * vertices[1] + barycentric[2] * vertices[2] << endl;
		cout << "Normal Vector in intersetion point: " << ray.NormalInDestinationPoint() << endl;
		cout << "Distance form origin to destination: " << ray.Distance() << endl;
	}
	else
	{
		cout << "There is no intersetion point between them!" << endl;
	}
	cout << endl;
}

std::ostream &operator<<(std::ostream &os, const Triangle &value)
{
	os << "Triagle - v1: " << value.Vertices()[0] << ", v2: " << value.Vertices()[1] << ", v3: " << value.Vertices()[2] << endl;
	os << "Normal: " << value.Normal() << endl;
	os << "Surface Area: " << value.SurfaceArea() << endl;
	os << "Color ambient: " << value.CurrentMaterial().ColorAmbient() << endl;

	return os;
}