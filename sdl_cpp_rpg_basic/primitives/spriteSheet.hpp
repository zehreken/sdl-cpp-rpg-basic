#ifndef spriteSheet_hpp
#define spriteSheet_hpp
#include <iostream>
#include <SDL2_image/SDL_image.h>

class SpriteSheet
{
public:
	SpriteSheet();
	
	~SpriteSheet();
	
	bool loadFromFile(SDL_Renderer *renderer, std::string path);
	
	void free();
	
	void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clipRect = NULL);
	
	int getWidth();
	int getHeight();
private:
	SDL_Texture *texture;
	
	int width;
	int height;
};

#endif /* spriteSheet_hpp */
