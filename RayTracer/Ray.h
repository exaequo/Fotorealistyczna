#ifndef RAY_H
#define RAY_H
#include "Vector3.h"

enum IntersectType{
    MISS,
    HIT,
    INSIDE
};

class Ray
{
    public:
        Ray();
        Ray(Vector3 origin, Vector3 direction);
        virtual ~Ray();
        Vector3& Origin();
        Vector3& Direction();
        Vector3 normalOfHit;
    protected:
        Vector3 origin;
        Vector3 direction;

    private:
};

#endif // RAY_H
