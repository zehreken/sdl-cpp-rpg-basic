#ifndef grid_hpp
#define grid_hpp

#include "../primitives/spriteSheet.hpp"
#include "../primitives/primitives.hpp"

void initGrid(SDL_Renderer *renderer);
void renderGrid(SDL_Renderer *renderer);
void moveGrid(IntVector2 direction);
void moveCamera(IntVector2 direction);
void translateCamera(Vector2 delta);
Vector2 getCameraPosition();
void setGridPos(Vector2 delta);
void closeGrid();

#endif /* grid_hpp */
