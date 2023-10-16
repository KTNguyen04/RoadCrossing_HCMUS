#include "CObstacle.h"

int CObstacle::getCoorX()
{
	return coorX;
}

int CObstacle::getCoorY() {
	return coorY;
}
int CObstacle::getWidth() {
	return width;
}
int CObstacle::getHeight() {
	return height;
}

void CObstacle::setCoorX(int x)
{
	this->coorX = x;
}
void CObstacle::setCoorY(int y) {
	this->coorY = y;
}
