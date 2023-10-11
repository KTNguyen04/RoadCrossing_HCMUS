#include "CPeople.h"


CPeople::CPeople()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2 - 1;
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight() - 2;
	height = 1;
	width = 2;
	color = Black;
	drawPeople(color);
}


void CPeople::moveUp() {   // test, not real
	coorY -= 1.5;
	if (!isInBoard()) coorY += 2;
}
void CPeople::moveDown() {
	coorY += 2;                       // do hàm vẽ có sử dụng /2 
	if (!isInBoard()) coorY -= 1.5;
}
void CPeople::moveLeft() {
	coorX -= 4;
	if (!isInBoard()) coorX += 4;
}
void CPeople::moveRight() {
	coorX += 4;
	if (!isInBoard()) coorX -= 4;
}
void CPeople::drawPeople(int pColor)
{
	CConsole::drawHorLine(coorX, coorX + width, coorY * 2, 220, pColor);
	CConsole::drawHorLine(coorX, coorX + width, coorY * 2 - height, 220, pColor);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX, 219, pColor);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX + width, 219, pColor);
}

void CPeople::peopleMoving(char c)
{

	drawPeople(White);      //sau này đổi thành màu color(background)
	if (c == 'w') moveUp();
	else if (c == 'a') moveLeft();
	else if (c == 's') moveDown();
	else if (c == 'd') moveRight();

	CGame::drawRoad();
	drawPeople(color);

}

bool CPeople::isInBoard()
{
	bool b1 = coorX >= CGame::getCoorTopLeftX() && coorX <= CGame::getCoorTopLeftX() + CGame::getWidth() -1 ;
	bool b2 = coorY >= CGame::getCoorTopLeftY() +2  && coorY <= CGame::getCoorTopLeftX() + CGame::getHeight() - 2;
	return b1 && b2;
}
