#ifndef characterManager_hpp
#define characterManager_hpp

#include <SDL2/SDL.h>
#include "../primitives/primitives.hpp"

void initCharacterManager(SDL_Renderer *p_renderer);
void renderCharacters(SDL_Renderer *p_renderer);
void moveCharacter(IntVector2 direction);

#endif /* characterManager_hpp */
