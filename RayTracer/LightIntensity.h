#pragma once
class LightIntensity
{
public:
	LightIntensity();
	LightIntensity(float r, float g, float b);
	LightIntensity(float r, float g);
	LightIntensity(float r);

	~LightIntensity();

	float R();
	void R(float value);
	float G();
	void G(float value);
	float B();
	void B(float value);

	void add(double R, double G, double B);
	
	void operator()(float R, float G, float B);
	void operator()(float R, float G);
	void operator()(float R);

	LightIntensity& operator+(LightIntensity &li);
	LightIntensity& operator-(LightIntensity &li);
	
	LightIntensity& operator/(float num);

	LightIntensity& operator+=(LightIntensity &li);
	LightIntensity& operator-=(LightIntensity &li);

	LightIntensity& operator*=(float num);
	LightIntensity& operator/=(float num);
	
	friend LightIntensity& operator*(float num, LightIntensity &li);
	friend LightIntensity& operator*(LightIntensity &li, float num);
	friend std::ostream& operator<<(std::ostream& str, LightIntensity &li);

protected:
	float r;
	float b;
	float g;
};

