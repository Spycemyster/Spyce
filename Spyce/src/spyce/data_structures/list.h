#pragma once
#include "spyce/core.h"

namespace Spyce
{
	template <typename T>
	/// <summary>
	/// Stores objects as a continguous piece of memory.
	/// </summary>
	class List
	{
	public:
		// iterator
		class ListIterator
		{
		public:
			ListIterator(List* list, size_t start_index = 0)
			{
				mList = list;
				mIndex = start_index;
			}

			T& operator*() 
			{
				return mList->Get(mIndex);
			}
			void operator++() { mIndex++; }
			void operator--() { mIndex--; }
			bool operator !=(const ListIterator& other) const { return other.mIndex != mIndex || mList != other.mList; }

		private:
			List* mList;
			size_t mIndex;
		};

		ListIterator begin()
		{
			return ListIterator(this);
		}
		ListIterator end()
		{
			return ListIterator(this, Size());
		}
		/// <summary>
		/// Creates a new instance of a list.
		/// </summary>
		List() : List(1)
		{

		}

		/// <summary>
		/// Creates a new instance of a list with an initial size.
		/// </summary>
		/// <param name="initial_size"></param>
		List(size_t initial_size)
		{
			assert(initial_size > 0);
			mCurrentSize = 0;
			mInitialSize = initial_size;
			mMaxSize = initial_size;

			mData = new T[mMaxSize];

		}

		~List()
		{
			delete[] mData;
		}

		/// <summary>
		/// The number of elements stored in the list.
		/// </summary>
		/// <returns></returns>
		size_t Size() const
		{
			return mCurrentSize;
		}

		/// <summary>
		/// Adds the object to the end of the list.
		/// 
		/// O(1) amortized
		/// </summary>
		void Add(T obj)
		{
			// double the current list size and copy all the elements to the new list
			if (mCurrentSize >= mMaxSize)
			{
				mMaxSize = mMaxSize + mMaxSize;
				T* newData = new T[mMaxSize];
				for (size_t idx = 0; idx < mCurrentSize; idx++)
				{
					newData[idx] = mData[idx];
				}

				delete[] mData;
				mData = newData;
			}


			mData[mCurrentSize++] = obj;
		}

		/// <summary>
		/// Removes the object at the end of the list.
		/// 
		/// O(1)
		/// </summary>
		T& Pop_Back()
		{
			return mData[mCurrentSize-- - 1];
		}

		/// <summary>
		/// Gets the object at index i.
		/// 
		/// O(1)
		/// </summary>
		/// <param name="i"></param>
		T& Get(size_t i) const
		{
			return mData[i];
		}

		/// <summary>
		/// Sets the value of the object located at index i. The index must already be set.
		/// 
		/// O(1)
		/// </summary>
		/// <param name="index"></param>
		/// <param name="obj"></param>
		void Set(size_t index, T& obj)
		{
			mData[index] = obj;
		}

		/// <summary>
		/// Access the element at index i.
		/// 
		/// O(n)
		/// </summary>
		T& operator[](size_t i) 
		{
			return mData[i];
		}

		/// <summary>
		/// Removes the object at the specified index and returns it.
		/// 
		/// O(n)
		/// </summary>
		/// <param name="i"></param>
		T& Remove(size_t i)
		{
			T obj = Get(i);

			for (size_t idx = i + 1; idx < mCurrentSize; idx++)
			{
				mData[idx - 1] = mData[idx];
			}

			Pop_Back();

			return obj;
		}

		/// <summary>
		/// Swaps two objects with the given indices.
		/// 
		/// O(1) complexity -> Constant assignment operations
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		void Swap(size_t a, size_t b)
		{
			T temp = mData[a];
			mData[a] = mData[b];
			mData[b] = temp;
		}

		/// <summary>
		/// Removes all elements from the list.
		/// </summary>
		void Clear()
		{
			Reset();
		}

		/// <summary>
		/// Whether this list has elements or not.
		/// 
		/// O(1)
		/// </summary>
		/// <returns></returns>
		bool Empty() const
		{
			return mCurrentSize == 0;
		}

		/// <summary>
		/// Checks whether the two lists have equal elements.
		/// 
		/// O(n)
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		bool operator==(const List& other) const
		{
			// trivial case, two lists are of different sizes.
			if (other.mCurrentSize != mCurrentSize)
				return false;

			for (size_t i = 0; i < mCurrentSize; i++)
			{
				if (other.Get(i) != Get(i))
					return false;
			}

			return true;
		}
	private:
		static size_t max(size_t a, size_t b) { return (a > b) * a + (a <= b) * b; }
		void Reset()
		{
			mCurrentSize = 0;
			mMaxSize = mInitialSize;
			if (mData != nullptr)
				delete[] mData;
			mData = new T[mMaxSize];
		}
		size_t mCurrentSize;
		size_t mMaxSize;
		size_t mInitialSize;
		T* mData;
	};


}