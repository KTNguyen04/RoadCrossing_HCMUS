#include "CGame.h"
#include "CRoad.h"
#include <condition_variable>
int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 0;
int CGame::frameWidth = 100;
int CGame::frameHeight = 82;



CGame::CGame()
{
	level = 1;
	//drawFrame();
	//drawRoad();


	CRoad::drawMap();

	initTrafficLights();
	bool flag = false;
	initObstacle();
	isRunning = true;


}

void CGame::drawFrame()
{
	wchar_t wc1 = L'\u2500';//   mảng ngang
	wchar_t wc2 = L'\u2502';//   mảng đứng
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY, wc1, Black);
	CConsole::drawChar(coorTopLeftX, coorTopLeftY, L'\u250C', Black);
	CConsole::drawVerLine(coorTopLeftY + 1, coorTopLeftY + frameHeight / 2 - 2, coorTopLeftX, wc2, Black);
	CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY, L'\u2510', Black);

	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + frameHeight / 2 - 1, wc1, Black);
	CConsole::drawChar(coorTopLeftX, coorTopLeftY + frameHeight / 2 - 1, L'\u2514', Black);

	CConsole::drawVerLine(coorTopLeftY + 1, coorTopLeftY + frameHeight / 2 - 2, coorTopLeftX + frameWidth - 1, wc2, Black);
	CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + frameHeight / 2 - 1, L'\u2518', Black);





}

void CGame::drawRoad()
{
	wchar_t wc1 = L'\u2500';//   mảng ngang
	wchar_t wc2 = L'\u2502';//   mảng đứng
	for (int i = 0; i < 4; i++) {
		CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + pavement / 2 + i * (lane + pavement) / 2, wc1, Black);
		CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + (i + 1) * (lane + pavement) / 2, wc1, Black);
	}
	for (int i = 0; i < 4; i++) {
		CConsole::drawChar(coorTopLeftX, coorTopLeftY + pavement / 2 + i * (lane + pavement) / 2, L'\u251C', Black);
		CConsole::drawChar(coorTopLeftX, coorTopLeftY + (i + 1) * (lane + pavement) / 2, L'\u251C', Black);

		CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + 4 + i * 9, L'\u2524', Black);
		CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + 9 + i * 9, L'\u2524', Black);

	}
}

//void CGame::drawBackGround()
//{
//	for (int i = 0; i < 4; i++) {
//		fillRect(coorTopLeftX, coorTopLeftY + pavement / 2+i*(pavement+lane)/2, 0, frameWidth - 1, 220, laneColor);
//		fillRect(coorTopLeftX, coorTopLeftY + pavement / 2 + 1+ i * (pavement + lane) / 2, lane / 2 - 2, frameWidth - 1, 219, laneColor);
//		fillRect(coorTopLeftX, coorTopLeftY + pavement / 2 + lane / 2+ i * (pavement + lane) / 2, 0, frameWidth - 1, 223, laneColor);
//	}
//
//}

int CGame::getWidth()
{
	return frameWidth;
}

int CGame::getHeight()
{
	return frameHeight;
}

int CGame::getCoorTopLeftX()
{
	return coorTopLeftX;
}

int CGame::getCoorTopLeftY()
{
	return coorTopLeftY;
}


//void CGame::insertRectSpace(int x, int y, int height, int width, int color)
//{
//	for (int i = y; i >= y - height; i--) {
//		CConsole::drawHorLine(x, x + width, i, 219, color);
//	}
//}

void CGame::fillRect(int x, int y, int hei, int wid, wchar_t c, int color)
{
	for (int i = y; i <= y + hei; i++) {
		CConsole::drawHorLine(x, x + wid, i, c, color);
	}
}

