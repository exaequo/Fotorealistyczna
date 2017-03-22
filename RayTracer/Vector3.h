#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

class Vector3
{
    public:
        Vector3():Vector3(0,0,0){}
        Vector3(float x, float y, float z);
        virtual ~Vector3();
        const float X();
        void setX(float value);
        const float Y();
        void setY(float value);
        const float Z();
        void setZ(float value);

        float magnitude();
        void normalize();
        Vector3 &negate();

        static float dot(Vector3 &l, Vector3 &r);
        static Vector3 &cross(Vector3 &l, Vector3 &r);
        static Vector3 &zero();
        static Vector3 &right();
        static Vector3 &forward();
        static Vector3 &up();
        static float distance (Vector3 &v1, Vector3 &v2);

		Vector3& operator+=(Vector3& right);
		Vector3& operator-=(Vector3& right);

		Vector3 operator-(Vector3& right);

		

		Vector3 operator*(Vector3& right);

		Vector3& operator*=(Vector3& right);
		Vector3& operator/(Vector3& right);

		Vector3 &operator*(float value);

		Vector3 &operator/(float value);

		Vector3& operator/=(Vector3& right);

		bool operator==(Vector3& right);
		bool operator!=(Vector3& right);
		Vector3 operator-() const;

        std::string toString();
    protected:
        float x;
        float y;
        float z;
    private:
};
std::ostream & operator<<(std::ostream & Str, Vector3 & v);
Vector3 operator+(Vector3& left, Vector3& right);
#endif // VECTOR3_H
