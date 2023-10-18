#include "CLane.h"
#include "CGame.h"
CLane::CLane()
{
	coorX = CGame::getCoorTopLeftX();
	coorY = 0;
	width = CGame::getWidth();
	height = lane;
}
void CLane::drawRoad()
{

	CGame::fillRect(coorX, coorY+1, 0, width - 1, 254, laneColor);
	CGame::fillRect(coorX, coorY+1 , height / 2-2 , width - 1, 219, laneColor);
	CGame::fillRect(coorX, coorY + height / 2, 0, width - 1, 219, laneColor);

}
