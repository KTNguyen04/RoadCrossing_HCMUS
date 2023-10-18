#pragma once
#include "CConsole.h"
#include <vector>
const int lane = 10;    //size
const int pavement = 8;  //size
const int laneColor = Gray;
const int paveColor = DarkYellow;
const int riverColor = Blue;



//3 lane and 1 river
class CRoad
{
	int whereRiver;     // 1 or 2,3,4?
public:
	vector<int> sepLane;
protected:
	int width, height;
	int coorX, coorY; //topleft
	int color;
public:
	CRoad();
	virtual void drawRoad() {};
	static void drawPavement();

	 void setCoorY(int y);
	 void setCoorX(int x);

	template<class makeLane>
	void makeRandomLane();
};

