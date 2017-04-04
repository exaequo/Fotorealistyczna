#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "Scene.h"
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "AdaptiveSampler.h"
#include "Triangle.h"
#include "Mesh.h"


#include <chrono> // time measurement

using namespace std;
using namespace std::chrono;

int main()
{
	Scene scene = Scene();
	Primitive *sphere1 = new Sphere(Vector3(0.0f, 0.0f, 0.0f), 1.2f, Color::red);
	Primitive *sphere2 = new Sphere(Vector3(-2.5f, 0.5f, 1.0f), 1.0f, Color::blue);
	Primitive *plane2 = new Plane(Vector3(0.0f, -0.5f, 0.0f), Vector3(0.1f, 0.9f, -0.1f), Color::yellow);

	Mesh meshCube = Mesh("cube", Color::cyan);
	Mesh meshCone = Mesh("cone", Color::white);

	scene.AddPrimitveToScene(sphere2);
	scene.AddPrimitveToScene(sphere1);
	scene.AddPrimitveToScene(plane2);
	scene.AddPrimitveToScene(meshCube);
	scene.AddPrimitveToScene(meshCone);


	unsigned int width = 1024;
	unsigned int height = 1024;

	OrthographicCamera OrtCamera = OrthographicCamera(
		Vector3(0.0f, 0.0f, -10.0f),
		Vector3::forward,
		width,
		height,
		10.0f,
		nullptr
		//new AdaptiveSampler(1, 4, 0.05f)
		);

	auto time1 = high_resolution_clock::now();
	OrtCamera.RenderScene(scene.Primitives());
	auto time2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(time2 - time1).count() / 1000.0f;

	cout << "Othographic: " << duration << " seconds" << endl;

	PerspectiveCamera Perspective = PerspectiveCamera(
		Vector3(0.0f, 0.0f, -10.0f),
		Vector3(0.0f, 0.0f, 300.0f),
		Vector3::up,
		0.1f,
		1000.0f,
		45.0f,
		width,
		height,
		nullptr
		//new AdaptiveSampler(1, 4, 0.05f)
		);


	time1 = high_resolution_clock::now();
	Perspective.RenderScene(scene.Primitives());
	time2 = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(time2 - time1).count() / 1000.0f;
	cout << "Persp: " << duration << " seconds" << endl;

	delete sphere1;
	delete sphere2;

	system("pause");

	return 0;

}

