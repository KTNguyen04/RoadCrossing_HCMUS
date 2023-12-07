#include "CRiver.h"
#include "CGame.h"
CRiver::CRiver()
{
		coorX = CGame::getCoorTopLeftX();
		coorY = 0;
		width = CGame::getWidth();
		height = lane;
		color = riverColor;
}
