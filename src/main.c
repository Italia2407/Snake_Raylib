#include "globals.h"
#include "management/grid-manager.h"
#include "objects/snake.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(FPS_CAP);
    
    Snake snake = InitSnake((Vector2){7, 0}, SD_RIGHT, BLUE);

    // Main game loop
    while (!WindowShouldClose())
    {
    	UpdateSnake(&snake);
    	
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawSnake(snake);
        DrawGridLines();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}