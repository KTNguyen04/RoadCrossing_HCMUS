#pragma once
#include "CConsole.h"
#include "CObstacle.h"
#include <vector>
class CPeople
{
	int coorX, coorY;
	int height, width;
	int color, backColor;
	bool isDead;
	int oldX, oldY;
public:
	CPeople();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void drawPeople(bool isForRemove = false);
	bool IS_DEAD();
	void peopleMoving(char c);
	bool isInBoard(int, int y);
	void setOldx(int x) { oldX = x; }
	void setOldy(int y) { oldY = y; }
	bool isNeedDraw();
	int getX() { return coorX; };
	int getY() { return coorY; };
	bool levelComplete();
	void resetPos();
	bool isCollide(const CObstacle& obs);
};

