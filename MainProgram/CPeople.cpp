#include "CPeople.h"


CPeople::CPeople()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2 - 2;       //bottom left
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight() / 2-2 ;
	height = 6;
	width = 8;
	color = Black;
	backColor = paveColor;
	drawPeople(color);
}


void CPeople::moveUp() {   // test, not real
	coorY -= 3;
	if (!isInBoard()) coorY += 3;
}
void CPeople::moveDown() {
	coorY += 3;
	if (!isInBoard()) coorY -= 3;
}
void CPeople::moveLeft() {
	coorX -= 4;
	if (!isInBoard()) coorX += 4;
}
void CPeople::moveRight() {
	coorX += 4;
	if (!isInBoard()) coorX -= 4;
}
void CPeople::drawPeople(bool isForRemove)
{
	int x = coorX;
	int y = coorY;
	int bcl0 = -1, bcl1 = -1, bcl2 = -1;
	CGame::relaxBackGround(y, bcl0);
	CGame::relaxBackGround(y - 1, bcl1);
	CGame::relaxBackGround(y - 2, bcl2);
	if (!isForRemove) {
		


		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);

		x++;
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, botBlock, DarkRed, bcl1);

		x++;
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, block, DarkRed, bcl1);


		x++;
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);

		x++;
		CConsole::drawChar(x, y, block, Black, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, topBlock, Black, DarkGreen);

		x++;
		CConsole::drawChar(x, y, topBlock, Black, bcl0);
		CConsole::drawChar(x, y - 1, block, Black, bcl1);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);

		x++;
		CConsole::drawChar(x, y, block, Black, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, topBlock, Black, DarkGreen);

		x++;
		//CConsole::drawChar(x, y, topBlock, DarkRed, backColor);
		CConsole::drawChar(x, y - 1, topBlock, Black, bcl1);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);
	}
	else {
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);

		x++;
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, botBlock, bcl1, bcl1);

		x++;
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, block, bcl1, bcl1);


		x++;
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);

		x++;
		CConsole::drawChar(x, y, block, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, topBlock, bcl2, bcl2);

		x++;
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, block, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);

		x++;
		CConsole::drawChar(x, y, block, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, topBlock, bcl2, bcl2);

		x++;
		//CConsole::drawChar(x, y, topBlock, DarkRed, backColor);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);
	}
}

void CPeople::peopleMoving(char c)
{

	drawPeople(true);
	if (c == 'w') moveUp();
	else if (c == 'a') moveLeft();
	else if (c == 's') moveDown();
	else if (c == 'd') moveRight();

	drawPeople();
	//CGame::drawRoad();

}

bool CPeople::isInBoard()
{
	bool b1 = coorX >= CGame::getCoorTopLeftX() && (coorX + width) <= CGame::getCoorTopLeftX() + CGame::getWidth();
	bool b2 = (coorY - height / 2) >= CGame::getCoorTopLeftY() && coorY <= CGame::getCoorTopLeftY() + CGame::getHeight() / 2;
	return b1 && b2;
}
