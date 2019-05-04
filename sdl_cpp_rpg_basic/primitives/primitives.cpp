#include "primitives.hpp"

Vector2::Vector2() {}
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

IntVector2::IntVector2() {};
IntVector2::IntVector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

Vector3::Vector3() {};
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

int add(int x, int y)
{
	return x + y;
}
