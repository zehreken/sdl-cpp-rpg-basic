#ifndef grid_hpp
#define grid_hpp

#include "../primitives/spriteSheet.hpp"
#include "../primitives/primitives.hpp"

void initGrid(SDL_Renderer *renderer);
void renderGrid(SDL_Renderer *renderer);
void setGridPos(Vector2 delta);
void closeGrid();

#endif /* grid_hpp */
