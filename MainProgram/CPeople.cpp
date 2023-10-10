#include "CPeople.h"


CPeople::CPeople()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2 - 1;
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight() - 2;
	height = 1;
	width = 2;
	drawPeople();
}


void CPeople::moveUp() {   // test, not real
	coorY += 1;
}
void CPeople::moveDown() {
	coorY -= 1;
}
void CPeople::moveLeft() {
	coorX -= 2;
}
void CPeople::moveRight() {
	coorX += 2;
}
void CPeople::drawPeople()
{
	CConsole::drawHorLine(coorX, coorX + width, coorY*2, 220, Black);
	CConsole::drawHorLine(coorX-1, coorX + width, coorY*2- height, 220, Black);
	CConsole::drawVerLine(coorY - height/2 , coorY  , coorX-1, 219, Black);
	CConsole::drawVerLine(coorY - height/2 , coorY  , coorX + width, 219, Black);



}
