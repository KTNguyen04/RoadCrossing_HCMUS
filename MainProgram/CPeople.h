#pragma once
#include "CConsole.h"
#include "CObstacle.h"
#include "CBridge.h"
#include <vector>
class CPeople
{
	int coorX, coorY;
	int height, width;
	int color, backColor;
	bool isDead;
	int oldX, oldY;
	vector<int> bcl; 
public:
	CPeople();
	void setX(const int& x);
	void setY(const int& y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void drawPeople(bool isForRemove = false);
	bool IS_DEAD();
	void dead(bool state = true);
	void peopleMoving(char c);
	bool isInBoard(int, int y);
	void setOldx(int x) { oldX = x; }
	void setOldy(int y) { oldY = y; }
	void setBackColor(const int& bcl);
	bool isNeedDraw();
	int getX() { return coorX; };
	int getY() { return coorY; };
	bool levelComplete();
	void resetPos();
	bool isCollide(const CObstacle& obs);
	bool isDrown(const CBridge& br);
	int relaxBackGround(const int& y, const int& x = -1);
};

