#ifndef dialogueBox_hpp
#define dialogueBox_hpp

#include <SDL2/SDL.h>
#include <iostream>

void initDialogueBox();
void showDialogueMessage(SDL_Renderer *p_renderer, std::string message);
void renderDialogueBox(SDL_Renderer *p_renderer);
void closeDialogueBox();

#endif /* dialogueBox_hpp */
