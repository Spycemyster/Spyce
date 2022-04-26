#pragma once

#include "spyce/vector2.h"
#include <vector>

namespace Spyce
{
	class Triangle
	{
	public:
		Triangle(const Vector2& a, const Vector2& b, const Vector2& c);
		Vector2 GetA() const;
		Vector2 GetB() const;
		Vector2 GetC() const;
		bool Intersects(const Triangle& other);
	private:
		Vector2 mA;
		Vector2 mB;
		Vector2 mC;
	};
}
