#include "CGame.h"


int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 1;
int CGame::frameWidth = 85;
int CGame::frameHeight = 28;
CGame::CGame()
{
	drawFrame();
	drawRoad();

}

void CGame::drawFrame()
{
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY, 220, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX, 219, Black);
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY + frameHeight * 2 - 1, 223, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX + frameWidth - 1, 219, Black);




}

void CGame::drawRoad()
{
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 8, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 16, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 20, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 28, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 32, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 40, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 44, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 52, Ngang, Black);
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


void CGame::insertRectSpace(int x, int y, int height, int width, int color)
{
	for (int i = y; i >= y - height; i--) {
		CConsole::drawHorLine(x, x + width, i, 219, color);
	}
}

void CGame::runGame()
{
	CPeople people;
	while (1) {
		char c = CConsole::getInput();
		people.peopleMoving(c);
	}
}

