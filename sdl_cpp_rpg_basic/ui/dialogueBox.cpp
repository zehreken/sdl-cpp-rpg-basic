#include "dialogueBox.hpp"
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>

TTF_Font* font;

static const SDL_Rect fillRect = {0, 540 - 100, 960, 100};

static bool isOpen = false;
static SDL_Surface* p_surface;
static SDL_Texture* p_texture;
static SDL_Rect rect;
static SDL_Color color = { 255, 255, 255, 255 };

void initDialogueBox()
{
	TTF_Init();
	font = TTF_OpenFont("assets/emulogic.ttf", 24);
	if (!font)
		printf("%s: %s\n", "Font loading error", SDL_GetError());
}

void showDialogueMessage(SDL_Renderer *p_renderer, std::string message)
{
	isOpen = true;
	
	p_surface = TTF_RenderText_Blended_Wrapped(font, message.c_str(), color, 960);
	p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);
	// Free surface
	SDL_FreeSurface(p_surface);
	SDL_QueryTexture(p_texture, NULL, NULL, &rect.w, &rect.h);
	rect.x = 0;
	rect.y = 540 - 100;
}

void renderDialogueBox(SDL_Renderer *p_renderer)
{
	if (isOpen)
	{
		SDL_SetRenderDrawColor(p_renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(p_renderer, &fillRect);
		SDL_RenderCopy(p_renderer, p_texture, NULL, &rect);
	}
}

void closeDialogueBox()
{
	isOpen = false;
	SDL_DestroyTexture(p_texture);
}
