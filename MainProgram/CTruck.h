#pragma once
#include "CObstacle.h"
#include "CConsole.h"
const int truckHeight = 8;
const int truckWidth = 12;
	
class CTruck :public CObstacle
{
public:
	CTruck(int x, int y, string direct, int speed = 1);      //bottom left coor
	//void move();
	void drawObject(bool isForRemove = false);
	/*bool isInBoard(bool isForDraw=false,int x=-1);*/
};
