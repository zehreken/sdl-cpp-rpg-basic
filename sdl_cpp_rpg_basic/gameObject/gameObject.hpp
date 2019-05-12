#ifndef gameObject_hpp
#define gameObject_hpp

#include <SDL2/SDL.h>
#include "transform.hpp"
#include "view.hpp"

class GameObject
{
public:
	GameObject();
//	GameObject(SDL_Renderer *p_renderer, SpriteSheet *p_spriteSheet);
	void update(float deltaTime, SDL_Renderer *p_renderer);
	Transform *p_transform();
	View *p_view(); // obsolete
	SDL_Renderer *p_renderer();
	void setSpriteSheet(SpriteSheet *p_spriteSheet);
	SpriteSheet *p_spriteSheet();
private:
	Transform _transform;
	View _view; // obsolete
	SDL_Renderer *_p_renderer;
	SpriteSheet *_p_spriteSheet;
};

#endif /* gameObject_hpp */
