#include "CLane.h"
#include "CGame.h"
CLane::CLane()
{
	coorX = CGame::getCoorTopLeftX();
	coorY = 0;
	width = CGame::getWidth();
	height = lane;
	color = laneColor;
}
