#include "gameObject.hpp"

GameObject::GameObject(SDL_Renderer *p_renderer) : _view(this), _transform(this)
{
	_p_renderer = p_renderer;
}

void GameObject::update(float deltaTime)
{
	
}

Transform *GameObject::p_transform()
{
	return &_transform;
}

View *GameObject::p_view()
{
	return &_view;
}
