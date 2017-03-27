// RayTracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<SceneObject *> objToRender;

	SceneObject *sphere1 = new Sphere(Vector3::zero, 1, Material(Color::red));
	SceneObject *sphere2 = new Sphere(Vector3(0.5f, 0.5f, -1), 1, Material(Color::blue));
	SceneObject *plane1 = new Plane(Vector3(0,-0.5f,0), Vector3(-0.1f, 0.9f, -0.1f),Material(Color::green));
	
	objToRender.push_back(plane1);
	objToRender.push_back(sphere1);
	objToRender.push_back(sphere2);
	

	OrthogonalCamera cam1(640, 480, Vector3(0, 0, -10), Vector3::forward, 0, 100, 2);
	cam1.render(objToRender);
	cout << "Orto rendered\n";

	PerspectiveCamera cam2(640, 480, 15.0f, Vector3(0, 0, -10), Vector3::forward, 0.01f, 100);
	/*cout << cam2.Fov() << ", " << cam2.ViewPlaneDistance() << ", W:" << cam2.W() << ", U:" << cam2.U() << ", V:" << cam2.V() << endl;
	cout << cam2.Width() << ", " << cam2.Height() <<", " << cam2.FarPlane()<<", " << cam2.NearPlane() << endl;*/
	cam2.render(objToRender);
	cout << "Persp rendered\n";

	system("pause");
    return 0;

}

