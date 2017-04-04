#pragma once
#include "Primitive.h"
#include "Camera.h"
#include "Mesh.h"

class Scene
{
public:
	Scene();
	~Scene();

	void AddPrimitveToScene(Primitive *primitive);
	void AddPrimitveToScene(Mesh &mesh);
	void Sort();
	void CalculatePrimitivesDistanceToCamera(Camera* camera);

	friend std::ostream &operator<<(std::ostream &os, const Scene &value);

	std::vector<Primitive *> Primitives() const { return primitives; }
	void Primitives(std::vector<Primitive *> val) { primitives = val; }
private:
	vector<Primitive*> primitives;

	int QuickSortPartition(int start, int end);
};

bool wayToSort(const Primitive* lhs, const Primitive* rhs);