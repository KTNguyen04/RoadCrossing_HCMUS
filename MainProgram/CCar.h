#pragma once
#include "CObstacle.h"
#include "CConsole.h"

const int carHeight = 8;
const int carWidth = 13;
class CCar :public CObstacle
{

public:
	CCar();
	CCar(int x, int y, string direct,int speed = 1);      //bottom left coor
	void drawObject(bool isForRemove = false);
};

