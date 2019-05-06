#include "grid.hpp"

const int COLUMN_COUNT = 100;
const int ROW_COUNT = 60;
LTexture ltexture;
Tile tiles[COLUMN_COUNT * ROW_COUNT];

Tile::Tile()
{
	ltexture = NULL;
	gridPos = {0, 0};
	clipPos = {0, 0};
}

void grid_init(SDL_Renderer *renderer)
{
	ltexture.loadFromFile(renderer, "sprites.png");
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			Tile *tile = &tiles[row * COLUMN_COUNT + column];
			tile->ltexture = &ltexture;
			tile->gridPos = {column, row};
			tile->clipPos = {rand() % 3 * 17, rand() % 3 * 17};
		}
	}
}

void grid_render(SDL_Renderer *renderer)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			Tile *tile = &tiles[row * COLUMN_COUNT + column];
			SDL_Rect clipRect;
			clipRect.x = tile->clipPos.x;
			clipRect.y = tile->clipPos.y;
			clipRect.w = 16;
			clipRect.h = 16;
			tile->ltexture->render(renderer, column * 64, row * 64, &clipRect);
		}
	}
}

void grid_close()
{
	
}
