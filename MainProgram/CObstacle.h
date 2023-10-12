#pragma once
#include <string>
using namespace std;
class CObstacle
{
protected:
	int coorX, coorY;
	int width, height;
public:
	
	virtual void move(string direct)=0;
	virtual void drawObject(int color) =0;
};

