#pragma once
#include "CObstacle.h"
#include "CConsole.h"
#include "CGame.h"

const int carHeight = 8;
const int carWidth = 13;
class CCar :public CObstacle
{

public:
	CCar(int x, int y, string direct,int speed = 0);      //bottom left coor
	//void move();
	void drawObject(bool isForRemove = false);
	/*bool isInBoard(bool isForDraw=false,int x=-1);*/
	//bool isInit();
	

};

