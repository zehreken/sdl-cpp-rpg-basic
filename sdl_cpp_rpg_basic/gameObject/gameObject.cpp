#include "gameObject.hpp"

GameObject::GameObject() : _transform(this), _view(this)
{
	
}

GameObject::GameObject(SDL_Renderer *p_renderer, SpriteSheet *p_spriteSheet) : _transform(this), _view(this)
{
	
}

void GameObject::update(float deltaTime, SDL_Renderer *p_renderer)
{
	_view.render(p_renderer);
}

Transform *GameObject::p_transform()
{
	return &_transform;
}

View *GameObject::p_view()
{
	return &_view;
}

SDL_Renderer *GameObject::p_renderer()
{
	return _p_renderer;
}

void GameObject::setSpriteSheet(SpriteSheet *p_spriteSheet)
{
	_p_spriteSheet = p_spriteSheet;
}

SpriteSheet *GameObject::p_spriteSheet()
{
	return _p_spriteSheet;
}
