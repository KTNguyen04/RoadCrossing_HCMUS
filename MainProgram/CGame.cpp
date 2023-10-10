#include "CGame.h"


int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 1;
int CGame::frameWidth = 84;
int CGame::frameHeight = 28;
CGame::CGame()
{
	drawBackGround();

}

void CGame::drawBackGround()
{
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY, 220, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX, 219, Black);
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY + frameHeight * 2 - 1, 223, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX + frameWidth - 1, 219, Black);


	CConsole::drawHorLine(3, 84, 8, Ngang, Black);
	CConsole::drawHorLine(3, 84, 16, Ngang, Black);
	CConsole::drawHorLine(3, 84, 20, Ngang, Black);
	CConsole::drawHorLine(3, 84, 28, Ngang, Black);
	CConsole::drawHorLine(3, 84, 32, Ngang, Black);
	CConsole::drawHorLine(3, 84, 40, Ngang, Black);
	CConsole::drawHorLine(3, 84, 44, Ngang, Black);
	CConsole::drawHorLine(3, 84, 52, Ngang, Black);




}

int CGame::getWidth()
{
	return frameWidth;
}

int CGame::getHeight()
{
	return frameHeight;
}

int CGame::getCoorTopLeftX()
{
	return coorTopLeftX;
}

int CGame::getCoorTopLeftY()
{
	return coorTopLeftY;
}

