#include "CObstacle.h"
#include "CGame.h"

CObstacle::CObstacle()
{
	backColor = laneColor;
}

CObstacle::CObstacle(int x, int y, string direct, int speed):CObstacle()
{
	coorX = x;
	coorY = y;
	backColor = laneColor;
	this->direct = direct;
	this->speed = speed;
}

void CObstacle::move()
{
	
	if (direct == "right") {
		coorX += speed;
		if ((coorX >= (CGame::getCoorTopLeftX() + CGame::getWidth())-1) && !isInit()) {
			coorX = CGame::getCoorTopLeftX()+1-width;
		}
	}
	else if (direct == "left") {

		coorX -= speed;

		if ((coorX <= (CGame::getCoorTopLeftX() - this->width + 1)) && !isInit()) {
			coorX = CGame::getCoorTopLeftX()+ CGame::getWidth();

		}

	}
	
}

int CObstacle::getCoorX() const
{
	return coorX;
}

int CObstacle::getCoorY() const {
	return coorY;
}
bool CObstacle::isInit()
{
	return  (coorX <= CGame::getCoorTopLeftX() - this->width) || (coorX >= CGame::getCoorTopLeftX() + CGame::getWidth() + 1);
}
int CObstacle::getWidth()const {
	return width;
}
int CObstacle::getHeight() const {
	return height;
}

int CObstacle::getSpeed() const
{
	return speed;
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

void CObstacle::setCoorX(const int& x)
{
	this->coorX = x;
}
void CObstacle::setCoorY(const int &y) {
	this->coorY = y;
}

void CObstacle::setSpeed(int speed)
{
	this->speed = speed;
}
void CObstacle::setDirect(string direct)
{
	this->direct = direct;
}


string CObstacle::getDirect() const
{
	return direct;
}

