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
        Ray(Vector3 origin, Vector3 direction, float maxLength);
        virtual ~Ray();
        Vector3 Origin();
        Vector3 Direction();
		float Length();
		void Length(float value);
        
		void reset(Vector3 origin, Vector3 direction, float maxLength);

		Vector3 normalOfHit;
    protected:
        Vector3 origin;
        Vector3 direction;
		float length;

    private:
};

#endif // RAY_H
