//
// Created by IGRec on 14 Jun 2020.
//

#include "snake.h"
#include "edible.h"
#include "../management/grid-manager.h"

#define MOVEMENT_FRAME_BUFFER (10)
static int FrameCount = 0;

Snake InitSnake(Vector2 position, SnakeDirection direction, Color colour)
{
	Snake newSnake = {0};
	
	newSnake.headPosition = position;
	newSnake.direction = direction;
	newSnake.nextDirection = direction;
	newSnake.colour = colour;
	
	newSnake.headPosition.x = (int)newSnake.headPosition.x % CELLS_HORIZONTAL;
	newSnake.headPosition.y = (int)newSnake.headPosition.y % CELLS_VERTICAL;
	
	return newSnake;
}

void UpdateSnake(Snake* snake)
{
	// Get tail location in case snake has to grow
	{
		Vector2 tailPosition;
		if (snake->length >= 1)
			tailPosition = snake->segmentPositions[snake->length-1];
		else
			tailPosition = snake->headPosition;
		
		if (snake->length < MAX_SNAKE_LENGTH)
		{
			snake->segmentPositions[snake->length] = tailPosition;
		}
	}
	
	// Movement
	//------------------------------------------------------------------------------------------------------------------
	// Change movement direction
	if (IsKeyPressed(KEY_W) && (snake->direction != SD_DOWN))
	{
		snake->nextDirection = SD_UP;
	}
	if (IsKeyPressed(KEY_S) && (snake->direction != SD_UP))
	{
		snake->nextDirection = SD_DOWN;
	}
	if (IsKeyPressed(KEY_A) && (snake->direction != SD_RIGHT))
	{
		snake->nextDirection = SD_LEFT;
	}
	if (IsKeyPressed(KEY_D) && (snake->direction != SD_LEFT))
	{
		snake->nextDirection = SD_RIGHT;
	}
	
	if (FrameCount > MOVEMENT_FRAME_BUFFER)
	{
		FrameCount = 0;
		
		// Move segments
		for (int i = snake->length; i > 1; i--)
		{
			snake->segmentPositions[i-1] = snake->segmentPositions[i-2];
		}
		snake->segmentPositions[0] = snake->headPosition;
		
		// Move head
		snake->direction = snake->nextDirection;
		
		switch (snake->nextDirection)
		{
			case SD_UP:
			{
				snake->headPosition.y -= 1;
				break;
			}
			case SD_DOWN:
			{
				snake->headPosition.y += 1;
				break;
			}
			case SD_LEFT:
			{
				snake->headPosition.x -= 1;
				break;
			}
			case SD_RIGHT:
			{
				snake->headPosition.x += 1;
				break;
			}
		}
		
		snake->headPosition.x = PositiveModulo((int)snake->headPosition.x, CELLS_HORIZONTAL);
		snake->headPosition.y = PositiveModulo((int)snake->headPosition.y, CELLS_VERTICAL);
		
		//snake->direction = snake->nextDirection;
	}
	
	// Check if it collided with itself
	for (int i = 3; i < snake->length; i++)
	{
		if (Vector2Compare(snake->headPosition, snake->segmentPositions[i]))
		{
			GameOver = true;
			break;
		}
	}
	
	// Check if it collided with an edible
	if (CheckEdiblesCollision(*snake))
	{
		snake->length++;
	}
	FrameCount++;
	//------------------------------------------------------------------------------------------------------------------
}

void DrawSnake(Snake snake)
{
	// Draw head
	Vector2 headScreenSpace = GridToScreenSpace(snake.headPosition);
	Rectangle headRect = {
			.x = headScreenSpace.x,
			.y = headScreenSpace.y,
			.width = CELL_SIZE,
			.height = CELL_SIZE
	};
	DrawRectangleRec(headRect, snake.colour);
	
	for (int i = 0; i < snake.length; i++)
	{
		Vector2 segmentScreenSpace = GridToScreenSpace(snake.segmentPositions[i]);
		Rectangle segmentRect = {
				.x = segmentScreenSpace.x,
				.y = segmentScreenSpace.y,
				.width = CELL_SIZE,
				.height = CELL_SIZE
		};
		DrawRectangleRec(segmentRect, snake.colour);
	}
}