#include "scpch.h"
#include "vector2.h"
#include "math.h"

namespace Spyce
{
	Vector2::Vector2(float x, float y): mX(x), mY(y) { }
	Vector2::Vector2() : Vector2(0, 0) { }
	float Vector2::GetX() const { return mX; }
	float Vector2::GetY() const { return mY; }

	Vector2 Vector2::GetNormalized() const
	{
		float len = GetLength();
		if (Math::IsZero(len))
			return Vector2(0, 0);

		return Vector2(mX / len, mY / len);
	}

	Vector2 Vector2::GetOrthogonal() const
	{
		return Vector2(-mY, mX);
	}

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(other.mX + mX, other.mY + mY);
	}
	
	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(mX - other.mX, mY - other.mY);
	}

	Vector2 Vector2::operator*(float mult) const
	{
		return Vector2(mX * mult, mY * mult);
	}

	float Vector2::operator*(const Vector2& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	bool Vector2::operator==(const Vector2& other) const
	{
		return mX == other.mX && mY == other.mY;
	}

	float Vector2::GetLength() const
	{
		return Math::Sqrt(mX * mX + mY * mY);
	}

	void Vector2::Normalize()
	{
		float len = GetLength();

		if (Math::IsZero(len))
			return;

		mX /= len;
		mY /= len;
	}

}