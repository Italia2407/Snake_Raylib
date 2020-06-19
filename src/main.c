#include "globals.h"
#include "management/grid-manager.h"
#include "objects/snake.h"
#include "objects/edible.h"

#define EDIBLE_SPAWN_FRAME_BUFFER (180)
static int SpawnFrameBuffer = 0;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(FPS_CAP);
    
    Snake snake = InitSnake((Vector2){7, 0}, SD_RIGHT, BLUE);

    // Main game loop
    while (!WindowShouldClose())
    {
    	if (!GameOver && (snake.length < MAX_SNAKE_LENGTH))
		{
			if (SpawnFrameBuffer >= EDIBLE_SPAWN_FRAME_BUFFER)
			{
				SpawnFrameBuffer = 0;
				
				Vector2 position = {
						.x = GetRandomValue(0, CELLS_HORIZONTAL - 1),
						.y = GetRandomValue(0, CELLS_VERTICAL - 1)
				};
				position.x = PositiveModulo((int)position.x, CELLS_HORIZONTAL);
				position.y = PositiveModulo((int)position.y, CELLS_VERTICAL);
				SpawnEdible(position);
			}
			SpawnFrameBuffer++;
			
			UpdateSnake(&snake);
		}
    	
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawSnake(snake);
        DrawEdibles();
        DrawGridLines();
        
        if (GameOver)
		{
        	DrawText("GAME OVER!", 24, 24, 72.0f, BLACK);
		} else if (snake.length == MAX_SNAKE_LENGTH)
		{
			DrawText("YOU WON!!!", 24, 24, 72.0f, BLACK);
		}

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}