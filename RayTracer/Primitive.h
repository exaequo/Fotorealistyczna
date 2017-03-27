#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "Ray.h"
#include "Material.h"

class Primitive : public SceneObject
{
    public:
        Primitive();
        virtual ~Primitive();
        virtual int intersect(Ray& ray, Vector3& hitpoint) = 0;
		bool checkIntersection(Ray & ray, Vector3 & point);
    protected:
		
    private:
};

#endif // PRIMITIVE_H
