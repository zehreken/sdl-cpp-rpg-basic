/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
 and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "primitives/primitives.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The surface contained by the window
SDL_Surface *gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface *gXOut = NULL;

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
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	
	//Load splash image
	gXOut = SDL_LoadBMP( "x.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "x.bmp", SDL_GetError() );
		success = false;
	}
	
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;
	
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	int a = 12;
	int b = 2;
	std::cout << "The sum of " << a << " and " << b << " is " << add(a, b) << '\n';
	Vector2 v2;
	std::cout << v2.x << " " << v2.y << '\n';
	
	Vector3 v3;
	std::cout << v3.z << '\n';
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
			
			//Event handler
			SDL_Event e;
			
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
						switch (e.key.keysym.sym) {
							case SDLK_w:
								std::cout << "up" << '\n';
								break;
							case SDLK_a:
								std::cout << "left" << '\n';
								break;
							case SDLK_s:
								std::cout << "down" << '\n';
								break;
							case SDLK_d:
								std::cout << "right" << '\n';
								break;
							default:
								break;
						}
					}
				}
				
				//Apply the image
				SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );
				
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}
	
	//Free resources and close SDL
	close();
	
	return 0;
}