//void CGame::setGame()  // just demo
//{
//	/*vector<CCar> carList;
//	vector<CTruck> truckL;*/
//
//
//
//	CRoad virtualRoad;
//	CLane l1, l2, l3;
//	CRiver rv;
//	virtualRoad.drawWinLane();
//	virtualRoad.setUpRoad();
//	CRoad::makeRandomLane();
//	l1.setCoorY(CRoad::sepLane[0]);
//	virtualRoad.specifyRoad[virtualRoad.sepLane[0]] = "lane";
//
//	l2.setCoorY(CRoad::sepLane[1]);
//	virtualRoad.specifyRoad[virtualRoad.sepLane[1]] = "lane";
//
//	l3.setCoorY(CRoad::sepLane[2]);
//	virtualRoad.specifyRoad[virtualRoad.sepLane[2]] = "lane";
//
//
//	rv.setCoorY(CRoad::sepLane[3]);
//	virtualRoad.specifyRoad[virtualRoad.sepLane[3]] = "river";
//
//	l1.drawRoad();
//	l2.drawRoad();
//	l3.drawRoad();
//	rv.drawRoad();
//	virtualRoad.drawPavement();
//
//}
condition_variable cv, cv2;
mutex m, m2;
bool ready_input = false;
bool canmove = true;
void CGame::startGame()
{

	thread t1(&CGame::subThread, this);
	while (1) {
		//unique_lock<mutex> lock(m);
		//cv2.wait(lock, [] {return finish_move; });
		if (canmove) {
			key = CConsole::getInput();
			ready_input = true;
			pp.peopleMoving(key);
		}

		
		//this_thread::sleep_for(chrono::microseconds(100));


	}


	t1.join();
	////t2.join();
	//t3.join();
	//
}

void CGame::initTrafficLights()
{

	for (int i = 0; i < 3; i++) {
		CTrafficLight tf(coorTopLeftX + frameWidth, CRoad::sepLane[i]);
		trafficLights.push_back(tf);
		trafficLights[i].drawTrafficLight();
		trafficLights[i].setGreenTime(rand() % 3 + 1);
		trafficLights[i].setRedTime(rand() % 3 + 1);
		trafficLights[i].lightUp();

	}
}

void CGame::relaxBackGround(const int& y, int& backColor)
{

	//if (y >= CRoad::sepPave[3]) backColor = paveColor;
	if (y >= CRoad::sepLane[3] / 2 && y < CRoad::sepLane[3] / 2 + lane / 2) {
		/*if (CRoad::specifyRoad[CRoad::sepLane[3]] == "lane") {
			backColor = laneColor;
		}*/
		backColor = riverColor;
	}
	else if (y >= CRoad::sepLane[2] / 2 && y < CRoad::sepLane[2] / 2 + lane / 2) {
		/*if (CRoad::specifyRoad[CRoad::sepLane[2]] == "lane") {
			backColor = laneColor;
		}*/
		backColor = laneColor;
	}
	else if (y >= CRoad::sepLane[1] / 2 && y < CRoad::sepLane[1] / 2 + lane / 2) {
		/*if (CRoad::specifyRoad[CRoad::sepLane[1]] == "lane") {
			backColor = laneColor;
		}*/
		backColor = laneColor;
	}
	else if (y >= CRoad::sepLane[0] / 2 && y < CRoad::sepLane[0] / 2 + lane / 2) {
		/*if (CRoad::specifyRoad[CRoad::sepLane[0]] == "lane") {
			backColor = laneColor;
		}*/
		backColor = laneColor;
	}
	else if (y < CRoad::saveLane[0]) backColor = winColor;
	else {
		backColor = paveColor;
	}
}


//int CGame::getNumberOfObstacle()
//{
//	if ()
//	return 0;
//}
//

template<class obstacle>
bool CGame::isAbleToCreate(obstacle& O1, obstacle& O2) {
	return O1.getCoorX() + O1.getWidth() < O2.getCoorX();
}

