//
// Created by IGRec on 14 Jun 2020.
//

#include "grid-manager.h"

Color GridLineColour = BLACK;

Vector2 GridToScreenSpace(Vector2 position)
{
	Vector2 screenSpace = {
			.x = position.x * CELL_SIZE,
			.y = position.y * CELL_SIZE
	};
	
	return screenSpace;
}

void DrawGridLines()
{
	for (int x = 0; x < CELLS_HORIZONTAL; x++)
	{
		DrawLine(x*CELL_SIZE, 0, x*CELL_SIZE, SCREEN_HEIGHT, GridLineColour);
	}
	for (int y = 0; y < CELLS_VERTICAL; y++)
	{
		DrawLine(0, y*CELL_SIZE, SCREEN_WIDTH, y*CELL_SIZE, GridLineColour);
	}
}