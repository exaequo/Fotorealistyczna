#ifndef SPHERE_H
#define SPHERE_H
#include "Vector3.h"
#include "Primitive.h"

class Sphere : public Primitive
{
    public:
        Sphere();
        Sphere(Vector3& center, float radius);
        virtual ~Sphere();
        int intersect(Ray& ray, float &distance, Vector3& hitpoint);
        const Vector3& Center();
        const float& Radius();

    protected:
        Vector3 center;
        float radius;
    private:
};

#endif // SPHERE_H
