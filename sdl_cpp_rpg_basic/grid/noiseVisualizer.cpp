#include "noiseVisualizer.hpp"
#include "perlinNoise.hpp"

const int COLUMN_COUNT = 200;
const int ROW_COUNT = 120;
static PerlinNoise pN(20);

void noiseDraw(SDL_Renderer *renderer)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			double noise = pN.noise(column / (double)COLUMN_COUNT, row / (double)ROW_COUNT, 0);
			
			SDL_SetRenderDrawColor(renderer, 0xFF * noise, 0xFF * (1 - noise), 0x00, 0xFF);
			SDL_RenderDrawPoint(renderer, column, row);
			
			// values have to be normalized
			printf("%f\n", noise);
		}
	}
}
