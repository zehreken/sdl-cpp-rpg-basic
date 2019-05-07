#include "grid.hpp"
#include "perlinNoise.hpp"

const int COLUMN_COUNT = 100;
const int ROW_COUNT = 60;
LTexture ltexture;
Tile tiles[COLUMN_COUNT * ROW_COUNT];

Vector2 gridPos;
PerlinNoise pN(17);

Tile::Tile()
{
	ltexture = NULL;
	gridPos = {0, 0};
	clipPos = {0, 0};
}

void grid_init(SDL_Renderer *renderer)
{
	gridPos = {0, 0};
	ltexture.loadFromFile(renderer, "sprites.png");
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			Tile *tile = &tiles[row * COLUMN_COUNT + column];
			tile->ltexture = &ltexture;
			tile->gridPos = {column, row};
			double noise = pN.noise(column / (double)COLUMN_COUNT, row / (double)ROW_COUNT, 0);
//			tile->clipPos = {rand() % 3 * 17, rand() % 3 * 17};
			if (noise < 0.35)
				tile->clipPos = {0, 0};
			else if (noise >= 0.35 && noise < 0.45)
				tile->clipPos = {3 * 17, 7 * 17};
			else if (noise >= 0.45 && noise < 0.6)
				tile->clipPos = {5 * 17, 0};
			else if (noise >= 0.6 && noise < 0.7)
				tile->clipPos = {3 * 17, 16 * 17};
			else if (noise >= 0.7)
				tile->clipPos = {6 * 17, 0};
			
			// values have to be normalized
			printf("%f\n", noise);
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
			tile->ltexture->render(renderer, column * 16 + (int)gridPos.x, row * 16 + (int)gridPos.y, &clipRect);
		}
	}
}

void setGridPos(Vector2 delta)
{
	gridPos.x += delta.x;
	gridPos.y += delta.y;
}

void grid_close()
{
	
}
