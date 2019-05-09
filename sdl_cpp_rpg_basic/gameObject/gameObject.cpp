#include "gameObject.hpp"

GameObject::GameObject()
{
	position = {0, 0};
}

void GameObject::setPosition(float x, float y)
{
	position = {x, y};
}

void GameObject::setPosition(Vector2 pos)
{
	position = pos;
}

void GameObject::translate(float x, float y)
{
	position.x += x;
	position.y += y;
}

void GameObject::translate(Vector2 deltaPos)
{
	position.x += deltaPos.x;
	position.y += deltaPos.y;
}

Vector2 GameObject::getPosition()
{
	return position;
}
