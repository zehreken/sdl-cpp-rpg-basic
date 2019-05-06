#include "primitives.hpp"
#include <iostream>

Vector2::Vector2() { x = y = 0; }
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
Vector2::~Vector2() { std::cout << "Vector2 is deleted" << '\n'; }

IntVector2::IntVector2() { x = y = 0; };
IntVector2::IntVector2(int _x, int _y)
{
	x = _x;
	y = _y;
}
//IntVector2::~IntVector2() { std::cout << "IntVector2 is deleted" << '\n'; }

Vector3::Vector3() { x = y = z = 0; };
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
Vector3::~Vector3() { std::cout << "Vector3 is deleted" << '\n'; }

int add(int x, int y)
{
	return x + y;
}
