#include "textureWrapper.hpp"

LTexture::LTexture()
{
	texture = NULL;
	width = 0;
	height = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(SDL_Renderer *renderer, std::string path)
{
	free();
	
	SDL_Texture *newTexture = NULL;
	SDL_Surface *newSurface = IMG_Load(path.c_str());
	if (newSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, 255, 0, 255));
		newTexture = SDL_CreateTextureFromSurface(renderer, newSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = newSurface->w * 2;
			height = newSurface->h * 2;
		}
	}
	
	//Return success
	texture = newTexture;
	return texture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if(texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void LTexture::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clipRect)
{
	//Set rendering space and render to screen
	SDL_Rect renderRect = { x, y, width, height };
	
	if (clipRect != NULL)
	{
		renderRect.w = clipRect->w;
		renderRect.h = clipRect->h;
	}
	
	SDL_RenderCopy(renderer, texture, clipRect, &renderRect);
}

int LTexture::getWidth()
{
	return width;
}

int LTexture::getHeight()
{
	return height;
}
