#include "CCar.h"
#include "CGame.h"

CCar::CCar():CObstacle()
{
}

CCar::CCar(int x, int y, string direct, int speed):CObstacle(x, y, direct, speed)
{
	width = carWidth;
	height = carHeight;

}

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

