#include "scpch.h"
#include "random.h"

namespace Spyce
{
	Random::Random(size_t seed)
	{
		mSeed = seed;
	}

	Random::Random() : Random(0) { }

	float Random::Next(float min_value, float max_value)
	{
		// Park and Miller rng algorithm
		const size_t a = 16807;
		const size_t m = 2147483647;
		mSeed = (a * mSeed) % m;
		float result = mSeed / (float)m;

		// ensures we don't hit the c = 0 special case
		mSeed += (mSeed == 0) * a;

		// normalize results to given bounds
		return result * (max_value - min_value) + min_value;
	}

	float Random::Next()
	{
		return Next(0.f, 1.f);
	}
}