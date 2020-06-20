//
// Created by IGRec on 16 Jun 2020.
//

#include "edible.h"
#include "../management/grid-manager.h"

#define MAX_EDIBLE_COUNT 16
static Edible Edibles[MAX_EDIBLE_COUNT] = {0};
static int EdiblesCount = 0;

void SpawnEdible(Vector2 position)
{
	if (EdiblesCount < MAX_EDIBLE_COUNT)
	{
		Edibles[EdiblesCount] = (Edible){
			.position = position,
			.colour = RED
		};
		EdiblesCount++;
	}
}

bool CheckEdiblesCollision(Snake snake)
{
	for (int i = 0; i < EdiblesCount; i++)
	{
		if (Vector2Compare(Edibles[i].position, snake.headPosition))
		{
			// Remove the current edible
			for (int j = i; j < EdiblesCount-1; j++)
			{
				Edibles[j] = Edibles[j+1];
			}
			EdiblesCount--;
			return true;
		}
	}
	return false;
}

void DrawEdibles()
{
	for (int i = 0; i < EdiblesCount; i++)
	{
		Vector2 screenSpace = GridToScreenSpace(Edibles[i].position);
		Rectangle rect = {
				.x = screenSpace.x,
				.y = screenSpace.y,
				.width = CELL_SIZE,
				.height = CELL_SIZE
		};
		
		DrawRectangleRec(rect, Edibles[i].colour);
	}
}