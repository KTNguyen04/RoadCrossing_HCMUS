#include "CCar.h"

CCar::CCar(int x, int y, int speed)
{
	width = carWidth;
	height = carHeight;
	coorX = x;
	coorY = y;
	this->speed = speed;
	if (isInBoard())
		drawObject(Black);

}

void CCar::move(string direct)
{
	
	Sleep(1);
	if (!isInit() && isInBoard())
	drawObject(White);
	if (direct == "right") {//left to right
		coorX+=speed;
		if (!isInBoard() && !isInit()) coorX = CGame::getCoorTopLeftX() + CGame::getWidth() - 1;
	}
	else if (direct == "left") {
		coorX -= speed;
		if (!isInBoard() && !isInit()) coorX += speed;
	}

	//CGame::drawRoad();
	coorX %= CGame::getWidth();
	if (!isInit() && isInBoard())
	drawObject(Black);

}

void CCar::drawObject(int color)
{
	int toX = coorX + width;
	if (toX > CGame::getCoorTopLeftX() + CGame::getWidth() - 2)
		toX = CGame::getCoorTopLeftX() + CGame::getWidth() - 2;

	int fromX = coorX;
	if (fromX <= CGame::getCoorTopLeftX()) 
		fromX = CGame::getCoorTopLeftX() + 1;
	
	
	CConsole::drawHorLine(fromX, toX-6, coorY * 2, 223, color);
	CConsole::drawHorLine(fromX+5, toX-1, coorY * 2 , 223, color);
	color = Blue;
	CConsole::drawHorLine(fromX-1, toX - 6, coorY * 2 - height+1, 219, color);
	CConsole::drawHorLine(toX-5, toX -1, coorY * 2 - height + 1, 220, color);
	CConsole::drawHorLine(toX , toX + 1, coorY * 2 - height + 1, 219, color);
	CConsole::drawHorLine(fromX, fromX+6, coorY * 2 - height , 220, color);
}


bool CCar::isInBoard()
{
	bool b1 = coorX >= CGame::getCoorTopLeftX() && coorX <= CGame::getCoorTopLeftX() + CGame::getWidth() - 1;
	return b1;
}

void CCar::setSpeed(int speed)
{
	this->speed = speed;
}


bool CCar::isInit() {
	return  coorX <= CGame::getCoorTopLeftX();
}
