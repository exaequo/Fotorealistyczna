#include "stdafx.h"
#include "SceneObject.h"


SceneObject::SceneObject()
{
}


SceneObject::~SceneObject()
{
}

Material & SceneObject::RenderMaterial()
{
	return mat;
}

void SceneObject::RenderMaterial(Material & material)
{
	mat = material;
}
