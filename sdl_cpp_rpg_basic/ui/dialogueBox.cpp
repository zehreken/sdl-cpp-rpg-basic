#include "dialogueBox.hpp"
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>

TTF_Font* font;
static bool isOpen = false;

void initDialogueBox()
{
	font = TTF_OpenFont("fonts/emulogic.ttf", 24);
	if (!font)
		printf("Font loading error");
}

void showDialogueMessage(std::string message)
{
	isOpen = true;
}

void renderDialogueBox(SDL_Renderer *p_renderer)
{
	if (isOpen)
	{
		
	}
}

void closeDialogueBox()
{
	isOpen = false;
}
