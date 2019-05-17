#include "grid.hpp"
#include "perlinNoise.hpp"
#include "../gameObject/gameObject.hpp"
#include "../utils/timeUtils.hpp"

const int COLUMN_COUNT = 200;
const int ROW_COUNT = 120;
SpriteSheet spriteSheet;
GameObject tiles[COLUMN_COUNT * ROW_COUNT];

PerlinNoise pN(0);

Transform gridTransform;

void initGrid(SDL_Renderer *p_renderer)
{
	spriteSheet.loadFromFile(p_renderer, "map_sheet.png");
	
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			GameObject *tile = &tiles[row * COLUMN_COUNT + column];
			
			tile->setSpriteSheet(&spriteSheet);
			tile->p_transform()->setParent(&gridTransform);
			tile->p_transform()->setPosition(column * 16, row * 16);
			double noise = pN.noise(column / (double)COLUMN_COUNT, row / (double)ROW_COUNT, 0);
			if (noise < 0.35)
				tile->p_view()->clipRect = {0, 0, 16, 16};
			else if (noise >= 0.35 && noise < 0.45)
				tile->p_view()->clipRect = {3 * 17, 7 * 17, 16, 16};
			else if (noise >= 0.45 && noise < 0.6)
				tile->p_view()->clipRect = {5 * 17, 0, 16, 16};
			else if (noise >= 0.6 && noise < 0.7)
				tile->p_view()->clipRect = {3 * 17, 16 * 17, 16, 16};
			else if (noise >= 0.7)
				tile->p_view()->clipRect = {6 * 17, 0, 16, 16};
			
			// values have to be normalized
//			printf("%f\n", noise);
		}
	}
}

void renderGrid(SDL_Renderer *p_renderer)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			GameObject *tile = &tiles[row * COLUMN_COUNT + column];
//			GameObject *tile = p_tiles[row * COLUMN_COUNT + column];
//			SDL_Rect clipRect;
//			clipRect.x = tile->clipPos.x;
//			clipRect.y = tile->clipPos.y;
//			clipRect.w = 16;
//			clipRect.h = 16;
//			tile->ltexture->render(renderer, column * 16 + (int)gridPos.x, row * 16 + (int)gridPos.y, &clipRect);
			tile->update(getDeltaTimeInSeconds(), p_renderer);
		}
	}
}

void moveGrid(IntVector2 direction)
{
	const float SPEED = 500;
	
	if ((direction.x < 0 && gridTransform.getPosition().x <= 960 - COLUMN_COUNT * 16)
		|| (direction.x > 0 && gridTransform.getPosition().x >= 0)
		|| (direction.y < 0 && gridTransform.getPosition().y <= 540 - ROW_COUNT * 16)
		|| (direction.y > 0 && gridTransform.getPosition().y >= 0))
		return;
	gridTransform.translate(direction.x * SPEED * getDeltaTimeInSeconds(), direction.y * SPEED * getDeltaTimeInSeconds());
}

void setGridPos(Vector2 delta)
{
//	gridPos.x += delta.x;
//	gridPos.y += delta.y;
	gridTransform.translate(delta.x, delta.y);
}

void closeGrid()
{
	
}
