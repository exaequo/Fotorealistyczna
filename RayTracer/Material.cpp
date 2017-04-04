#include "stdafx.h"
#include "Material.h"


Material::Material() :
	colorAmbient(Color::black)
{ }


Material::Material(const Color &colorAmbient) :
	colorAmbient(colorAmbient)
{ }

Material::Material(std::string name) :
	materialName(name)
{ }

Material::~Material()
{ }
