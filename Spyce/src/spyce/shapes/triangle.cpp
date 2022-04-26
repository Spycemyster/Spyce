#include "scpch.h"
#include "triangle.h"

namespace Spyce
{
	Triangle::Triangle(const Vector2& a, const Vector2& b, const Vector2& c) : mA(a), mB(b), mC(c) { }
	Vector2 Triangle::GetA() const { return mA; }
	Vector2 Triangle::GetB() const { return mB; }
	Vector2 Triangle::GetC() const { return mC; }
	bool Triangle::Intersects(const Triangle& other)
	{
		Vector2 initialA[3] = { mA, mA, mB };
		Vector2 finalA[3] = {mB, mC, mC};
		Vector2 initialB[3] = { other.mA, other.mA, other.mB };
		Vector2 finalB[3] = { other.mB, other.mC, other.mC };

		// (P - P0) * n = 0
		for (unsigned int a = 0; a < 3; a++)
		{
			float x0 = initialA[a].GetX();
			float y0 = initialA[a].GetY();
			float x1 = finalA[a].GetX();
			float y1 = finalA[a].GetY();
			for (unsigned int b = 0; b < 3; b++)
			{
				Vector2 AB = (finalB[b] - initialB[b]).GetOrthogonal().GetNormalized();
				float x = initialB[b].GetX();
				float y = initialB[b].GetY();
				float t = (AB.GetY() * (x0 - x) + AB.GetX() * (y - y0)) / ((y1 - y0) * AB.GetX() - (x1-x0) * AB.GetY());

				// not on the line
				if (t > 1 || t < 0)
					continue;

				float t_p = (x0 + (x1 - x0) * t - initialB[b].GetX()) / (finalB[b].GetX() - initialB[b].GetX());
				if (t_p <= 1 && t_p >= 0)
					return true;
			}
		}

		return false;
	}
}