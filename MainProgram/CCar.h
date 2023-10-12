#pragma once
#include "CObstacle.h"
#include "CConsole.h"
#include "CGame.h"
class CCar :public CObstacle
{

public:
	CCar(int x, int y);                  //bottom left coor
	virtual void move(string direct);
	virtual void drawObject(int color);
};

