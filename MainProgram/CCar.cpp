#include "CCar.h"

CCar::CCar(int x, int y, string direct, int speed)
{
	width = carWidth;
	height = carHeight;
	coorX = x;
	coorY = y;
	backColor = laneColor;
	this->direct = direct;
	this->speed = speed;
	//if (isInBoard())
	drawObject();

}

//void CCar::move()
//{
//
//	Sleep(1);
//	//	if (isInBoard())
//	drawObject(true);
//	if (direct == "right") {//left to right
//		coorX += speed;
//		if ((coorX >= (CGame::getCoorTopLeftX() + CGame::getWidth())) && !isInit()) {
//			coorX -= CGame::getWidth();
//			coorX -= this->width;
//		}
//		//if (!isInBoard() && !isInit()) coorX = CGame::getCoorTopLeftX() + CGame::getWidth() - 1;
//	}
//	else if (direct == "left") {
//		coorX -= speed;
//
//		if ((coorX <= (CGame::getCoorTopLeftX() - this->width + 1)) && !isInit()) {
//			coorX += CGame::getWidth();
//			coorX += this->width;
//		}
//		//if (!isInBoard() && !isInit()) coorX += speed;
//	}
//
//	//CGame::drawRoad();
//	//coorX %= CGame::getWidth();
//
//	//if ( isInBoard())
//	drawObject();
//
//}

void CCar::drawObject(bool isForRemove)
{
	if (!isForRemove) {
		int x = coorX;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , botBlock, Black, White);
			CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
			CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			//CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 3, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 3, topBlock, Black, Blue);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 3, topBlock, Black, Blue);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 3, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , botBlock, Black, White);
			CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
			CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			//CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
		}

		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Red, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
			CConsole::drawChar(x, coorY - 2, topBlock, Black, Red);

		}

		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
			CConsole::drawChar(x, coorY - 2, block, Red, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, Black, backColor);

		}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, Black, backColor);

		}
	}
	else {
		int x = coorX;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
			//CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, topBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, topBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
			//CConsole::drawChar(x, coorY - 1, botBlock, Black, Red);
		}

		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY , topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, topBlock, backColor, backColor);

		}

		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);

		}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);

		}
	}
}

//
//bool CCar::isInBoard(bool isForDraw, int x)
//{
//	if (!isForDraw) {
//		bool b1 = coorX >= CGame::getCoorTopLeftX() && coorX <= CGame::getCoorTopLeftX() + CGame::getWidth() - 1;
//
//		return b1;
//	}
//
//	bool b1 = (x >= CGame::getCoorTopLeftX()) && (x <= (CGame::getCoorTopLeftX() + CGame::getWidth() -1));
//
//	return b1;
//}


//bool CCar::isInit() {
//	return  (coorX <= CGame::getCoorTopLeftX() - this->width) || (coorX >= CGame::getCoorTopLeftX() + CGame::getWidth() + 1);
//}
