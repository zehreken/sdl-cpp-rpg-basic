#include "transform.hpp"

Transform::Transform(GameObject *p_parent)
{
	_p_parent = p_parent;
	_position = {0, 0};
	_scale = {1, 1};
}

GameObject *Transform::p_parent()
{
	return _p_parent;
}

void Transform::setPosition(float x, float y)
{
	_position = {x, y};
}

void Transform::setPosition(Vector2 position)
{
	_position = position;
}

void Transform::translate(float x, float y)
{
	_position.x += x;
	_position.y += y;
}

void Transform::translate(Vector2 deltaPosition)
{
	_position.x += deltaPosition.x;
	_position.y += deltaPosition.y;
}

Vector2 Transform::getPosition()
{
	return _position;
}

void Transform::setScale(float x, float y)
{
	_scale = {x, y};
}

void Transform::setScale(Vector2 scale)
{
	_scale = scale;
}

Vector2 Transform::getScale()
{
	return _scale;
}
