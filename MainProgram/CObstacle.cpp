#include "CObstacle.h"
#include "CGame.h"

void CObstacle::move()
{
	Sleep(1);
	//	if (isInBoard())
	drawObject(true);
	if (direct == "right") {//left to right
		coorX += speed;
		if ((coorX >= (CGame::getCoorTopLeftX() + CGame::getWidth())) && !isInit()) {
			coorX -= CGame::getWidth();
			coorX -= this->width;
		}
		//if (!isInBoard() && !isInit()) coorX = CGame::getCoorTopLeftX() + CGame::getWidth() - 1;
	}
	else if (direct == "left") {
		coorX -= speed;

		if ((coorX <= (CGame::getCoorTopLeftX() - this->width + 1)) && !isInit()) {
			coorX += CGame::getWidth();
			coorX += this->width;
		}
		//if (!isInBoard() && !isInit()) coorX += speed;
	}

	//CGame::drawRoad();
	//coorX %= CGame::getWidth();

	//if ( isInBoard())
	drawObject();
}

int CObstacle::getCoorX()
{
	return coorX;
}

int CObstacle::getCoorY() {
	return coorY;
}
bool CObstacle::isInit()
{
	return  (coorX <= CGame::getCoorTopLeftX() - this->width) || (coorX >= CGame::getCoorTopLeftX() + CGame::getWidth() + 1);
}
int CObstacle::getWidth() {
	return width;
}
int CObstacle::getHeight() {
	return height;
}

bool CObstacle::isInBoard(bool isForDraw  , int x )
{
	if (!isForDraw) {
		bool b1 = coorX >= CGame::getCoorTopLeftX() && coorX <= CGame::getCoorTopLeftX() + CGame::getWidth() - 1;

		return b1;
	}

	bool b1 = (x >= CGame::getCoorTopLeftX()) && (x <= (CGame::getCoorTopLeftX() + CGame::getWidth() - 1));

	return b1;
}

void CObstacle::setCoorX(int x)
{
	this->coorX = x;
}
void CObstacle::setCoorY(int y) {
	this->coorY = y;
}

void CObstacle::setSpeed(int speed)
{
	this->speed = speed;
}
