#pragma once
#include "core.h"
#include <cmath>

#define DELTA 1.0e-6f

namespace Spyce
{
	// a small delta value that we'll consider "0"
	namespace Math
	{
		/// <summary>
		/// Linearly interpolates between the values [from, to] based on the t (which should be
		/// a value between [0,1].
		/// </summary>
		/// <param name="from"></param>
		/// <param name="to"></param>
		/// <param name="t"></param>
		/// <returns></returns>
		inline float Lerp(float from, float to, float t)
		{
			return (to - from) * t + from;
		}

		/// <summary>
		/// Checks if the floating point number is considered "0".
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		inline bool IsZero(float value)
		{
			return std::fabsf(value) < DELTA;
		}

		/// <summary>
		/// Checks if the two floating point numbers are equal.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		inline bool AreEqual(float a, float b)
		{
			return IsZero(a - b);
		}

		/// <summary>
		/// Takes the floor value.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		inline float Floor(float val)
		{
			return std::floor(val);
		}

		/// <summary>
		/// Takes the ceiling value.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		inline float Ceil(float val)
		{
			return std::ceil(val);
		}

		/// <summary>
		/// Returns the rounded value.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		inline float Round(float val)
		{
			return std::round(val);
		}

		/// <summary>
		/// Takes the square root.
		/// </summary>
		/// <param name="val"></param>
		/// <returns></returns>
		inline float Sqrt(float val)
		{
			return std::sqrtf(val);
		}

		/// <summary>
		/// The num-th power of 2.
		/// 
		/// O(log[num])
		/// </summary>
		/// <param name="num"></param>
		/// <returns></returns>
		unsigned long PowBase2(unsigned int num)
		{
			if (num == 0)
				return 1.0f;
			else if (num == 1)
				return 2;

			unsigned long a = PowBase2(num / 2);

			return a * a * ((num % 2 == 1) + 1);
		}

		// trig functions
		const float PI = 3.1415f;
		const float TWO_PI = 6.2832f;
		const float PI_OVER_2 = 1.5707f;
		const float PI_OVER_4 = 0.7854f;
		
		/// <summary>
		/// Converts the angle from radians to degrees.
		/// </summary>
		/// <param name="rads"></param>
		/// <returns></returns>
		inline float ToDegrees(float rads)
		{
			return rads * 180.f / PI;
		}

		/// <summary>
		/// Converts the angle from degrees to radians.
		/// </summary>
		/// <param name="deg"></param>
		/// <returns></returns>
		inline float ToRadians(float deg)
		{
			return deg * PI / 180.f;
		}
	}
}

#undef DELTA