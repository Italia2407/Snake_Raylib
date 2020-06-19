//
// Created by IGRec on 14 Jun 2020.
//

#include "raymath.h"

#ifndef SNAKE_GLOBALS_H
#define SNAKE_GLOBALS_H

#define CELLS_HORIZONTAL (42)
#define CELLS_VERTICAL (42)
#define CELL_SIZE (24)

#define SCREEN_WIDTH (CELLS_HORIZONTAL * CELL_SIZE)
#define SCREEN_HEIGHT (CELLS_VERTICAL * CELL_SIZE)

#define FPS_CAP (60)

#define ASSET_PATH "../assets/"

extern bool GameOver;

bool Vector2Compare(Vector2 v1, Vector2 v2);
int PositiveModulo(int a, int b);

#endif //SNAKE_GLOBALS_H
