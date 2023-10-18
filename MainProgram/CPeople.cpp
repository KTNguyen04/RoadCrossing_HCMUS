#include "CPeople.h"


CPeople::CPeople()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2-2 ;       //bottom left
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight()/2 - 1;
	height = 6;
	width = 6;
	color = Black;
	backColor = paveColor;
	drawPeople(color);
}


void CPeople::moveUp() {   // test, not real
	coorY -= 3;
	if (!isInBoard()) coorY += 3;
}
void CPeople::moveDown() {
	coorY += 3;                       // do hàm vẽ có sử dụng /2 
	if (!isInBoard()) coorY -= 3;
}
void CPeople::moveLeft() {
	coorX -= 3;
	if (!isInBoard()) coorX += 3;
}
void CPeople::moveRight() {
	coorX += 3;
	if (!isInBoard()) coorX -= 3;
}
void CPeople::drawPeople(int pColor)
{
	CConsole::drawHorLine(coorX, coorX + width, coorY , 220, pColor);
	CConsole::drawHorLine(coorX, coorX + width, coorY - height/2, 220, pColor);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX, 220, pColor);
	CConsole::drawVerLine(coorY - height / 2, coorY, coorX + width, 220, pColor);
}

void CPeople::peopleMoving(char c)
{

	drawPeople(White);      //sau này đổi thành màu color(background)
	if (c == 'w') moveUp();
	else if (c == 'a') moveLeft();
	else if (c == 's') moveDown();
	else if (c == 'd') moveRight();

	drawPeople(color);
	//CGame::drawRoad();

}

bool CPeople::isInBoard()
{
	bool b1 = coorX >= CGame::getCoorTopLeftX()  && (coorX+width) <= CGame::getCoorTopLeftX() + CGame::getWidth()  ;
	bool b2 = (coorY - height/2) >= CGame::getCoorTopLeftY()   &&coorY<= CGame::getCoorTopLeftY() + CGame::getHeight()/2 - 2;
	return b1 && b2;
}
