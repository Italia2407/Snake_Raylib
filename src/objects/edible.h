//
// Created by IGRec on 16 Jun 2020.
//

#include "../globals.h"
#include "snake.h"

#ifndef SNAKE_EDIBLE_H
#define SNAKE_EDIBLE_H

typedef struct Edible
{
	Vector2 position;
	
	Color colour;
} Edible;

void SpawnEdible(Vector2 position);

bool CheckEdiblesCollision(Snake snake);

void DrawEdibles();

#endif //SNAKE_EDIBLE_H
