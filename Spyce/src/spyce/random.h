#pragma once
#include "core.h"
namespace Spyce
{
	/// <summary>
	/// An random number generator object that can be instanced.
	/// </summary>
	class SC_API Random
	{
	public:
		Random(size_t seed);
		Random();

		/// <summary>
		/// Obtains a randomly generated value between min_value and max_value.
		/// </summary>
		/// <param name="min_value"></param>
		/// <param name="max_value"></param>
		/// <returns></returns>
		float Next(float min_value, float max_value);

		/// <summary>
		/// Obtains a randomly generated value from [0,1)
		/// </summary>
		/// <returns></returns>
		float Next();
	private:
		size_t mSeed = 0;
	};
}