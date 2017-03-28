#include "stdafx.h"
#include "Sampler.h"


Sampler::Sampler() :
	numberOfSamples(16),
	numberOfSets(1)
{ }

Sampler::Sampler(const int numberOfSamples) :
	numberOfSamples(numberOfSamples),
	numberOfSets(1)
{ }

Sampler::Sampler(const int numberOfSamples, const int num_sets) :
	numberOfSamples(numberOfSamples),
	numberOfSets(num_sets)
{ }

Sampler::Sampler(const Sampler& s) :
	numberOfSamples(NumberOfSamples()),
	numberOfSets(1)
{ }

Sampler& Sampler::operator=(const Sampler& rhs)
{
	numberOfSets = rhs.numberOfSets;
	NumberOfSamples(rhs.NumberOfSamples());
	samples = rhs.samples;

	return *this;
}

Sampler::~Sampler()
{ }
