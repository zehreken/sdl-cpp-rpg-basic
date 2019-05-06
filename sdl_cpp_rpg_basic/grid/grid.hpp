#ifndef grid_hpp
#define grid_hpp

#include "../primitives/textureWrapper.hpp"
#include "../primitives/primitives.hpp"

class Tile
{
public:
	LTexture *ltexture;
	IntVector2 gridPos;
	Tile();
private:
};

void grid_init(SDL_Renderer *renderer);
void grid_render(SDL_Renderer *renderer);
void grid_close();

#endif /* grid_hpp */
