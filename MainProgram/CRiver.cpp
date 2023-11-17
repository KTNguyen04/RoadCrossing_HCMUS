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
//void CRiver::drawRoad()
//{
//	CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2, block, riverColor, background);
//	CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2 + 1, block, riverColor, background);
//	CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2 + 2, block, riverColor, background);
//	CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2 + 3, block, riverColor, background);
//	CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2 + 4, block, riverColor, background);
//	////CGame::fillRect(coorX, coorY+1, 0, width - 1, block, laneColor);
//	////CGame::fillRect(coorX, coorY+1 , height / 2-2 , width - 1, block, laneColor);
//	////CGame::fillRect(coorX, coorY + height / 2, 0, width - 1, block, laneColor);
//	//CConsole::drawHorLine(coorX, coorX + width - 1, coorY / 2 + lane / 2, topBlock, riverColor, background);
//}
