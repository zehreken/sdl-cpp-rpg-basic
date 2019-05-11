#ifndef view_hpp
#define view_hpp

#include <SDL2/SDL.h>
//#include "gameObject.hpp" // TODO: I can't do this, why?

class GameObject; // This is to show View that GameObject exists
class View
{
public:
	View(GameObject *p_parent);
	~View();
	void render();
	GameObject *p_parent();
private:
	GameObject *_p_parent;
	SDL_Texture *_p_texture;
};

#endif /* view_hpp */
