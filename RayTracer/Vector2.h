#ifndef VECTOR2_H
#define VECTOR2_H
#include <iostream>
#include <string>
#include <sstream>

class Vector2
{
    public:
        Vector2():Vector2(0,0){}
        Vector2(float x, float y);
        virtual ~Vector2();
        const float X();
        void setX(float value);
        const float Y();
        void setY(float value);

        float magnitude();
        void normalize();
        void negate();

        static float dot(Vector2 &l, Vector2 &r);
//        static Vector2 &cross(const Vector2 &l, const Vector2 &r);

        Vector2 operator+(Vector2& right){
            float x = X() + right.X();
            float y = Y() + right.Y();
            return Vector2(x,y);
        }
        Vector2& operator+=(Vector2& right){
            this->x += right.X();
            this->y += right.Y();
            return *this;
        }
        Vector2 operator-(Vector2& right){
            float x = X() - right.X();
            float y = Y() - right.Y();
            return Vector2(x,y);
        }
        Vector2& operator-=(Vector2& right){
            this->x -= right.X();
            this->y -= right.Y();
            return *this;
        }
        Vector2 operator*(Vector2& right){
            float x = X() * right.X();
            float y = Y() * right.Y();
            return Vector2(x,y);
        }
        Vector2& operator*=(Vector2& right){
            this->x *= right.X();
            this->y *= right.Y();
            return *this;
        }
        Vector2 operator/(Vector2& right){
            if(right.X() != 0 && right.Y() != 0){
                float x = X() / right.X();
                float y = Y() / right.Y();
                return Vector2(x,y);
            }else{
                std::cout<<"Trying to divide by zero\n";
            }
        }

        Vector2 operator*(float value){
            float x = X() * value;
            float y = Y() * value;
            return Vector2(x,y);
        }
        Vector2 operator/(float value){
            if(value != 0){
                float x = X() / value;
                float y = Y() / value;
                return Vector2(x,y);
            }else{
                std::cout<<"Trying to divide by zero\n";
            }
        }
        Vector2& operator/=(Vector2& right){
            this->x /= right.X();
            this->y /= right.Y();
            return *this;
        }
        bool operator==(Vector2& right){
            return (this->x == right.X() && this->y == right.Y());
        }
        bool operator!=(Vector2& right){
            return (this->x != right.X() && this->y != right.Y());
        }
        std::string toString() {
            std::stringstream str;
            str <<"["<< X()<< ", "<< Y()<< "]";
            return str.str();
        }
        operator std::string(){
          return toString();
        }
    protected:
        float x;
        float y;
    private:
};
std::ostream & operator<<(std::ostream & Str, Vector2 & v);
#endif // VECTOR2_H
