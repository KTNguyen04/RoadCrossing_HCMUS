#pragma once
#include <thread>
#include "CConsole.h"
#include "CPeople.h"
#include "CCar.h"
#include "CTimer.h"
#include "CBridge.h"
#include "CLane.h"
#include "CRiver.h"
#include <vector>
#include <thread>
#include "CTrafficLight.h"
#include "CTruck.h"
#include "CAudio.h"
#include "CFileWork.h"

#define ThangDung 179
#define Ngang 196
#define Vuong 254


const int bridgeWidth = 12;
const int bridgeHeight = 10;
const int bridgeColor = Red;

const string moveSound = "Dash";
const string tapSound = "Tap";
const string menuSound = "Menu";
const string vehicleSound = "CarHorn";
const string victorySound = "Victory";
const string gameOverSound = "GameOver";
const string hitSound = "Hit";

class CGame
{
	static int coorTopLeftX, coorTopLeftY;
	static int frameWidth, frameHeight;
	int level;
	int score;
	bool isRunning;
	vector<CTruck> trucks;
	vector<CTruck> truck2s;
	vector<CCar> cars;
	vector<CBridge> bridges;
	vector<CTrafficLight> trafficLights;
	CPeople pp;
	CTimer timer;
	Audio audio;
	CFileWork fileM;
	int key;
	//vector<CTruck> truckL ;

public:
	CGame();
	static void drawFrame();
	static void drawRoad();
	//	static void drawBackGround();
	static int getWidth();
	static int getHeight();
	static int getCoorTopLeftX();
	static int getCoorTopLeftY();
	static void fillRect(int x, int y, int hei, int wid, wchar_t c, int color);         //topLeft coor
	void setGame();

	void startGame();
	template<class obstacle>
	bool isAbleToCreate(obstacle& O1, obstacle& O2);
	void initTrafficLights();
	void initBridges();

	template<class T>
	vector<T> createListObstacle(int x, int y, int number, string direct);

	
	template <class obs>
	void deleteShadow(vector<obs>& obss);

	//static void relaxBackGround(const int& y, int& backColor);

	void levelUp();
	template<class obs>
	void setObssSpeed(vector<obs>& obss);
	template< class obs>
	void addObs(vector<obs>& obss);
	void subThread(bool &canmove);
	void initObstacle();
	template< class obs>
	void resetPosObs(vector<obs>& obss, const int& l);   //0123
	void resetPosBridge();   //0123
	void resetPosTrafficLight();
	//void changeLight(CTrafficLight& tf);
	
	void increDifficulty();
	static vector<int> sepBridges;

	
	bool saveGame(const string& name);
	void loadGame(const string& name);

};

