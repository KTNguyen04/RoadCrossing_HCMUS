#pragma once
#include "CConsole.h"
#include "CPeople.h"
#include "CCar.h"
#include <vector>
#define ThangDung 179
#define Ngang 196
#define Vuong 254
class CGame
{
	static int coorTopLeftX, coorTopLeftY;
	static int frameWidth, frameHeight;
	int level;
	
public:
	CGame();
	static void drawFrame();
	static void drawRoad();
	static int getWidth();
	static int getHeight();
	static int getCoorTopLeftX();
	static int getCoorTopLeftY();
	static void insertRectSpace(int x, int y, int hei, int wid, int color);    //bottomLeft coor

	void runGame();

	template<class obstacle>
	bool isAbleToCreate(obstacle &O1, obstacle &O2);

	template<class obstacle>
	void createListObstacle(vector<obstacle> &obs, int x, int y, int number);

	template<class obstacle>
	void moveObstacle(vector<obstacle> &obs, int speed);

	int getNumberOfObstacle();
	int getSpeed();


};

