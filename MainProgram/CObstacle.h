#pragma once
#include <string>
using namespace std;
class CObstacle
{
protected:
	int coorX, coorY;
	int width, height;
	int speed;
	int backColor;
	string direct;
public:

	void move();
	virtual void drawObject(bool isForRemove = false) = 0;
	int getCoorX();
	int getCoorY();
	bool isInit();
	int getWidth();
	int getHeight();
	bool isInBoard(bool isForDraw = false, int x = -1);
	void setCoorX(int x);
	void setCoorY(int y);
	void setSpeed(int speed);
	//virtual bool isInBoard(bool isForDraw = false, int x = -1) = 0;
};

