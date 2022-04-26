#include "scpch.h"
#include "circle.h"

namespace Spyce
{
	Circle::Circle(float x, float y, float radius) : mX(x), mY(y), mRadius(radius) { }
	Circle::Circle(const Vector2& center, float radius) : Circle(center.GetX(), center.GetY(), radius) { }
	float Circle::GetArea() const
	{
		return mRadius * mRadius;
	}

	Vector2 Circle::GetCenter() const
	{
		return Vector2(mX, mY);
	}
}