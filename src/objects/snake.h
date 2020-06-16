//
// Created by IGRec on 14 Jun 2020.
//

#include "../globals.h"

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#define MAX_SNAKE_LENGTH (57)

typedef enum SnakeDirection
{
	SD_UP,
	SD_DOWN,
	SD_LEFT,
	SD_RIGHT
} SnakeDirection;

typedef struct Snake
{
	SnakeDirection direction;
	
	Vector2 headPosition;
	Vector2 segmentPositions[MAX_SNAKE_LENGTH];
	int length;
	
	Color colour;
} Snake;

Snake InitSnake(Vector2 position, SnakeDirection direction, Color colour);

void UpdateSnake(Snake* snake);

void DrawSnake(Snake snake);

#endif //SNAKE_SNAKE_H
