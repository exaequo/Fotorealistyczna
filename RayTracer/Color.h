#pragma once
class Color
{
public:
#pragma region Static & Const
	static const float CLAMPED_MIN;
	static const float CLAMPED_MAX;
	static const int UNCLAMPED_MIN;
	static const int UNCLAMPED_MAX;

	static Color black;
	static Color blue;
	static Color clear;
	static Color cyan;
	static Color gray;
	static Color green;
	static Color grey;
	static Color magenta;
	static Color red;
	static Color white;
	static Color yellow;
	static Color undefined;

	static Color GetGrayscale(const Color &color);
	static Color& Clamp(Color &color);
	static int UnclampedR(const Color &color);
	static int UnclampedG(const Color &color);
	static int UnclampedB(const Color &color);
	static int UnclampedA(const Color &color);
#pragma endregion Static & Const

#pragma region Member Functions & Constructors
	Color();
	Color(const float &r, const float& g, const float &b);
	Color(const float &r, const float& g, const float &b, const float &a);
	Color(const Color &color);
	~Color();

	Color GetGrayscale();
	void Clamp();
	int UnclampedR();
	int UnclampedG();
	int UnclampedB();
	int UnclampedA();
#pragma endregion Member Functions & Constructors

#pragma region Overloaded Operators
	Color& operator=(const Color &rhs);
	Color& operator+=(const Color &rhs);
	Color& operator-=(const Color &rhs);
	Color& operator*=(const Color &rhs);
	Color& operator/=(const Color &rhs);
	//template<typename T>
	Color& operator*=(const float &rhs);
	//template<typename T>
	Color& operator/=(const float &rhs);

	friend bool operator==(const Color &lhs, const Color &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Color &value);
	friend std::istream &operator>>(std::istream &is, Color &value);
#pragma endregion Overloaded Operators

#pragma region Getters & Setters
	float R() const { return r; }
	void R(float val) { r = val; }
	float G() const { return g; }
	void G(float val) { g = val; }
	float B() const { return b; }
	void B(float val) { b = val; }
	float A() const { return a; }
	void A(float val) { a = val; }
#pragma endregion Getters & Setters

private:
	float r;
	float g;
	float b;
	float a;
};

Color operator+(const Color &lhs, const Color &rhs);
Color operator-(const Color &lhs, const Color &rhs);
Color operator*(const Color &lhs, const Color &rhs);
Color operator/(const Color &lhs, const Color &rhs);
bool operator!=(const Color &lhs, const Color &rhs);
//template<typename T>
Color operator*(const Color &lhs, const float &rhs);
//template<typename T>
Color operator*(const float &lhs, const Color &rhs);
//template<typename T>
Color operator/(const Color &lhs, const float &rhs);