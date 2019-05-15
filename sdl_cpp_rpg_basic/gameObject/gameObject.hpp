#ifndef gameObject_hpp
#define gameObject_hpp

#include <SDL2/SDL.h>
#include "transform.hpp"
#include "view.hpp"

class GameObject
{
public:
	GameObject();
	void update(float deltaTime, SDL_Renderer *p_renderer);
	Transform *p_transform();
	View *p_view(); // obsolete
	void setSpriteSheet(SpriteSheet *p_spriteSheet);
	SpriteSheet *p_spriteSheet();
private:
	Transform _transform;
	View _view; // obsolete
	SpriteSheet *_p_spriteSheet;
};

#endif /* gameObject_hpp */
