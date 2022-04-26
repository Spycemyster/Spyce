#pragma once

#include "spyce/core.h"

namespace Spyce
{
	template<typename T>
	class SC_API MaxFinder
	{
	public:
		/// <summary>
		/// Creates a new instance of a max finder.
		/// </summary>
		MaxFinder<T>() : mCurrentElement(nullptr), mPriority(0.f) {}

		/// <summary>
		/// Pushes the object into the max finder. If it has a higher priority, then it'll replace the previous object.
		/// </summary>
		/// <param name="obj"></param>
		/// <param name="priority"></param>
		bool Push(T* obj, float priority)
		{
			if (obj == nullptr || priority > mPriority)
			{
				mCurrentElement = obj;
				mPriority = priority;
				return true;
			}
			return false;
		}

		inline bool IsEmpty() const 
		{
			return mCurrentElement == nullptr; 
		}

		inline float GetPriority() const
		{
			return mPriority;
		}

		inline T* GetMax() const
		{
			return mCurrentElement;
		}
	private:
		T* mCurrentElement = nullptr;
		float mPriority;
	};
}