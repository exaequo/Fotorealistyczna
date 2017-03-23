// RayTracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Vector3 v1(0, 0, -20);
	//Vector3 v2(0, 0, 1);
	//Vector3 v3(0, 1, 0);
	//Vector3 v4(10, 10, 0);
	//Vector3 v5(-1, 0, 0);
	//Vector3 hit;
	//float distance = 100;
	//float defDistance = 100;
	//Plane p1(*(new Vector3(0, 0, 0)), *(new Vector3(0, 1, 1)));
	////
	////    Ray r1(v1, v3);

	//Sphere s1(Vector3::zero(), 10);
	//Ray r1(v1, v2);
	//int type;
	//cout << "Ray:\no:" << v1 << ", d:" << v2 << endl;
	//type = s1.intersect(r1, distance, hit);
	//cout << "HitType: " << type << endl;
	//if (type != IntersectType::MISS) { cout << "point: " << hit << endl << endl; }
	//else { cout << endl; }

	//distance = defDistance;

	//Ray r2(v1, v3);
	//cout << "Ray:\no:" << v1 << ", d:" << v3 << endl;
	//type = s1.intersect(r2, distance, hit);
	//cout << "HitType: " << type << endl;
	//if (type != IntersectType::MISS) { cout << "point: " << hit << endl << endl; }
	//else { cout << endl; }
	//distance = defDistance;

	//Ray r3(v4, v5);
	//cout << "Ray:\no:" << v4 << ", d:" << v5 << endl;
	//type = s1.intersect(r3, distance, hit);
	//cout << "HitType: " << type << endl;
	//if (type != IntersectType::MISS) { cout << "point: " << hit << endl << endl; }
	//else { cout << endl; }
	//distance = defDistance;

	////     cout<<"Ray:\no:"<<v1<<", d:"<<v3<<endl;
	//type = p1.intersect(r2, distance, hit);
	//cout << "Ray:\no:" << r2.Origin() << ", d:" << r2.Direction() << endl;
	//cout << "HitType: " << type << endl;
	//if (type != IntersectType::MISS) { cout << "point: " << hit << endl << endl; }
	//else { cout << endl; }

	//cout << "TEST"<< endl;
	//Plane p2(Vector3(1, 0, 0), Vector3(1, 1, 0));
	//Ray r8(Vector3(10, 0, 0), Vector3(-1, 0, 0));
	//type = p2.intersect(r8, distance, hit);
	//cout << "Ray:\no:" << r8.Origin() << ", d:" << r8.Direction() << endl;
	//cout << "HitType: " << type << endl;
	//if (type != IntersectType::MISS) { cout << "point: " << hit << endl << endl; }
	//else { cout << endl; }

	Color c1 = Color::green;
	
	cout << c1 << endl;
	//c1 /= 4;
	cout << c1/4 << endl;

	system("pause");
    return 0;

}

