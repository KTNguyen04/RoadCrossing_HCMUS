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
#include"CMenu.h"
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
const string hitSound2 = "Hit2";
const string levelUpSound = "LevelUp";
const string diveSound = "Dive";

const string savedFilePath = "save_game.bin";

class CGame
{
	static int coorTopLeftX, coorTopLeftY;
	static int frameWidth, frameHeight;
	int level=1;
	int score=0;
	bool isRunning;
	vector<CTruck> trucks;
	vector<CTruck> truck2s;
	vector<CCar> cars;
	vector<CBridge> bridges;
	vector<CTrafficLight> trafficLights;
	CPeople pp;
	CTimer timer;
	Audio audio;
	int key;
	//vector<CTruck> truckL ;
	CFileWork fileM;

public:
	CGame();
	void initGame();
	static void drawFrame();
	static void drawRoad();
	static int getWidth();
	static int getHeight();
	static int getCoorTopLeftX();
	static int getCoorTopLeftY();
	static void fillRect(int x, int y, int hei, int wid, wchar_t c, int color);         //topLeft coor


	char startGame();
	template<class obstacle>
	bool isAbleToCreate(obstacle& O1, obstacle& O2);
	template<class T>
	vector<T> createListObstacle(int x, int y, int number, string direct);
	void initTrafficLights();
	void initBridges();

	template <class obs>
	void deleteShadow(vector<obs>& obss);
	void levelUp();
	template<class obs>
	void setObssSpeed(vector<obs>& obss);
	template< class obs>
	void addObs(vector<obs>& obss);
	void subThread(bool &canmove,bool& rd,bool & isRun);
	void initObstacle();
	template< class obs>
	void resetPosObs(vector<obs>& obss, const int& l);   //0123
	void resetPosBridge();   //0123
	void resetPosTrafficLight();
	void resetPosPp();
	void increDifficulty();
	static vector<int> sepBridges;
	void tlLightUp();
	void drawBridge();

	

	bool saveGame(const string& name);
	void loadGame(const string& name);
	char deadPopUp();
	char victoryPopUp();
	string loadPopUp(); 
	string savePopUp(bool isForRemove = false);
	bool isAvail(string input);

	void showLevel(int level, int x);
	void showScore(int score, int x);
	int getScore();
	int getLevel();
};

