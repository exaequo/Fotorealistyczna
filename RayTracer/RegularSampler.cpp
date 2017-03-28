#include "stdafx.h"
#include "RegularSampler.h"


RegularSampler::RegularSampler() :
	Sampler()
{ }


RegularSampler::RegularSampler(const int num) :
	Sampler(num)
{ }

RegularSampler::RegularSampler(const RegularSampler& u) :
	Sampler(u)
{ }

RegularSampler& RegularSampler::operator=(const RegularSampler& rhs)
{
	numberOfSamples = rhs.NumberOfSamples();
	numberOfSets = rhs.NumberOfSets();
	samples = rhs.Samples();

	return *this;
}

RegularSampler::~RegularSampler()
{ }

void RegularSampler::GenerateSamples()
{
	int n = (int)sqrt((float)numberOfSamples);

	for (int j = 0; j < numberOfSets; j++)
	{
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < n; q++)
			{
				samples.push_back(Vector2((q + 0.5f), (p + 0.5f)));
			}
		}
	}
}
