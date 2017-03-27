#pragma once
#include "Camera.h"
#include "SceneObject.h"
#include <vector>

class OrthogonalCamera : public Camera
{
public:
	//OrthogonalCamera(int width, int height);
	OrthogonalCamera();
	OrthogonalCamera(int width, int height);
	OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction);
	OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far);
	OrthogonalCamera(int width, int height, Vector3 & position, Vector3 & direction, float near, float far, int scale);
	~OrthogonalCamera();

	void render(std::vector<SceneObject*> &objectsToRender);
protected:
	
};

