#include "noiseVisualizer.hpp"
#include "perlinNoise.hpp"

const int COLUMN_COUNT = 200;
const int ROW_COUNT = 120;
static PerlinNoise pN(0);
double noises[COLUMN_COUNT * ROW_COUNT];

void noiseInit()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			noises[row * COLUMN_COUNT + column] = pN.noise(column / (double)COLUMN_COUNT, row / (double)ROW_COUNT, 0);
		}
	}
}

void noiseDraw(SDL_Renderer *renderer)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			double noise = noises[row * COLUMN_COUNT + column];
			
			SDL_SetRenderDrawColor(renderer, 0xFF * noise, 0xFF * (1 - noise), 0x00, 0xFF);
			SDL_RenderDrawPoint(renderer, column, row);
			
			// values have to be normalized
			printf("%f\n", noise);
		}
	}
}
