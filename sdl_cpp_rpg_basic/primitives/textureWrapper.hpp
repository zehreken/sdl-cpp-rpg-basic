#ifndef textureWrapper_hpp
#define textureWrapper_hpp
#include <iostream>
#include <SDL2_image/SDL_image.h>

class LTexture
{
public:
	LTexture();
	
	~LTexture();
	
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

#endif /* textureWrapper_hpp */
