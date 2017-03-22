#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "Ray.h"

class Primitive
{
    public:
        Primitive();
        virtual ~Primitive();
        virtual int intersect(Ray& ray, float &distance, Vector3& hitpoint) = 0;
    protected:

    private:
};

#endif // PRIMITIVE_H
