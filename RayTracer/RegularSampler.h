#pragma once
class RegularSampler :
	public Sampler
{
public:
	RegularSampler();

	RegularSampler(const int num);

	RegularSampler(const RegularSampler& u);

	RegularSampler& operator= (const RegularSampler& rhs);


	virtual ~RegularSampler();

	virtual void GenerateSamples();
};

