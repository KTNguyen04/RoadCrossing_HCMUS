#pragma once
#include "CConsole.h"
#include <vector>
#include <algorithm>
#include <map>
#include "CTrafficLight.h"
const int lane = 10;    //size
const int pavement = 8;  //size
const int laneColor = DarkWhite;
const int paveColor = DarkYellow;
const int riverColor = DarkCyan;
const int winColor = DarkBlue;

const wchar_t block = L'\u2588';
const wchar_t topBlock = L'\u2580';
const wchar_t botBlock = L'\u2584';



//3 lane and 1 river
class CRoad
{
	//int whereRiver;     // 1 or 2,3,4?

public:
	static vector<int> sepLane;
	static vector<int> saveLane;
	static vector<int>sepPave;
	static map<int, string> specifyRoad;
protected:
	int width, height;
	int coorX, coorY; //topleft
	int color;
public:
	//CRoad() {};
	static void setUpRoad();
	static void drawRoad(const int &y,const int& color);
	static void drawPavement();

	void setCoorY(int y);
	void setCoorX(int x);
	static void drawMap();
	static void drawWinLane();
	static void makeRandomLane();
	
	
};

