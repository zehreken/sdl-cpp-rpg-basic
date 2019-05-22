#include "characterManager.hpp"
#include "../gameObject/gameObject.hpp"
#include "../utils/timeUtils.hpp"

SpriteSheet characterSheet;
GameObject character;

void initCharacterManager(SDL_Renderer *p_renderer)
{
	std::string path = "assets/character_sheet.png";
	characterSheet.loadFromFile(p_renderer, path);
	
	character.setSpriteSheet(&characterSheet);
	character.p_transform()->setPosition(0, 0);
	character.p_view()->clipRect = {0, 17 * 5, 16, 16};
}

void renderCharacters(SDL_Renderer *p_renderer)
{
	character.update(getDeltaTimeInSeconds(), p_renderer);
}

void moveCharacter(IntVector2 direction)
{
	const float SPEED = 200;
	character.p_transform()->translate(direction.x * SPEED * getDeltaTimeInSeconds(), direction.y * SPEED * getDeltaTimeInSeconds());
}

Vector2 getCharacterPosition()
{
	return character.p_transform()->getPosition();
}
