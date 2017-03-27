#pragma once
class Color
{
public:
	static Color white;
	static Color black;
	static Color red;
	static Color blue;
	static Color green;
	static Color yellow;
	static Color purple;

	Color();
	Color(float r, float g, float b);
	Color(float r, float g);
	Color(float r);

	~Color();

	float R();
	void R(float value);
	float G();
	void G(float value);
	float B();
	void B(float value);

	void add(float R, float G, float B);
	
	void operator()(float R, float G, float B);
	void operator()(float R, float G);
	void operator()(float R);

	Color& operator+(Color &li);
	Color& operator-(Color &li);
	

	Color& operator+=(Color &li);
	Color& operator-=(Color &li);

	Color& operator*=(float num);
	Color& operator/=(float num);

	Color& operator=(const Color &rhs);
	
	friend Color& operator*(float num, Color &li);
	friend Color& operator*(Color &li, float num);
	friend Color& operator/(float num, Color &li);
	friend Color& operator/(Color &li, float num);
	friend std::ostream& operator<<(std::ostream& str, Color &li);

protected:
	float r;
	float b;
	float g;
};

