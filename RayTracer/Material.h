#pragma once
#include "Vector3.h"
#include "Color.h"
#include <string>

class Material
{
public:
	Material();
	Material(std::string name);
	Material(const Color &colorAmbient);
	~Material();

	std::string Name() const { return materialName; }
	void Name(std::string val) { materialName = val; }
	Color ColorAmbient() const { return colorAmbient; }
	void ColorAmbient(Color val) { colorAmbient = val; }
	Color ColorDiffuse() const { return colorDiffuse; }
	void ColorDiffuse(Color val) { colorDiffuse = val; }
	Color ColorSpecular() const { return colorSpecular; }
	void ColorSpecular(Color val) { colorSpecular = val; }
	Color ColorEmissive() const { return colorEmissive; }
	void ColorEmissive(Color val) { colorEmissive = val; }
	float Ns() const { return m_Ns; }
	void Ns(float val) { m_Ns = val; }
	float Ni() const { return m_Ni; }
	void Ni(float val) { m_Ni = val; }
	float D() const { return m_d; }
	void D(float val) { m_d = val; }
	float Tr() const { return m_Tr; }
	void Tr(float val) { m_Tr = val; }
	Vector3 Tf() const { return m_Tf; }
	void Tf(Vector3 val) { m_Tf = val; }
	float Illum() const { return illum; }
	void Illum(float val) { illum = val; }
private:
	std::string materialName;
	Color colorAmbient;
	Color colorDiffuse;
	Color colorSpecular;
	Color colorEmissive;
	float m_Ns;
	float m_Ni;
	float m_d;
	float m_Tr;
	Vector3 m_Tf;
	float illum;
};

