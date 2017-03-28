#pragma once
class Sampler
{
public:
	Sampler();

	Sampler(const int numberOfSamples);

	Sampler(const int numberOfSamples, const int num_sets);

	Sampler(const Sampler& s);

	Sampler& operator= (const Sampler& rhs);
	~Sampler();

	virtual void GenerateSamples() = 0;

	int NumberOfSamples() const { return numberOfSamples; }
	void NumberOfSamples(int val) { numberOfSamples = val; }
	int NumberOfSets() const { return numberOfSets; }
	void NumberOfSets(int val) { numberOfSets = val; }
	std::vector<Vector2> Samples() const { return samples; }
	void Samples(std::vector<Vector2> val) { samples = val; }
protected:
	int numberOfSamples;
	int numberOfSets;
	vector<Vector2> samples;
};

