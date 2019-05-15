#ifndef view_hpp
#define view_hpp

#include <SDL2/SDL.h>
#include "../primitives/spriteSheet.hpp"
#include "../primitives/primitives.hpp"
//#include "gameObject.hpp" // TODO: I can't do this, why?

class GameObject; // This is to show View that GameObject exists
class View
{
public:
	View(GameObject *p_gameObject);
	~View();
	void render(SDL_Renderer *p_renderer);
	GameObject *p_gameObject();
	SDL_Rect clipRect;
private:
	GameObject *_p_gameObject;
	IntVector2 size;
};

#endif /* view_hpp */
