#include "grid.hpp"
#include "perlinNoise.hpp"
#include "../gameObject/gameObject.hpp"

const int COLUMN_COUNT = 200;
const int ROW_COUNT = 120;
SpriteSheet spriteSheet;
GameObject tiles[COLUMN_COUNT * ROW_COUNT];

Vector2 gridPos;
PerlinNoise pN(0);

void initGrid(SDL_Renderer *p_renderer)
{
	gridPos = {0, 0};
	spriteSheet.loadFromFile(p_renderer, "map_sheet.png");
	
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			GameObject *tile = &tiles[row * COLUMN_COUNT + column];
			tile->setSpriteSheet(&spriteSheet);
//			*tile = GameObject(p_renderer, &spriteSheet);
			tile->p_transform()->setPosition(column, row);
//			tile->gridPos = {column, row};
			tile->p_view()->clipRect = {0, 0, 16, 16};
//			double noise = pN.noise(column / (double)COLUMN_COUNT, row / (double)ROW_COUNT, 0);
////			tile->clipPos = {rand() % 3 * 17, rand() % 3 * 17};
//			if (noise < 0.35)
//				tile->clipPos = {0, 0};
//			else if (noise >= 0.35 && noise < 0.45)
//				tile->clipPos = {3 * 17, 7 * 17};
//			else if (noise >= 0.45 && noise < 0.6)
//				tile->clipPos = {5 * 17, 0};
//			else if (noise >= 0.6 && noise < 0.7)
//				tile->clipPos = {3 * 17, 16 * 17};
//			else if (noise >= 0.7)
//				tile->clipPos = {6 * 17, 0};
			
			// values have to be normalized
//			printf("%f\n", noise);
		}
	}
}

void renderGrid(SDL_Renderer *renderer)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			GameObject *tile = &tiles[row * COLUMN_COUNT + column];
//			SDL_Rect clipRect;
//			clipRect.x = tile->clipPos.x;
//			clipRect.y = tile->clipPos.y;
//			clipRect.w = 16;
//			clipRect.h = 16;
//			tile->ltexture->render(renderer, column * 16 + (int)gridPos.x, row * 16 + (int)gridPos.y, &clipRect);
			tile->update(0, renderer);
		}
	}
}

void setGridPos(Vector2 delta)
{
	gridPos.x += delta.x;
	gridPos.y += delta.y;
}

void closeGrid()
{
	
}
