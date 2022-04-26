#pragma once

namespace Spyce
{
	class Vector2
	{
	public:
		Vector2(float x, float y);
		Vector2();
		float GetX() const;
		float GetY() const;
		float GetLength() const;
		void Normalize();
		Vector2 GetNormalized() const;
		Vector2 GetOrthogonal() const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(float mult) const;
		float operator*(const Vector2& other) const;
		bool operator==(const Vector2& other) const;
	private:
		float mX;
		float mY;
	};
}