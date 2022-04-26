#pragma once
#include "spyce/vector2.h"

namespace Spyce
{
	class Circle
	{
	public:
		Circle(float x, float y, float radius);
		Circle(const Vector2& center, float radius);
		float GetArea() const;
		Vector2 GetCenter() const;
		
	private:
		float mRadius;
		float mX;
		float mY;
	};
}