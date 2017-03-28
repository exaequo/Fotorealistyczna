#include "stdafx.h"
#include "Material.h"


Material::Material() : Material(Color::white){}

Material::Material(Color & color)
{
	materialColor = color;
	
}


Material::~Material(){}

Color & Material::MaterialColor()
{
	return materialColor;
}

void Material::MaterialColor(Color & color)
{
	materialColor = color;
}
