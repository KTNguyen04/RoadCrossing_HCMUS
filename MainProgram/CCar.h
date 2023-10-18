#pragma once
#include "CObstacle.h"
#include "CConsole.h"
#include "CGame.h"

const int carHeight = 8;
const int carWidth = 12;
class CCar :public CObstacle
{

public:
	CCar(int x, int y, int speed = 0);      //bottom left coor
	void move(string direct);
	void drawObject(int color);
	bool isInBoard();
	void setSpeed(int speed);
	bool isInit();
	

};

