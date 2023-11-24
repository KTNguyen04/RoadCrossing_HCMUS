#pragma once
#include <string>
using namespace std;
class CObstacle
{
protected:
	int coorX, coorY;    //bottomleft
	int width, height;
	int speed;
	int backColor;
	string direct;
public:
	CObstacle() ;
	CObstacle(int x, int y, string direct, int speed=1) ;
	void move();
	virtual void drawObject(bool isForRemove = false) {};
	int getCoorX()const;
	int getCoorY()const;
	bool isInit();
	int getWidth() const;
	int getHeight() const;
	bool isInBoard(bool isForDraw = false, int x = -1);
	void setCoorX(int x);
	void setCoorY(int y);
	void setSpeed(int speed);
	int getSpeed();
	string getDirect();
	
	//virtual bool isInBoard(bool isForDraw = false, int x = -1) = 0;
};

