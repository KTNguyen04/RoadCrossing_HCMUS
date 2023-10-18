#include "CRiver.h"
#include "CGame.h"
void CRiver::drawRoad()
{
	CGame::fillRect(coorX, coorY, 0, CGame::getWidth() - 1, 220, laneColor);
	CGame::fillRect(coorX, coorY + 1, lane / 2 - 2, CGame::getWidth() - 1, 219, laneColor);
	CGame::fillRect(coorX, coorY + lane / 2, 0, CGame::getWidth() - 1, 219, laneColor);
}
