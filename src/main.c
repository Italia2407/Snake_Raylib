#include "globals.h"
#include "management/grid-manager.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(FPS_CAP);

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawGridLines();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}