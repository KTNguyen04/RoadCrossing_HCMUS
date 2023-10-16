#pragma once
#include <string>
using namespace std;
class CObstacle
{
protected:
	int coorX, coorY;
	int width, height;
	int speed;
public:
	
	virtual void move(string direct)=0;
	virtual void drawObject(int color) =0;
	int getCoorX();
	int getCoorY();
	int getWidth();
	int getHeight();

	void setCoorX(int x);
	void setCoorY(int y);
	virtual bool isInBoard()=0;
};

