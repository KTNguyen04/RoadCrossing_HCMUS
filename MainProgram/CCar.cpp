#include "CCar.h"

CCar::CCar(int x,int y)
{
	coorX = x;
	coorY = y;
	width = 6;
	height = 4;
	drawObject(Black);
	
}

void CCar::move(string direct)
{
	
	drawObject(White);
	if (direct == "right") {//left to right
		//coorX += 1;
	}
	//CGame::drawRoad();
	drawObject(Black);
}

void CCar::drawObject(int color)
{
	CConsole::drawHorLine(coorX, coorX + width, coorY * 2, 220, color);
	CConsole::drawHorLine(coorX, coorX + width, coorY * 2 - height, 220, color);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX, 220, color);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX + width, 220, color);
}
