#pragma once
#include <thread>
#include "CConsole.h"
#include "CPeople.h"
#include "CCar.h"
#include "CTimer.h"
//#include "CObstacle.h"
#include "CLane.h"
#include "CRiver.h"
#include <vector>
#include <thread>
#include <future>
#include "CTrafficLight.h"
#include "CTruck.h"
#define ThangDung 179
#define Ngang 196
#define Vuong 254

class CGame
{
	static int coorTopLeftX, coorTopLeftY;
	static int frameWidth, frameHeight;
	int level;

	bool isRunning;
	vector<CTruck> trucks  ;	
	vector<CTruck> truck2s  ;	
	vector<CCar> cars ;	

	vector<CTrafficLight> trafficLights	;
	CPeople pp;
	CTimer timer;

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
	static void fillRect(int x, int y, int hei, int wid,wchar_t c, int color);         //topLeft coor
	void setGame();
	void startGame();
	template<class obstacle>
	bool isAbleToCreate(obstacle &O1, obstacle &O2);
	void initTrafficLights();

	template<class T>
	vector<T> createListObstacle( int x, int y, int number,string direct);

	void initTrafficLight();
	template <class obs>
	void deleteShadow(vector<obs>& obss);

	static void relaxBackGround(const int &y, int& backColor);

	void levelUp();
	template<class obs>
	void setObssSpeed(vector<obs>& obss);
	template< class obs>
	void addObs(vector<obs>& obss);
	void subThread();
	void initObstacle();
	template< class obs>
	void resetPosObs(vector<obs>& obss,const int& l) ;   //0123

	void changeLight(CTrafficLight& tf);
};

