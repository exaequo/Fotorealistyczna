#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

class Vector3
{
    public:
		static Vector3 zero;
		static Vector3 right;
		static Vector3 left;
		static Vector3 forward;
		static Vector3 back;
		static Vector3 up;
		static Vector3 down;

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
		Vector3 normalized();
        Vector3 &negate();

        static float dot(Vector3 &l, Vector3 &r);
        static Vector3 &cross(Vector3 &l, Vector3 &r);
        
        static float distance (Vector3 &v1, Vector3 &v2);

		Vector3& operator=(const Vector3 &rhs);
		Vector3& operator+=(const Vector3 &rhs);
		Vector3& operator-=(const Vector3 &rhs);
		Vector3 operator-() const;
		Vector3& operator*=(const Vector3 &rhs);
		Vector3& operator/=(const Vector3 &rhs);
		Vector3& operator*=(const float &rhs);
		Vector3& operator/=(const float &rhs);

		friend bool operator==(const Vector3 &lhs, const Vector3 &rhs);
		friend std::ostream &operator<<(std::ostream &os, const Vector3 &value);

        std::string toString();
    protected:
        float x;
        float y;
        float z;
    private:
};

Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs);
bool operator!=(const Vector3 &lhs, const Vector3 &rhs);
Vector3 operator*(const Vector3 &lhs, const float &rhs);
Vector3 operator*(const float &lhs, const Vector3 &rhs);
Vector3 operator/(const Vector3 &lhs, const float &rhs);

#endif // VECTOR3_H
