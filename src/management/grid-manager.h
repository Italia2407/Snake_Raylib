//
// Created by IGRec on 14 Jun 2020.
//

#include "../globals.h"

#ifndef SNAKE_GRID_MANAGER_H
#define SNAKE_GRID_MANAGER_H

extern Color GridLineColour;

Vector2 GridToScreenSpace(Vector2 position);

void DrawGridLines();

#endif //SNAKE_GRID_MANAGER_H
