//
// Created by IGRec on 19 Jun 2020.
//

#include "globals.h"

bool GameOver = false;

bool Vector2Compare(Vector2 v1, Vector2 v2)
{
	return (v1.x == v2.x) && (v1.y == v2.y);
}
int PositiveModulo(int a, int b)
{
	return ((a % b) + b) % b;
}