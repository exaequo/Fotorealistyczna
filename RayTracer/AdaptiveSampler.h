#pragma once
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "Vector2.h"
#include "Color.h"
#include "Primitive.h"

class AdaptiveSampler
{
public:
	AdaptiveSampler();

	AdaptiveSampler(const int maxSamplesPerPixel);

	AdaptiveSampler(const int minSamplesPerPixel, const int maxSamplesPerPixel);

	AdaptiveSampler(const int minSamplesPerPixel, const int maxSamplesPerPixel, const float spatialContrast);

	AdaptiveSampler(const AdaptiveSampler& r);

	AdaptiveSampler& operator= (const AdaptiveSampler& rhs);

	~AdaptiveSampler();

	bool CheckSpatialContrast(const Color &value);

	Color AdaptiveAntiAliasing(Camera *camera, vector<Primitive*> primitives, const Vector2 &center, const int &row, const int &column, int level, Color leftDown, Color leftUp, Color rightUp, Color rightDown);

	//Color CalculateSingleSample(PerspectiveCamera &camera, const Vector2 &coord, const int &row, const int &column, vector<Primitive*> &primitives);
	//Color CalculateSingleSample(OrthographicCamera &camera, const Vector2 &coord, const int &row, const int &column, vector<Primitive*> &primitives);

	int MinSamplesPerPixel() const { return minSamplesPerPixel; }
	void MinSamplesPerPixel(int val) { minSamplesPerPixel = val; }
	int MaxSamplesPerPixel() const { return maxSamplesPerPixel; }
	void MaxSamplesPerPixel(int val) { maxSamplesPerPixel = val; }
	float SpatialContrast() const { return spatialContrast; }
	void SpatialContrast(float val) { spatialContrast = val; }
private:
	int minSamplesPerPixel;
	int maxSamplesPerPixel;
	float spatialContrast;
};

