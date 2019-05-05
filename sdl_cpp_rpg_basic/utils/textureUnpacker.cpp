#include "textureUnpacker.hpp"

const int WIDTH = 968;
const int HEIGHT = 526;
const int SIZE = 16;
const int COLUMN_COUNT = (WIDTH - 1) / (SIZE + 1);
const int ROW_COUNT = (HEIGHT - 1) / (SIZE + 1);

SDL_Rect *unpack()
{
	static SDL_Rect rects[COLUMN_COUNT * ROW_COUNT];
	
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			rects[row * COLUMN_COUNT + column] = {row * 17, column * 17, 16, 16};
		}
	}
	
	return rects;
}
