#ifndef PLANE_H
#define PLANE_H
#include "Ray.h"
#include "Vector3.h"
#include "Primitive.h"

class Plane : public Primitive
{
    public:
        Plane();
        Plane(Vector3 &point, Vector3 &normal);
        virtual ~Plane();
        int intersect(Ray& ray, float &distance, Vector3& hitpoint);
        float Distance();
    protected:
        Vector3 normal;
        Vector3 point;
        float dist;
    private:
};

#endif // PLANE_H
