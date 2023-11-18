#include "CObstacle.h"
#include "CGame.h"

CObstacle::CObstacle(int x, int y, string direct, int speed)
{
	coorX = x;
	coorY = y;
	backColor = laneColor;
	this->direct = direct;
	this->speed = speed;
	drawObject();
}

void CObstacle::move()
{
	//	if (isInBoard())
	//drawObject(true);
	
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
		//if (!isInBoard() && !isInit()) coorX += speed
	}
	
	//CGame::drawRoad();
	//coorX %= CGame::getWidth();


	//if ( isInBoard())
//	startSignalOb.set_value();
	//drawObject();
	//this_thread::sleep_for(chrono::milliseconds(1000=);
//	m_.unlock();
	//endSignalOb.get();
	

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

int CObstacle::getSpeed()
{
	return speed;
}

string CObstacle::getDirect()
{
	return direct;
}

