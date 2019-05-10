#include "transform.hpp"

Transform::Transform()
{
	position = {0, 0};
	scale = {1, 1};
}

void Transform::setPosition(float x, float y)
{
	position = {x, y};
}

void Transform::setPosition(Vector2 position)
{
	this->position = position;
}

void Transform::translate(float x, float y)
{
	position.x += x;
	position.y += y;
}

void Transform::translate(Vector2 deltaPosition)
{
	position.x += deltaPosition.x;
	position.y += deltaPosition.y;
}

Vector2 Transform::getPosition()
{
	return position;
}

void Transform::setScale(float x, float y)
{
	scale = {x, y};
}

void Transform::setScale(Vector2 scale)
{
	this->scale = scale;
}

Vector2 Transform::getScale()
{
	return scale;
}
