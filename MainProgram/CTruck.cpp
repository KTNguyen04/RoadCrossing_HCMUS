#include "CTruck.h"
#include<condition_variable>
#include "CGame.h"


CTruck::CTruck() :CObstacle()
{
}

CTruck::CTruck(int x, int y, string direct, int speed) :CObstacle(x, y, direct, speed)
{


	width = truckWidth;
	height = truckHeight;

}

void CTruck::drawObject(bool isForRemove)
{
	
	if (!isForRemove) {
		int x = coorX;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 1, topBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 2, topBlock, White, Yellow);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 1, topBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 2, block, Yellow, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, Black, Yellow);
			CConsole::drawChar(x, coorY - 2, botBlock, DarkYellow, Yellow);
			CConsole::drawChar(x, coorY - 3, botBlock, Black, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, Yellow, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, DarkYellow, Yellow);

		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, Yellow, backColor);
			CConsole::drawChar(x, coorY - 2, block, Yellow, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, Yellow, backColor);
			CConsole::drawChar(x, coorY - 2, block, Yellow, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, Yellow, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, DarkYellow, Yellow);
			CConsole::drawChar(x, coorY - 3, botBlock, White, Yellow);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 1, block, Blue, backColor);
			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, DarkYellow);
			CConsole::drawChar(x, coorY - 3, block, Yellow, backColor);
		}

		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, Black, Blue);
			CConsole::drawChar(x, coorY - 1, botBlock, Black, Blue);
			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, DarkYellow);
			CConsole::drawChar(x, coorY - 3, block, Yellow, backColor);
		}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY, botBlock, Black, Blue);
			//	CConsole::drawChar(x, coorY - 1, block, Blue, backColor);
			CConsole::drawChar(x, coorY - 1, block, Blue, backColor);

			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, Black, DarkYellow);
			//CConsole::drawChar(x, coorY - 3, block, Yellow, backColor);

		}

		//x++;
		//if (isInBoard(true, x)) {
		//	CConsole::drawChar(x, coorY, botBlock, Black, Blue);
		//	CConsole::drawChar(x, coorY - 1, block, Blue, backColor);
		//	//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
		//	CConsole::drawChar(x, coorY - 2, botBlock, Black, DarkYellow);
		//	//CConsole::drawChar(x, coorY - 3, block, Yellow, backColor);

		//}
		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY, topBlock, Black, backColor);
			CConsole::drawChar(x, coorY - 1, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, DarkYellow, Yellow);

		}
	}
	else {
		int x = coorX;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, topBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);

		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY - 1, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, botBlock, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, block, backColor, backColor);
		}

		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, block, backColor, backColor);
		}
		x++;
		if (isInBoard(true, x)) {
			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, botBlock, backColor, backColor);
			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 3, block, backColor, backColor);
		}

		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY, botBlock, backColor, backColor);
			//	CConsole::drawChar(x, coorY - 1, block, Blue, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);

			//	CConsole::drawChar(x, coorY - 2, block, Black, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);
			//CConsole::drawChar(x, coorY - 3, block, Yellow, backColor);

		}

		x++;
		if (isInBoard(true, x)) {

			CConsole::drawChar(x, coorY, topBlock, backColor, backColor);
			CConsole::drawChar(x, coorY - 1, block, backColor, backColor);
			CConsole::drawChar(x, coorY - 2, botBlock, backColor, backColor);

		}

	}
}
