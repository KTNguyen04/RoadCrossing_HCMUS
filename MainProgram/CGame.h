#pragma once
#include "CConsole.h"
#include "CPeople.h"
#include "CCar.h"
#include "CLane.h"
#include "CRiver.h"
#include <vector>
#include "CTruck.h"
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
//	static void drawBackGround();
	static int getWidth();
	static int getHeight();
	static int getCoorTopLeftX();
	static int getCoorTopLeftY();
	//static void insertRectSpace(int x, int y, int hei, int wid, int color);    //bottomLeft coor
	static void fillRect(int x, int y, int hei, int wid,wchar_t c, int color);         //topLeft coor
	void runGame();

	template<class obstacle>
	bool isAbleToCreate(obstacle &O1, obstacle &O2);

	template<class obstacle>
	void createListObstacle(vector<obstacle> &obs, int x, int y, int number,string direct);

	template<class obstacle>
	void moveObstacle(vector<obstacle> &obs, int speed);

	/*int getNumberOfObstacle();
	int getSpeed();*/
	static void relaxBackGround(const int &y, int& backColor);


};

