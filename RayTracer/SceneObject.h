#pragma once
#include "Material.h"
#include "Ray.h"
#include "Vector3.h"

class SceneObject
{
public:
	SceneObject();
	~SceneObject();
	virtual bool checkIntersection(Ray & ray, Vector3 & point) = 0;
	Material & RenderMaterial();
	void RenderMaterial(Material & material);
protected:
	Material mat;
};

