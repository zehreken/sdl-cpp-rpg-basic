#include "view.hpp"
#include "gameObject.hpp"

View::View(GameObject *p_parent)
{
	_p_parent = p_parent;
}

View::~View()
{
    
}

void View::render(SDL_Renderer *p_renderer)
{
//	tile->ltexture->render(renderer, column * 16 + (int)gridPos.x, row * 16 + (int)gridPos.y, &clipRect);
	Vector2 pos = _p_parent->p_transform()->getPosition();
//	std::cout << pos.x << " " << pos.y << "\n";
	_p_parent->p_spriteSheet()->render(p_renderer, pos.x * 16, pos.y * 16, &clipRect);
}

GameObject *View::p_parent()
{
	return _p_parent;
}
