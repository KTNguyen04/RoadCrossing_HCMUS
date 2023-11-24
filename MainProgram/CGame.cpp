#include "CGame.h"
#include "CRoad.h"
#include <cmath>
#include <condition_variable>
int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 0;
int CGame::frameWidth = 100;
int CGame::frameHeight = 82;

vector<int> CGame::sepBridges;

CGame::CGame()
{
	level = 1;
	//drawFrame();
	//drawRoad();


	CRoad::drawMap();

	initTrafficLights();
	bool flag = false;
	initObstacle();
	initBridges();
	isRunning = true;
	//sepBridges.resize(bridges.size());


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


void CGame::startGame()
{
	bool canmove = true;
	pp.drawPeople();
	thread t1(&CGame::subThread, this, std::ref(canmove));
	while (1) {
		//unique_lock<mutex> lock(m);
		//cv2.wait(lock, [] {return finish_move; });
		if (canmove) {
			key = CConsole::getInput();
			if (key == 'q') {
				saveGame("test12.bin");
				loadGame("test12.bin");
				system("pause");
			}
			pp.peopleMoving(key);
			audio.playSound(moveSound);


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
		trafficLights[i].setGreenTime(rand() % 10 + 5);
		trafficLights[i].setRedTime(rand() % 4 + 2);
		trafficLights[i].lightUp();

	}
}

void CGame::initBridges()
{

	for (int i = 0; i < 2; i++) {
		CBridge brid(rand() % (frameWidth - bridgeWidth) + coorTopLeftX + 1, CRoad::sepLane[3] + lane - 1);
		bridges.push_back(brid);
		bridges[i].drawObject();
		sepBridges.push_back(bridges[i].getCoorX());
	}
}


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

	deleteShadow(trucks);
	deleteShadow(truck2s);
	deleteShadow(cars);
	if (level % 2)
		CRoad::makeRandomLane();
	CRoad::drawMap();
	//setGame();
	increDifficulty();
	//if(level<)
	resetPosObs(trucks, 0);
	resetPosObs(truck2s, 2);
	resetPosObs(cars, 1);

	for (int i = 0; i < 3; i++) {

		trafficLights[i].drawTrafficLight(true);
		trafficLights[i].setState("green");
		trafficLights[i].setGreenTime(rand() % 10 + 5);
		trafficLights[i].setRedTime(rand() % 4 + 2);

	}
	resetPosTrafficLight();
	for (int i = 0; i < 3; i++) {
		trafficLights[i].lightUp();
	}

	resetPosBridge();
	for (auto& e : bridges) {
		e.drawObject();
	}
}



void CGame::resetPosBridge()
{
	for (int i = 0; i < bridges.size(); i++) {
		bridges[i].setCoorY(CRoad::sepLane[3] + lane - 1);
		bridges[i].setCoorX(rand() % frameWidth + coorTopLeftX + 1);
		sepBridges[i] = bridges[i].getCoorX();
	}
}

void CGame::increDifficulty()
{
	if (level <= 22) {
		if (level % 6 == 2) {

			addObs(trucks);
		}
		else if (level % 6 == 3) {

			addObs(cars);
		}
		else if (level % 6 == 4) {
			addObs(truck2s);

		}
		if (level >= 5) {
			if (level % 6 == 5 && level) {
				setObssSpeed(trucks);
			}
			else if (level % 6 == 6) {
				setObssSpeed(truck2s);
			}
			else if (level % 6 == 1) {
				setObssSpeed(cars);
			}
		}
	}
	if (level == 12) bridges.pop_back();
}


bool CGame::saveGame(const string& name)
{
	fileM.setPath(name, rootP);
	if (fileM.openFile()) {

		saveInfo info = { 0 };
		info.level = level;
		info.score = score;
		info.peopleX = pp.getX();
		info.peopleY = pp.getY();
		info.people_isDead = pp.IS_DEAD();

		info.numLane = CRoad::sepLane.size();
		info.coorYLane.assign(CRoad::sepLane.begin(), CRoad::sepLane.end());

		info.numBridge = sepBridges.size();
		info.coorXBridge.resize(info.numBridge);
		transform(bridges.begin(), bridges.end(), info.coorXBridge.begin(),
			[](const CBridge& st) { return st.getCoorX(); });
		info.coorYBridge.resize(info.numBridge);
		transform(bridges.begin(), bridges.end(), info.coorYBridge.begin(),
			[](const CBridge& st) { return st.getCoorY(); });

		info.numLight = trafficLights.size();
		info.stateLight.resize(info.numLight);
		transform(trafficLights.begin(), trafficLights.end(), info.stateLight.begin(),
			[](const CTrafficLight& st) { return st.getState(); });
		info.coorXLight.resize(info.numLight);
		transform(trafficLights.begin(), trafficLights.end(), info.coorXLight.begin(),
			[](const CTrafficLight& st) { return st.getCoorX(); });
		info.coorYLight.resize(info.numLight);
		transform(trafficLights.begin(), trafficLights.end(), info.coorYLight.begin(),
			[](const CTrafficLight& st) { return st.getCoorY(); });

		info.numTruck = trucks.size();
		info.coorXTruck.resize(info.numTruck);

		transform(trucks.begin(), trucks.end(), info.coorXTruck.begin(),
			[](const CTruck& st) { return st.getCoorX(); });
		info.coorYTruck.resize(info.numTruck);

		transform(trucks.begin(), trucks.end(), info.coorYTruck.begin(),
			[](const CTruck& st) { return st.getCoorY(); });

		info.numTruck2 = truck2s.size();
		info.coorXTruck2.resize(info.numTruck2);

		transform(truck2s.begin(), truck2s.end(), info.coorXTruck2.begin(),
			[](const CTruck& st) { return st.getCoorX(); });
		info.coorYTruck2.resize(info.numTruck2);

		transform(truck2s.begin(), truck2s.end(), info.coorYTruck2.begin(),
			[](const CTruck& st) { return st.getCoorY(); });

		info.numCar = cars.size();
		info.coorXCar.resize(info.numCar);

		transform(cars.begin(), cars.end(), info.coorXCar.begin(),
			[](const CCar& st) { return st.getCoorX(); });
		info.coorYCar.resize(info.numCar);

		transform(cars.begin(), cars.end(), info.coorYCar.begin(),
			[](const CCar& st) { return st.getCoorY(); });

		fileM.saving<saveInfo>(info);

		fileM.closeFile();

		fileM.setPath("testname.bin", rootP);
		if (fileM.openFile()) {

			fileNames fn;
			if (!fileM.isEmpty())
				fn = fileM.loading<fileNames>();
			fn.names.push_back(name);
			fileM.saving<fileNames>(fn);
			fileM.closeFile();
		}

		return true;
	}
	return false;


}

void CGame::loadGame(const string& name)
{
	fileM.setPath(name, rootP);
	if (fileM.openFile()) {
		saveInfo info;
		info = fileM.loading<saveInfo>();
		level = info.level;
		score = info.score;
		pp.setX(info.peopleX);
		pp.setY(info.peopleY);
		pp.dead(info.people_isDead);

		for (int i = 0; i < info.numLane;i++) {
			CRoad::sepLane[i] = info.coorYLane[i];
		}

		bridges.resize(info.numBridge);
		for (int i = 0; i < info.numBridge; i++) {
			bridges[i].setCoorX(info.coorXBridge[i]);
			bridges[i].setCoorY(info.coorYBridge[i]);
		}

		trafficLights.resize(info.numLight);
		for (int i = 0; i < info.numLight; i++) {
			trafficLights[i].setState(info.stateLight[i]);
			trafficLights[i].setCoorX(info.coorXLight[i]);
			trafficLights[i].setCoorY(info.coorYLight[i]);
		}

		trucks.resize(info.numTruck);
		for (int i = 0; i < info.numTruck; i++) {
			trucks[i].setCoorX(info.coorXTruck[i]);
			trucks[i].setCoorY(info.coorYTruck[i]);
		}

		truck2s.resize(info.numTruck2);
		for (int i = 0; i < info.numTruck; i++) {
			truck2s[i].setCoorX(info.coorXTruck2[i]);
			truck2s[i].setCoorY(info.coorYTruck2[i]);
		}
		cars.resize(info.numCar);
		for (int i = 0; i < info.numTruck; i++) {
			cars[i].setCoorX(info.coorXCar[i]);
			cars[i].setCoorY(info.coorYCar[i]);
		}
		fileM.closeFile();
	}
}

void CGame::resetPosTrafficLight()
{
	int i = 0;
	for (auto& e : trafficLights) {
		e.setCoorY(CRoad::sepLane[i]);
		i++;
	}

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

void CGame::subThread(bool& canmove)
{
	bool isDrowned = true;
	while (isRunning) {
		if (!pp.IS_DEAD()) {
			/*pp.peopleMoving(key);*/
				//pp.drawPeople(true);
			mutex mt, mt2;
			canmove = false;

			if (pp.isNeedDraw()) {
				//	m.unlock();


				pp.drawPeople(true);
				pp.drawPeople(false);

				pp.setOldx(pp.getX());
				pp.setOldy(pp.getY());
			}
			if (pp.levelComplete()) {
				//system("cls");
				//setGame();

				//this_thread::sleep_for(chrono::microseconds(50));

				levelUp();
				pp.drawPeople(true);

				pp.drawPeople();
				pp.resetPos();

				//this_thread::sleep_for(chrono::microseconds(100));

			}
			//	cv2.notify_one();

			//lock_guard<mutex> lg(mt);

		}
		isDrowned = true;

		sort(bridges.begin(), bridges.end(), [](const CBridge& a, const CBridge& b) {
			return a.getCoorX() <= b.getCoorX();
			});
		for (int i = 0; i < bridges.size(); i++) {
			isDrowned = isDrowned && pp.isDrown(bridges[i]);
			for (int j = i + 1; j < bridges.size(); j++) {
				if (bridges[i].getCoorX() + bridges[i].getWidth() >= bridges[j].getCoorX()) {

					CBridge temp(bridges[i].getCoorX(), bridges[i].getCoorY());
					temp.setWidth(2 * bridges[i].getWidth() - (bridges[i].getCoorX() + bridges[i].getWidth() - bridges[j].getCoorX()));
					if (pp.isDrown(temp)) isDrowned = true;
					else isDrowned = false;
				}
			}

		}

		if (isDrowned) {

			pp.drawPeople(true);
			//this_thread::sleep_for(chrono::microseconds(50));
			pp.drawPeople();
			exit(0);
		}



		int maxx = 4;
		for (int i = 0; i < trafficLights.size(); i++) {

			maxx = trafficLights[i].getTime();
			if (trafficLights[i].getTime() > maxx) maxx = trafficLights[i].getTime();
			if (timer.countDown(trafficLights[i].getTime())) {
				trafficLights[i].changeLight();
			}

		}
		if (timer.countDown(maxx)) timer.setStone();
		Sleep(1);
		for (auto& e : cars) {


			if (trafficLights[1].getState() == "green") {
				e.drawObject(true);
				e.move();
				e.drawObject();
			}
			if (pp.isCollide(e)) {
				audio.playSound(hitSound);
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();
				system("pause");
			}

		}
		for (auto& e : trucks) {
			//	this_thread::sleep_for(chrono::microseconds(200 / e.getSpeed()));


			if (trafficLights[0].getState() == "green") {
				e.drawObject(true);
				e.move();
				e.drawObject();
			}

			if (pp.isCollide(e)) {
				audio.playSound(hitSound);
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();

				system("pause");

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
				audio.playSound(hitSound);
				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();

				system("pause");

			}

		}
		canmove = true;

		//Sleep(1);

	//subsub.join();
	}
}
