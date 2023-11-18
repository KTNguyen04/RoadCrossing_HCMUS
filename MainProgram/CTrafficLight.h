#pragma once
#include "CConsole.h"
#include "CObstacle.h"
class CTrafficLight
{
	string lightState;
	int color;
	int coorX, coorY;
	int redTime, greenTime;
	int height, width;
	int greenColor, redColor;
		
public:
	CTrafficLight();
	CTrafficLight(int x, int y);
	void drawTrafficLight();
	void setCoorX(const int& x);
	void setCoorY(const int& y);
	void setRedTime(const int& r);
	void setGreenTime(const int& g);
	void lightUp();
	int getTime();
	string getState();
	void changeLight();
	void changeState();
	
};

