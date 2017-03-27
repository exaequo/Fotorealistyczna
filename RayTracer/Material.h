#pragma once
#include "stdafx.h"
#include "Color.h"

class Material
{
public:
	Material();
	Material(Color& color);
	~Material();
	Color& MaterialColor();
	void MaterialColor(Color& color);
protected:
	Color materialColor;

};

