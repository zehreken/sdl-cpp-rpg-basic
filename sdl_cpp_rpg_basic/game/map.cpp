#include "map.hpp"
#include "../primitives/spriteSheet.hpp"
#include "../gameObject/gameObject.hpp"

const int COLUMN_COUNT = 200;
const int ROW_COUNT = 120;
SpriteSheet spriteSheet;
static GameObject tiles[COLUMN_COUNT * ROW_COUNT];

void initMap(SDL_Renderer *renderer)
{
	spriteSheet.loadFromFile(renderer, "map_sheet.png");
}
