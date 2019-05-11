#ifndef gameObject_hpp
#define gameObject_hpp

#include <SDL2/SDL.h>
#include "transform.hpp"
#include "view.hpp"

class GameObject
{
public:
	GameObject(SDL_Renderer *p_renderer);
	void update(float deltaTime);
	Transform *p_transform();
	View *p_view();
private:
	Transform _transform;
	View _view;
	SDL_Renderer *_p_renderer;
};

#endif /* gameObject_hpp */