template<class T>
vector<T> CGame::createListObstacle(int x, int y, int number, string direct)
{
	vector<T> obs;
	if (direct == "right") {
		obs.push_back(T(x, y, "right"));
		int getAvg = frameWidth / number;
		if (number == 1) getAvg = frameWidth - obs.front().getWidth();
		int maxDis = (getAvg - obs.front().getWidth()) * 2;
		int minDis = 4;


		for (int i = 1; i < number; i++) {
			int tempX = obs[i - 1].getCoorX() - obs.front().getWidth() - rand() % (maxDis - minDis) - minDis;
			obs.push_back(T(tempX, y, "right"));
		}
	}
	else {
		obs.push_back(T(x, y, "left"));
		int getAvg = frameWidth / number;
		if (number == 1) getAvg = frameWidth - obs.front().getWidth();
		int maxDis = (getAvg - obs.front().getWidth() - 1) * 2;
		int minDis = 4;


		for (int i = 1; i < number; i++) {
			int tempX = obs[i - 1].getCoorX() + obs.front().getWidth() + rand() % (maxDis - minDis) + minDis;
			obs.push_back(T(tempX, y, "left"));
		}
	}
	return obs;
}

template<class obs>
void CGame::deleteShadow(vector<obs>& obss)
{
	for (int i = 0; i < obss.size(); i++) {
		obss[i].drawObject(true);
	}
}

//template<class obstacle>
//void CGame::moveObstacle() {
//
//	/*int getAvg = frameWidth / obs.size();
//	int maxDis = (getAvg - obs.front().getWidth()) * 2;
//	int minDis = 4;*/
//
//
//	for (int i = 0; i < obs.size(); i++) {
//		obs[i].move();
//
//	}
//}

//template<class obstacle>
void CGame::initObstacle()
{
	int test = coorTopLeftY + 2 * (lane + pavement) / 2 - 1;
	trucks = createListObstacle<CTruck>(coorTopLeftX + 1 - truckWidth, (CRoad::sepLane[0] + lane) / 2 - 1, 1, "right");
	cars = createListObstacle<CCar>(coorTopLeftX + 1, (CRoad::sepLane[1] + lane) / 2 - 1, 1, "left");
	truck2s = createListObstacle<CTruck>(coorTopLeftX + 1 + CGame::getWidth(), (CRoad::sepLane[2] + lane) / 2 - 1, 1, "left");


}

void CGame::levelUp()
{

	level += 1;
	/*if (level %10==0) {

		addObs(trucks);
	}
	else if (level % 10 == 1) {

		addObs(cars);
	}
	else if (level % 10 == 2) {
		addObs(truck2s);

	}
	else if (level % 10 == 3&&level >6) {
		setObssSpeed(trucks);
	}*/
	/*else if (level % 10 == 4) {
		setObssSpeed(truck2s);
	}
	else if (level % 10 == 5) {
		setObssSpeed(cars);
	}
	else if (level % 10 == 6) {
		setObssSpeed(trucks);
	}*/
	deleteShadow(trucks);
	deleteShadow(truck2s);
	deleteShadow(cars);
	if (level % 2)
		CRoad::makeRandomLane();
	CRoad::drawMap();
	//setGame();
	resetPosObs(trucks, 0);
	resetPosObs(truck2s, 1);
	resetPosObs(cars, 2);

}

