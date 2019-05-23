//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "primitives/primitives.hpp"
#include "primitives/spriteSheet.hpp"
#include "utils/textureUnpacker.hpp"
#include "grid/grid.hpp"
#include "grid/noiseVisualizer.hpp"
#include "gameObject/gameObject.hpp"
#include "utils/timeUtils.hpp"
#include "character/characterManager.hpp"
#include "ui/dialogueBox.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads image as texture
SDL_Texture *loadTexture(std::string path);

// The window we'll be rendering to
SDL_Window *p_window = NULL;

// The window renderer
SDL_Renderer *p_renderer = NULL;

// Current displayed texture
SpriteSheet texture;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

bool init()
{
	//Initialization flag
	bool success = true;
	
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		p_window = SDL_CreateWindow("sdl_cpp_rpg_basic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( p_window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);
			if (p_renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 255);
				
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	
	return success;
}

SDL_Texture *loadTexture(std::string path)
{
	SDL_Texture *newTexture = NULL;
	
	SDL_Surface *newSurface = IMG_Load(path.c_str());
	
	if(newSurface == NULL)
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(p_renderer, newSurface);
		if(newTexture == NULL)
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		
		//Get rid of old loaded surface
		SDL_FreeSurface(newSurface);
	}
	
	return newTexture;
}

SpriteSheet colorKeyTexture;
bool loadMedia()
{
	//Loading success flag
	bool success = true;
	
	//Load splash image
	std::string path = "assets/map_sheet.png";
	if(!texture.loadFromFile(p_renderer, path))
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		success = false;
	}
	
//	if (!colorKeyTexture.loadFromFile(renderer, "sprites_magenta.png"))
//	{
//		success = false;
//	}
	
	return success;
}

void close()
{
	colorKeyTexture.free();
	texture.free();
	
	SDL_DestroyRenderer(p_renderer);
	p_renderer = NULL;
	SDL_DestroyWindow(p_window);
	p_window = NULL;
	
	IMG_Quit();
	SDL_Quit();
}

IntVector2 direction(0, 0);
int main( int argc, char* args[] )
{
	int a = 12;
	int b = 2;
	std::cout << "The sum of " << a << " and " << b << " is " << add(a, b) << '\n';
	Vector2 v2;
	std::cout << v2.x << " " << v2.y << '\n';
	
	SDL_Rect *rects = unpack();
	
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if(!loadMedia())
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
			
			//Event handler
			SDL_Event e;
			
			initTimeUtils();
			
			initDialogueBox();
			
			initGrid(p_renderer);
			
			initCharacterManager(p_renderer);
			noiseInit();
			
			SpriteSheet sp;
			
			GameObject go;
			go.p_view()->p_gameObject()->p_view()->p_gameObject()->p_transform()->p_gameObject()->p_view()->p_gameObject()->p_transform()->setPosition(5, 2);
			std::cout << "testing: " << go.p_view()->p_gameObject()->p_transform()->getPosition().x << "\n";
			
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
							case SDLK_w:
//								std::cout << "up" << '\n';
//								setGridPos({0, 1});
								direction.y = -1;
								break;
							case SDLK_a:
//								std::cout << "left" << '\n';
//								setGridPos({1, 0});
								direction.x = -1;
								break;
							case SDLK_s:
//								std::cout << "down" << '\n';
//								setGridPos({0, -1});
								direction.y = 1;
								break;
							case SDLK_d:
//								std::cout << "right" << '\n';
//								setGridPos({-1, 0});
								direction.x = 1;
								break;
						}
					}
					else if (e.type == SDL_KEYUP)
					{
						switch (e.key.keysym.sym) {
							case SDLK_w:
								direction.y = 0;
								showDialogueMessage(p_renderer, "ONUR! tesitslhd\nasdasdasdasdasdad\nwwwwwwwwwwwwwwwww");
								break;
							case SDLK_a:
								direction.x = 0;
								closeDialogueBox();
								break;
							case SDLK_s:
								direction.y = 0;
								break;
							case SDLK_d:
								direction.x = 0;
								break;
						}
					}
				}
				
				updateTimeUtils();
				
//				moveGrid(direction);
				moveCharacter(direction);
				
				Vector2 deltaPos = {getCharacterPosition().x - getCameraPosition().x, getCharacterPosition().y - getCameraPosition().y};
				deltaPos.x -= SCREEN_WIDTH / 2;
				deltaPos.y -= SCREEN_HEIGHT / 2;
				deltaPos.x /= 50;
				deltaPos.y /= 30;
				translateCamera(deltaPos);
				
				// Clear screen
				SDL_RenderClear(p_renderer);
				
//				SDL_Rect clipRect = {0, 0, 16, 16};
//				colorKeyTexture.render(renderer, 0, 0, &clipRect);
				
				// Render texture to screen
//				SDL_Rect rect = rects[13];
//				rect.x = rect.y = 0;
//				rect.w = 16;
//				rect.h = 16;
//				texture.render(renderer, 0, 0, &rect);
				
				renderGrid(p_renderer);
				
				renderCharacters(p_renderer);
				
				renderDialogueBox(p_renderer);
				
//				noiseDraw(renderer);
				
				// Update screen
				SDL_RenderPresent(p_renderer);
				
				// Delay a bit to release CPU
				SDL_Delay(16);
			}
		}
	}
	
	//Free resources and close SDL
	close();
	
	return 0;
}
