#include "view.hpp"
#include "gameObject.hpp"
#include "../grid/grid.hpp"

View::View(GameObject *p_gameObject)
{
	_p_gameObject = p_gameObject;
}

View::~View()
{
    
}

void View::render(SDL_Renderer *p_renderer)
{
//	tile->ltexture->render(renderer, column * 16 + (int)gridPos.x, row * 16 + (int)gridPos.y, &clipRect);
	Vector2 pos = _p_gameObject->p_transform()->getPosition();
	Vector2 cameraPos = getCameraPosition();
	pos.x -= cameraPos.x;
	pos.y -= cameraPos.y;
//	std::cout << pos.x << " " << pos.y << "\n";
	
//	if (pos.x < 960 && pos.y < 540) // Optimization, does not seem to effect?
	_p_gameObject->p_spriteSheet()->render(p_renderer, pos.x, pos.y, &clipRect);
}

GameObject *View::p_gameObject()
{
	return _p_gameObject;
}
