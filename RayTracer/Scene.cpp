#include "stdafx.h"
#include "Scene.h"
#include <algorithm>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddPrimitveToScene(Primitive *primitive)
{
	primitives.push_back(primitive);
}

void Scene::AddPrimitveToScene(Mesh &mesh)
{
	for (auto &triangle : mesh.Polygons())
	{
		AddPrimitveToScene(triangle);
	}
}

void Scene::Sort()
{
	std::sort(primitives.begin(), primitives.end(), wayToSort);

	//int middle;

	//if (start < end)
	//{
	//	middle = QuickSortPartition(start, end);
	//	QuickSort(start, middle);
	//	QuickSort(middle + 1, end);
	//}
}

void Scene::CalculatePrimitivesDistanceToCamera(Camera* camera)
{
	for (auto& primitive : primitives)
	{
		primitive->CalculateDistanceToCamera(camera->Position());
	}
}

bool wayToSort(const Primitive* lhs, const Primitive* rhs)
{
	return (lhs->DistanceToCamera() > rhs->DistanceToCamera());
}

int Scene::QuickSortPartition(int start, int end)
{
	float z = primitives[start]->DistanceToCamera();
	int i = start, j = end;

	while (true)
	{
		while (primitives[j]->DistanceToCamera() > z)
		{
			--j;
		}
		while (primitives[i]->DistanceToCamera() < z)
		{
			++i;
		}

		if (primitives[i]->DistanceToCamera() <= primitives[j]->DistanceToCamera())
		{
			swap(primitives[i], primitives[j]);
			++i;
			--j;
		}
		else
		{
			return j;
		}
	}
}

std::ostream & operator<<(std::ostream &os, const Scene &value)
{
	os << "Scene primitives:" << endl;
	for (const auto &primitve : value.Primitives())
	{
		os << (*primitve) << endl;
	}

	return os;
}