template<class obs>
void CGame::addObs(vector<obs>& obss)
{
	if (obss.front().getDirect() == "right") {
		int getAvg = frameWidth / (obss.size() + 1);
		int maxDis = (getAvg - obss.back().getWidth()) * 2;
		int minDis = 4;
		int tempX = obss.back().getCoorX() - obss.back().getWidth() - rand() % (maxDis - minDis) - minDis;
		obss.push_back(obs(tempX, obss.back().getCoorY(), obss.back().getDirect(), obss.back().getSpeed()));

	}
	else {
		int getAvg = frameWidth / (obss.size() + 1);
		int maxDis = (getAvg - obss.back().getWidth()) * 2;
		int minDis = 4;
		int tempX = obss.back().getCoorX() + obss.back().getWidth() + rand() % (maxDis - minDis) + minDis;
		obss.push_back(obs(tempX, obss.back().getCoorY(), obss.back().getDirect(), obss.back().getSpeed()));

	}
}
template <class obs>
void CGame::resetPosObs(vector<obs>& obss, const int& l)
{

	for (int i = 0; i < obss.size(); i++) {
		if (obss[i].getDirect() == "right") {
			if (i == 0) {
				obss[i].setCoorX(coorTopLeftX + 1 - obss[i].getWidth());
			}
			else {
				int getAvg = frameWidth / (obss.size());
				int maxDis = (getAvg - obss.back().getWidth()) * 2;
				int minDis = 4;

				obss[i].setCoorX(obss[i - 1].getCoorX() - obss.front().getWidth() - rand() % (maxDis - minDis) - minDis);
			}
		}
		else
		{
			if (i == 0) {
				obss[i].setCoorX(coorTopLeftX + 1 + CGame::getWidth());
			}
			else {
				int getAvg = frameWidth / (obss.size());
				int maxDis = (getAvg - obss.back().getWidth()) * 2;
				int minDis = 4;

				obss[i].setCoorX(obss[i - 1].getCoorX() + obss.front().getWidth() + rand() % (maxDis - minDis) + minDis);
			}
		}
		obss[i].setCoorY((CRoad::sepLane[l] + lane) / 2 - 1);
	}

}
template<class obs>
void CGame::setObssSpeed(vector<obs>& obss)
{
	int curSpeed = obss.front().getSpeed();
	for (auto& e : obss) {
		e.setSpeed(curSpeed + 1);
	}
}

void CGame::subThread()
{

	/*thread subsub([this]() {

		while (isRunning) {
			for (auto& e : cars) {
				e.drawObject(true);
				e.move();
				e.drawObject();
			}
			for (auto& e : trucks) {
				e.drawObject(true);
				e.move();
				e.drawObject();
			}
		}});*/
	while (isRunning) {


		if (!pp.IS_DEAD()) {
			//	unique_lock<mutex> lock(m);
				//cv.wait(lock, []() {return ready_input; });
				//m.unlock();
			ready_input = false;

			/*pp.peopleMoving(key);*/
				//pp.drawPeople(true);
			mutex mt, mt2;
			canmove = false;

			if (pp.isNeedDraw()) {
				//	m.unlock();
				pp.drawPeople(true);
				pp.drawPeople();

				pp.setOldx(pp.getX());
				pp.setOldy(pp.getY());
			}
			if (pp.levelComplete()) {
				//system("cls");
				//setGame();

				//this_thread::sleep_for(chrono::microseconds(50));

				levelUp();
				pp.resetPos();

				this_thread::sleep_for(chrono::microseconds(100));

			}
			//	cv2.notify_one();

			//lock_guard<mutex> lg(mt);

		}

		for (auto& e : cars) {


				e.drawObject(true);
				e.move();
				e.drawObject();
			
			if (pp.isCollide(e)) {
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();
				exit(0);
			}
		}
		for (auto& e : trucks) {
			//	this_thread::sleep_for(chrono::microseconds(200 / e.getSpeed()));

			
				e.drawObject(true);
				e.move();
				e.drawObject();
			if (pp.isCollide(e)) {
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();
				exit(0);
			}


		}
		for (auto& e : truck2s) {
			//	this_thread::sleep_for(chrono::microseconds(200 / e.getSpeed()));

			if (trafficLights[2].getState() == "green") {
				e.drawObject(true);
				e.move();
				e.drawObject();
			}
			if (pp.isCollide(e)) {
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();
				exit(0);
			}


		}

		for (int i = 0; i < trafficLights.size(); i++) {
			if (timer.countDown(trafficLights[i].getTime())) {
				trafficLights[i].changeLight();
			}
		}
		canmove = true;

		//Sleep(1);

	//subsub.join();
	}
}
