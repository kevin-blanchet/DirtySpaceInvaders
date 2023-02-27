#include "Vector.h"

Vector2D::Vector2D(): x(0), y(0)
{
}

Vector2D::Vector2D(const Vector2D& vector): x(vector.x), y(vector.y)
{
}

Vector2D::Vector2D(const float x, const float y) : x(x), y(y)
{
}

bool Vector2D::IntCmp(const Vector2D& vec)
{
	return ( static_cast<int>(x) == static_cast<int>(vec.x) ) && ( static_cast<int>(y) == static_cast<int>(vec.y) );
}
