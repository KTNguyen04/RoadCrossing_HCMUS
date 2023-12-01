#include "CGame.h"
#include "CRoad.h"
#include <cmath>
#include <locale>
#include <codecvt>
#include <condition_variable>
int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 0;
int CGame::frameWidth = 100;
int CGame::frameHeight = 82;

vector<int> CGame::sepBridges;

CGame::CGame()
{
	key = 0;
	score = 0;
	//CRoad::setUpRoad();
	//sepBridges.resize(bridges.size());


}

void CGame::initGame() {
	level = 1;
	//drawFrame();
	//drawRoad();

	score = 0;

	//CRoad::drawMap();
	initTrafficLights();
	bool flag = false;
	initObstacle();
	initBridges();
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
void CGame::drawBridge() {
	for (int i = 0; i < bridges.size(); i++) {
		bridges[i].drawObject();

	}
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


char CGame::startGame()
{
	bool canmove = true, ready = false,is_running = true;
	pp.drawPeople();
	tlLightUp();
	drawBridge();
	thread t1(&CGame::subThread, this, std::ref(canmove), std::ref(ready),ref(is_running));
	while (1) {
		if (pp.IS_DEAD()||!is_running) {
			t1.join();
			if (key == 0) return deadPopUp();
			/*if (key == 'n') {
				
			}*/
			return key;
		}
		//unique_lock<mutex> lock(m);
		//cv2.wait(lock, [] {return finish_move; });
		if (canmove) {

			ready = true;

			key = CConsole::getInput();
			//if (tolower(key) == 'l') {
			//	ready = false;
			//	//CConsole::clearScreen(White);
			//	string sPath = savePopUp();
			//	if (sPath != "") {
			//		saveGame(sPath);
			//	}
			//	ready = true;
			//}
			pp.peopleMoving(key);
			Audio::playSound(moveSound);
		}

	}

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

	}
}

void CGame::initBridges()
{
	bridges.resize(2);
	sepBridges.resize(2);
	for (int i = 0; i < 2; i++) {
		CBridge brid(rand() % (frameWidth - bridgeWidth) + coorTopLeftX + 1, CRoad::sepLane[3] + lane - 1);
		bridges[i] = (brid);
		sepBridges[i] = (bridges[i].getCoorX());
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
	score += 100 / timer.timeLapse();
	showLevel(level, 171);
	showScore(score, 138);

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

	for (int i = 0; i < trafficLights.size(); i++) {

		trafficLights[i].drawTrafficLight(true);
		trafficLights[i].setState("green");
		trafficLights[i].setGreenTime(rand() % 10 + 5);
		trafficLights[i].setRedTime(rand() % 4 + 2);

	}
	resetPosTrafficLight();
	tlLightUp();

	resetPosBridge();
	for (auto& e : bridges) {
		e.drawObject();
	}
	resetPosPp();
}

void CGame::tlLightUp() {
	for (int i = 0; i < trafficLights.size(); i++) {
		trafficLights[i].lightUp();
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
void CGame::resetPosPp()
{
	pp.resetPos();
}
void CGame::increDifficulty()
{
	if (level <= 19) {
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
		info.redTime.resize(info.numLight);
		transform(trafficLights.begin(), trafficLights.end(), info.redTime.begin(),
			[](const CTrafficLight& st) { return st.getRedTime(); });
		info.greenTime.resize(info.numLight);
		transform(trafficLights.begin(), trafficLights.end(), info.greenTime.begin(),
			[](const CTrafficLight& st) { return st.getGreenTime(); });
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
		info.truckSpeed.resize(info.numTruck);

		transform(trucks.begin(), trucks.end(), info.truckSpeed.begin(),
			[](const CTruck& st) { return st.getSpeed(); });

		info.numTruck2 = truck2s.size();
		info.coorXTruck2.resize(info.numTruck2);

		transform(truck2s.begin(), truck2s.end(), info.coorXTruck2.begin(),
			[](const CTruck& st) { return st.getCoorX(); });
		info.coorYTruck2.resize(info.numTruck2);

		transform(truck2s.begin(), truck2s.end(), info.coorYTruck2.begin(),
			[](const CTruck& st) { return st.getCoorY(); });
		info.truck2Speed.resize(info.numTruck2);

		transform(truck2s.begin(), truck2s.end(), info.truck2Speed.begin(),
			[](const CTruck& st) { return st.getSpeed(); });

		info.numCar = cars.size();
		info.coorXCar.resize(info.numCar);

		transform(cars.begin(), cars.end(), info.coorXCar.begin(),
			[](const CCar& st) { return st.getCoorX(); });
		info.coorYCar.resize(info.numCar);

		transform(cars.begin(), cars.end(), info.coorYCar.begin(),
			[](const CCar& st) { return st.getCoorY(); });
		info.carSpeed.resize(info.numCar);

		transform(cars.begin(), cars.end(), info.carSpeed.begin(),
			[](const CCar& st) { return st.getSpeed(); });
		fileM.saving<saveInfo>(info);

		fileM.closeFile();

		fileM.setPath(savedFilePath, rootP);
		if (fileM.openFile()) {

			fileNames fn;
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
		//system("cls");
		saveInfo info = fileM.loading<saveInfo>();
		level = info.level;
		score = info.score;
		pp.setX(info.peopleX);
		pp.setY(info.peopleY);
		pp.dead(info.people_isDead);

		CRoad::sepLane.resize(info.numLane);
		for (int i = 0; i < info.numLane; i++) {
			CRoad::sepLane[i] = info.coorYLane[i];
		}

		bridges.resize(info.numBridge);
		sepBridges.resize(info.numBridge);
		for (int i = 0; i < info.numBridge; i++) {
			bridges[i].setCoorX(info.coorXBridge[i]);
			bridges[i].setCoorY(info.coorYBridge[i]);
			sepBridges[i] = bridges[i].getCoorX();

		}

		trafficLights.resize(info.numLight);
		for (int i = 0; i < info.numLight; i++) {
			trafficLights[i].setState(info.stateLight[i]);
			trafficLights[i].setGreenTime(info.greenTime[i]);
			trafficLights[i].setRedTime(info.redTime[i]);
			trafficLights[i].setCoorX(info.coorXLight[i]);
			trafficLights[i].setCoorY(info.coorYLight[i]);
		}

		trucks.resize(info.numTruck);
		for (int i = 0; i < info.numTruck; i++) {
			trucks[i].setCoorX(info.coorXTruck[i]);
			trucks[i].setCoorY(info.coorYTruck[i]);
		}

		truck2s.resize(info.numTruck2);
		for (int i = 0; i < info.numTruck2; i++) {
			truck2s[i].setCoorX(info.coorXTruck2[i]);
			truck2s[i].setCoorY(info.coorYTruck2[i]);
		}
		cars.resize(info.numCar);
		for (int i = 0; i < info.numCar; i++) {
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

void CGame::subThread(bool& canmove, bool& rd, bool& isRun)
{
	bool isDrowned = true;
	while (!pp.IS_DEAD()) {
		if (rd) {
			if (tolower(key )== 'r') {
				isRun = false;
				return;
			}
			if (tolower(key) == 'l') {
				canmove = false;
				string s = savePopUp();
				if (s == "newgame") {
					key = 'n';
					isRun = false;
					return;
				}

				key = 0;
				canmove = true;
				savePopUp(true);



			}
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
				canmove = false;
				Audio::playSound(levelUpSound);
				//this_thread::sleep_for(chrono::microseconds(50));

				levelUp();
				/*if (level > 19) {
					isRun = false;
					return;
				}*/

				pp.drawPeople(true);

				pp.drawPeople();
				canmove = true;
//this_thread::sleep_for(chrono::microseconds(100));

			}
			//	cv2.notify_one();

			//lock_guard<mutex> lg(mt);


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
				audio.playSound(diveSound);
				pp.dead(true);
				Sleep(1);

				pp.drawPeople(true);
				//this_thread::sleep_for(chrono::microseconds(50));
				pp.drawPeople();
				
				key = deadPopUp();

				canmove = true;

			
				continue;

				//exit(0);
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
					pp.dead(true);

					audio.playSound(hitSound);
					Sleep(1);

					pp.drawPeople(true);
					//this_thread::sleep_for(chrono::microseconds(50));
					pp.drawPeople();
					//audio.playSound(gameOverSound);

					key = deadPopUp();
					canmove = true;

					continue;



					//system("pause");
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
					pp.dead(true);

					audio.playSound(hitSound);
					Sleep(1);

					pp.drawPeople(true);
					//this_thread::sleep_for(chrono::microseconds(50));
					pp.drawPeople();



					key = deadPopUp();


					continue;

					//system("pause");

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
					pp.dead(true);

					audio.playSound(hitSound);


					pp.drawPeople(true);
					//this_thread::sleep_for(chrono::microseconds(50));
					pp.drawPeople();


					key = deadPopUp();


					continue;


					//system("pause");

				}

			}
			canmove = true;

			//Sleep(1);

		//subsub.join();
		}
	}
	return;
}




bool CGame::isAvail(string input)
{

	fileM.setPath(savedFilePath, rootP);
	if (fileM.openFile()) {
		fileNames fn = fileM.loading<fileNames>();
		fileM.closeFile();
		return find(fn.names.begin(), fn.names.end(), input) == fn.names.end();
	}
	return false;
}

char CGame::deadPopUp()
{
	Sleep(1000);
	Audio::playSound(gameOverSound);
	//clean khung;
	for (int i = 1; i <= 102; i++) {
		for (int j = 8; j <= 32; j++) {
			CConsole::drawChar(i, j, block, 15, 0, false);
		}
	}

	//ve khung
	CConsole::drawHorLine(2, 101, 9, topBlock, 0, 15);
	CConsole::drawVerLine(9, 31, 2, block, 0, 15);
	CConsole::drawVerLine(9, 31, 101, block, 0, 15);
	CConsole::drawHorLine(2, 101, 31, botBlock, 15, 0);

	//ve khung phu
	CConsole::drawHorLine(4, 12, 10, topBlock, 0, 15);
	CConsole::drawVerLine(10, 16, 4, block, 0, 15);
	CConsole::drawVerLine(23, 29, 99, block, 0, 15);
	CConsole::drawHorLine(91, 99, 30, botBlock, 15, 0);

	//ve cham trang tri;
	CConsole::drawChar(99, 10, block, 0, 15, false);
	CConsole::drawChar(98, 10, block, 0, 15, false);

	CConsole::drawHorLine(4, 5, 30, topBlock, 0, 15);
	CConsole::drawHorLine(4, 5, 29, botBlock, 0, 15);


	//ve game over
	 //Draw G
	CConsole::drawVerLine(11 + 1, 13 + 1, 9 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 13 + 1, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(11 + 1, 16 + 1, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(13 + 1, 16 + 1, 12 + 1, block, 4, 15);
	CConsole::drawHorLine(15 + 1, 16 + 1, 13 + 1, block, 4, 15);
	CConsole::drawHorLine(11 + 1, 14 + 1, 14 + 1, block, 4, 15);
	//Draw A
	CConsole::drawHorLine(19 + 1 + 1, 22 + 1 + 1, 10 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 14 + 1, 17 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 14 + 1, 18 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 14 + 1, 23 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 14 + 1, 24 + 1 + 1, block, 4, 15);
	CConsole::drawHorLine(19 + 1 + 1, 22 + 1 + 1, 12 + 1, block, 4, 15);
	//Draw M
	CConsole::drawVerLine(10 + 1, 14 + 1, 27 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 14 + 1, 28 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 14 + 1, 35 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 14 + 1, 36 + 1 + 1, block, 4, 15);
	CConsole::drawHorLine(29 + 1 + 1, 30 + 1 + 1, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(31 + 1 + 1, 32 + 1 + 1, 11 + 1, block, 4, 15);
	CConsole::drawHorLine(31 + 1 + 1, 32 + 1 + 1, 12 + 1, block, 4, 15);
	CConsole::drawHorLine(33 + 1 + 1, 34 + 1 + 1, 10 + 1, block, 4, 15);
	//Draw E
	CConsole::drawVerLine(10 + 1, 14 + 1, 38 + 1 + 1, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 14 + 1, 39 + 1 + 1, block, 4, 15);
	CConsole::drawHorLine(40 + 1 + 1, 43 + 1 + 1, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(40 + 1 + 1, 43 + 1 + 1, 12 + 1, block, 4, 15);
	CConsole::drawHorLine(40 + 1 + 1, 43 + 1 + 1, 14 + 1, block, 4, 15);

	//Draw O
	CConsole::drawHorLine(59, 62, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(59, 62, 14 + 1, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 13 + 1, 57, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 13 + 1, 58, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 13 + 1, 63, block, 4, 15);
	CConsole::drawVerLine(11 + 1, 13 + 1, 64, block, 4, 15);

	//Draw V
	CConsole::drawVerLine(10 + 1, 12 + 1, 66, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 12 + 1, 67, block, 4, 15);
	CConsole::drawVerLine(13 + 1, 13 + 1, 68, block, 4, 15);
	CConsole::drawVerLine(13 + 1, 14 + 1, 69, block, 4, 15);
	CConsole::drawVerLine(13 + 1, 14 + 1, 70, block, 4, 15);
	CConsole::drawVerLine(13 + 1, 13 + 1, 71, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 12 + 1, 72, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 12 + 1, 73, block, 4, 15);

	//Draw E
	CConsole::drawVerLine(10 + 1, 14 + 1, 66 + 9, block, 4, 15);
	CConsole::drawVerLine(10 + 1, 14 + 1, 67 + 9, block, 4, 15);
	CConsole::drawHorLine(68 + 9, 71 + 9, 10 + 1, block, 4, 15);
	CConsole::drawHorLine(68 + 9, 71 + 9, 12 + 1, block, 4, 15);
	CConsole::drawHorLine(68 + 9, 71 + 9, 14 + 1, block, 4, 15);

	//Draw R
	CConsole::drawHorLine(54 + 28, 59 + 28, 0 + 10 + 1, block, 4, 15);
	CConsole::drawVerLine(1 + 10 + 1, 4 + 10 + 1, 54 + 28, block, 4, 15);
	CConsole::drawVerLine(1 + 10 + 1, 4 + 10 + 1, 55 + 28, block, 4, 15);
	CConsole::drawHorLine(56 + 28, 59 + 28, 2 + 10 + 1, block, 4, 15);
	CConsole::drawHorLine(58 + 28, 59 + 28, 3 + 10 + 1, block, 4, 15);
	CConsole::drawHorLine(60 + 28, 61 + 28, 1 + 10 + 1, block, 4, 15);
	CConsole::drawHorLine(60 + 28, 61 + 28, 4 + 10 + 1, block, 4, 15);

	CConsole::gotoXY(7, 20);
	cout << "               Press: ";
	CConsole::gotoXY(30, 22);
	cout << "               L To SAVE";
	CConsole::gotoXY(30, 24);
	cout << "               R To BACK";
	CConsole::gotoXY(30, 26);
	cout << "               N to New Game";
	cin.clear();
	char choice;
	do {
		choice = CConsole::getInput();
	} while (choice != 'l' && choice != 'r' && choice != 'n');
	return choice;
}

char CGame::victoryPopUp()
{
	Sleep(1000);
	Audio::playSound(victorySound);
	//clean khung;
	for (int i = 1; i <= 102; i++) {
		for (int j = 8; j <= 32; j++) {
			CConsole::drawChar(i, j, block, 15, 0, false);
		}
	}

	//ve khung
	CConsole::drawHorLine(2, 101, 9, topBlock, 0, 15);
	CConsole::drawVerLine(9, 31, 2, block, 0, 15);
	CConsole::drawVerLine(9, 31, 101, block, 0, 15);
	CConsole::drawHorLine(2, 101, 31, botBlock, 15, 0);

	//ve khung phu
	CConsole::drawHorLine(4, 12, 10, topBlock, 0, 15);
	CConsole::drawVerLine(10, 16, 4, block, 0, 15);
	CConsole::drawVerLine(23, 29, 99, block, 0, 15);
	CConsole::drawHorLine(91, 99, 30, botBlock, 15, 0);

	//ve cham trang tri;
	CConsole::drawChar(99, 10, block, 0, 15, false);
	CConsole::drawChar(98, 10, block, 0, 15, false);

	CConsole::drawHorLine(4, 5, 30, topBlock, 0, 15);
	CConsole::drawHorLine(4, 5, 29, botBlock, 0, 15);

	//Draw VICTORY
	//Draw V
	CConsole::drawVerLine(11, 13, 20, block, Red,White);
	CConsole::drawVerLine(11, 13, 21, block,Red, White);
	CConsole::drawHorLine(22, 23, 14, block, Red, White);
	CConsole::drawHorLine(26, 27, 14, block, Red, White);
	CConsole::drawHorLine(24, 25, 15, block, Red, White);
	CConsole::drawVerLine(11, 13, 28, block, Red, White);
	CConsole::drawVerLine(11, 13, 29, block, Red, White);
	//Draw I
	CConsole::drawHorLine(31, 32, 11, block, Red, White);
	CConsole::drawHorLine(35, 36, 11, block, Red, White);
	CConsole::drawHorLine(31, 32, 15, block, Red, White);
	CConsole::drawHorLine(35, 36, 15, block, Red, White);
	CConsole::drawVerLine(11, 15, 33, block, Red, White);
	CConsole::drawVerLine(11, 15, 34, block, Red, White);
	//Draw C
	CConsole::drawHorLine(40, 43, 11, block, Red, White);
	CConsole::drawVerLine(12, 14, 38, block, Red, White);
	CConsole::drawVerLine(12, 14, 39, block, Red, White);
	CConsole::drawHorLine(44, 45, 12, block, Red, White);
	CConsole::drawHorLine(44, 45, 14, block, Red, White);
	CConsole::drawHorLine(40, 43, 15, block, Red, White);
	//Draw T
	CConsole::drawVerLine(11, 15, 50, block, Red, White);
	CConsole::drawVerLine(11, 15, 51, block, Red, White);
	CConsole::drawHorLine(47, 49, 11, block, Red, White);
	CConsole::drawHorLine(52, 54, 11, block, Red, White);
	//Draw O
	CConsole::drawHorLine(58, 61, 11, block, Red, White);
	CConsole::drawHorLine(58, 61, 15, block, Red, White);
	CConsole::drawVerLine(12, 14, 56, block, Red, White);
	CConsole::drawVerLine(12, 14, 57, block, Red, White);
	CConsole::drawVerLine(12, 14, 62, block, Red, White);
	CConsole::drawVerLine(12, 14, 63, block, Red, White);
	//Draw R
	CConsole::drawVerLine(11, 15, 65, block, Red, White);
	CConsole::drawVerLine(11, 15, 66, block, Red, White);
	CConsole::drawHorLine(67, 70, 11, block, Red, White);
	CConsole::drawHorLine(67, 70, 13, block, Red, White);
	CConsole::drawHorLine(69, 70, 14, block, Red, White);
	CConsole::drawHorLine(71, 72, 12, block, Red, White);
	CConsole::drawHorLine(71, 72, 15, block, Red, White);
	//Draw Y
	CConsole::drawVerLine(11, 13, 74, block, Red, White);
	CConsole::drawVerLine(11, 13, 75, block, Red, White);
	CConsole::drawVerLine(11, 13, 78, block, Red, White);
	CConsole::drawVerLine(11, 13, 79, block, Red, White);
	CConsole::drawVerLine(13, 15, 76, block, Red, White);
	CConsole::drawVerLine(13, 15, 77, block, Red, White);

	CConsole::gotoXY(21, 20);
	cout << "               You have won all the levels";
	CConsole::gotoXY(30, 22);
	cout << "               Press: ";
	CConsole::gotoXY(30, 24);
	cout << "               L To SAVE";
	CConsole::gotoXY(30, 26);
	cout << "               R To BACK";
	cin.clear();
	char choice;
	do {
		choice = CConsole::getInput();
	} while (choice != 'l' && choice != 'r');
	return choice;
}

string CGame::loadPopUp() {
	//CConsole::clearScreen(White);
	CConsole::drawHorLine(68 + 20, 93 + 20, 21 - 15, topBlock, 4, 15);
	CConsole::drawChar(67 + 20, 21 - 15, botBlock, 4, 15);
	CConsole::drawChar(94 + 20, 21 - 15, botBlock, 4, 15);
	CConsole::drawVerLine(22 - 15, 23 - 15, 66 + 20, block, 4, 15);
	CConsole::drawVerLine(22 - 15, 23 - 15, 95 + 20, block, 4, 15);
	CConsole::drawChar(66 + 20, 24 - 15, topBlock, 4, 15);
	CConsole::drawChar(95 + 20, 24 - 15, topBlock, 4, 15);
	CConsole::drawChar(67 + 20, 24 - 15, botBlock, 4, 15);
	CConsole::drawChar(94 + 20, 24 - 15, botBlock, 4, 15);
	CConsole::drawHorLine(68 + 20, 93 + 20, 25 - 15, topBlock, 4, 15);
	//Draw L
	CConsole::drawVerLine(22 - 15, 23 - 15, 71 + 20 + 1, block, 4, 15);
	CConsole::drawChar(71 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawHorLine(72 + 20 + 1, 73 + 20 + 1, 24 - 15, topBlock, 4, 15);
	//Draw O 
	CConsole::drawHorLine(76 + 20 + 1, 77 + 20 + 1, 22 - 15, topBlock, 4, 15);
	CConsole::drawHorLine(76 + 20 + 1, 77 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawChar(75 + 20 + 1, 23 - 15, block, 4, 15);
	CConsole::drawChar(78 + 20 + 1, 23 - 15, block, 4, 15);
	CConsole::drawChar(75 + 20 + 1, 22 - 15, botBlock, 4, 15);
	CConsole::drawChar(78 + 20 + 1, 22 - 15, botBlock, 4, 15);
	//Draw A
	CConsole::drawHorLine(81 + 20 + 1, 82 + 20 + 1, 22 - 15, topBlock, 4, 15);
	CConsole::drawChar(80 + 20 + 1, 22 - 15, botBlock, 4, 15);
	CConsole::drawChar(83 + 20 + 1, 22 - 15, botBlock, 4, 15);
	CConsole::drawChar(80 + 20 + 1, 23 - 15, block, 4, 15);
	CConsole::drawChar(83 + 20 + 1, 23 - 15, block, 4, 15);
	CConsole::drawChar(80 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawChar(83 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawHorLine(81 + 20 + 1, 82 + 20 + 1, 23 - 15, topBlock, 4, 15);
	//Draw D
	CConsole::drawVerLine(22 - 15, 23 - 15, 85 + 20 + 1, block, 4, 15);
	CConsole::drawChar(85 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawHorLine(86 + 20 + 1, 87 + 20 + 1, 22 - 15, topBlock, 4, 15);
	CConsole::drawHorLine(86 + 20 + 1, 87 + 20 + 1, 24 - 15, topBlock, 4, 15);
	CConsole::drawChar(88 + 20 + 1, 23 - 15, block, 4, 15);
	CConsole::drawChar(88 + 20 + 1, 22 - 15, botBlock, 4, 15);
	string s = "Press R to back";
	CConsole::drawString(CConsole::getConsoleWid() / 2, CConsole::getConsoleHei() - 10, s, DarkRed);
	fileM.setPath(savedFilePath, rootP);
	if (fileM.openFile()) {
		fileNames fn = fileM.loading<fileNames>();


		int startIndex = 0;
		int currChoice = 1; // i = choice - 1, tuc choice = 1 thi index trong mang la 0

		char userInput;
		do {
			CConsole::gotoXY(95, 20);
			for (int i = 0; i < 20; i++) {
				cout << "                                                                                                                        " << endl;
			}
			CConsole::gotoXY(95, 20);
			// Clear the console, you can change this based on your system
			for (int i = startIndex; i < startIndex + 5 && i < fn.names.size(); ++i) {
				if (i == currChoice - 1) {
					std::cout << "> " << fn.names[i] << endl << std::endl << std::endl << "                                                                                               ";
				}
				else {
					std::cout << "  " << fn.names[i] << std::endl << std::endl << std::endl << "                                                                                               ";
				}
			}
			userInput = _getch();
			switch (userInput) {
			case 's':
				if (currChoice < fn.names.size())
					++currChoice;
				if (startIndex + 5 < fn.names.size() && currChoice > 5 && currChoice % 5 == 1) {
					startIndex += 5;
				}
				break;
			case 'w':
				if (currChoice > 1)
					--currChoice;
				if (startIndex - 5 >= 0 && currChoice >= 5 && currChoice % 5 == 0) {
					startIndex -= 5;
				}
				break;
			}
			if (tolower(userInput) == 'r') {
				fileM.closeFile();
				return "";
			}
		} while (userInput != 13);
		fileM.closeFile();
		return fn.names[currChoice - 1];
	}
	return "";
}

string CGame::savePopUp(bool isForRemove) {
	if (!isForRemove) {
		CConsole::showConsoleCursor(true);


		CConsole::drawHorLine(2, 101, 43, topBlock, 0, 15);
		CConsole::drawVerLine(43, 53, 2, block, 0, 15);
		CConsole::drawVerLine(43, 53, 101, block, 0, 15);
		CConsole::drawHorLine(2, 101, 53, botBlock, 15, 0);



		string file_name;



		string s = "Enter filename you would like to save as: ";
		CConsole::drawString(15, 45, s, Black);
		CConsole::gotoXY(75, 45);
		cin >> file_name;
		cin.ignore();
		file_name += ".bin";
		do {

			if (!isAvail(file_name) || file_name == ".bin") {
				string s = "This name is not valid! Try again: ";
				CConsole::drawString(15, 46, s, Black);
				/*		s = "                ";
						CConsole::drawString(75, 45, s, Black);*/
				CConsole::gotoXY(75, 46);
				cin >> file_name;
				cin.ignore();
				file_name += ".bin";
			}
			else {

				string s = "Save as: " + file_name;
				CConsole::drawString(15, 47, s, Black);
				s = "Are you sure ? R to back, Y to accept, N to enter again ";
				CConsole::drawString(15, 48, s, Black);
				char c = CConsole::getInput();
				if (c == 'r') return "";
				else if (c == 'n') {
					file_name = ".bin";
					continue;
				}
				else if (c == 'y') {
					if (saveGame(file_name))
						s = "Saved successfully, N to new game or R to back";
					else s = "Failed, try again";
					CConsole::drawString(15, 49, s, Black);
					do {
						char c = CConsole::getInput();
						if (c == 'r')
							return "";
						else if (c == 'n')
							return "newgame";
					} while (1);
				}
			}

		} while (1);
		return "";
	}
	else {
		fillRect(2, 43, 10, 100, block, background);
		return "";
	}
}

void CGame::showScore(int score, int x) {
	CMenu g;
	x = 138;
	g.clearScoreBoard(true, Blue);
	// Draw each digit at appropriate positions
	if (score >= 0 && score < 10)
	{
		switch (score) {
		case 0:
			g.drawNumber0(false, Black, Blue, x);
			break;
		case 1:
			g.drawNumber1(false, Black, Blue, x);
			break;
		case 2:
			g.drawNumber2(false, Black, Blue, x);
			break;
		case 3:
			g.drawNumber3(false, Black, Blue, x);
			break;
		case 4:
			g.drawNumber4(false, Black, Blue, x);
			break;
		case 5:
			g.drawNumber5(false, Black, Blue, x);
			break;
		case 6:
			g.drawNumber6(false, Black, Blue, x);
			break;
		case 7:
			g.drawNumber7(false, Black, Blue, x);
			break;
		case 8:
			g.drawNumber8(false, Black, Blue, x);
			break;
		case 9:
			g.drawNumber9(false, Black, Blue, x);
			break;
		}
	}
	else if (score >= 10 && score < 100)
	{
		x -= 3;
		std::vector<int> digits;
		while (score > 0) {
			digits.push_back(score % 10);
			score /= 10;
		}
		for (int i = digits.size() - 1; i >= 0; --i) {
			switch (digits[i]) {
			case 0:
				g.drawNumber0(false, Black, Blue, x);
				break;
			case 1:
				g.drawNumber1(false, Black, Blue, x);
				break;
			case 2:
				g.drawNumber2(false, Black, Blue, x);
				break;
			case 3:
				g.drawNumber3(false, Black, Blue, x);
				break;
			case 4:
				g.drawNumber4(false, Black, Blue, x);
				break;
			case 5:
				g.drawNumber5(false, Black, Blue, x);
				break;
			case 6:
				g.drawNumber6(false, Black, Blue, x);
				break;
			case 7:
				g.drawNumber7(false, Black, Blue, x);
				break;
			case 8:
				g.drawNumber8(false, Black, Blue, x);
				break;
			case 9:
				g.drawNumber9(false, Black, Blue, x);
				break;
			}
			// Move to the next digit position
			x += 5; // Adjust this value based on the spacing between digits
		}
	}
	else if (score >= 100 && score < 1000)
	{
		x -= 5;
		std::vector<int> digits;
		while (score > 0) {
			digits.push_back(score % 10);
			score /= 10;
		}
		for (int i = digits.size() - 1; i >= 0; --i) {
			switch (digits[i]) {
			case 0:
				g.drawNumber0(false, Black, Blue, x);
				break;
			case 1:
				g.drawNumber1(false, Black, Blue, x);
				break;
			case 2:
				g.drawNumber2(false, Black, Blue, x);
				break;
			case 3:
				g.drawNumber3(false, Black, Blue, x);
				break;
			case 4:
				g.drawNumber4(false, Black, Blue, x);
				break;
			case 5:
				g.drawNumber5(false, Black, Blue, x);
				break;
			case 6:
				g.drawNumber6(false, Black, Blue, x);
				break;
			case 7:
				g.drawNumber7(false, Black, Blue, x);
				break;
			case 8:
				g.drawNumber8(false, Black, Blue, x);
				break;
			case 9:
				g.drawNumber9(false, Black, Blue, x);
				break;

			}
			// Move to the next digit position
			x += 5; // Adjust this value based on the spacing between digits
		}
	}
}
void CGame::showLevel(int level, int x)
{
	CMenu g;
	g.clearLevelBoard(true, Yellow);
	// Draw each digit at appropriate positions
	if (level > 0 && level < 10)
	{
		switch (level) {
		case 0:
			g.drawNumber0(false, Black, Yellow, x);
			break;
		case 1:
			g.drawNumber1(false, Black, Yellow, x);
			break;
		case 2:
			g.drawNumber2(false, Black, Yellow, x);
			break;
		case 3:
			g.drawNumber3(false, Black, Yellow, x);
			break;
		case 4:
			g.drawNumber4(false, Black, Yellow, x);
			break;
		case 5:
			g.drawNumber5(false, Black, Yellow, x);
			break;
		case 6:
			g.drawNumber6(false, Black, Yellow, x);
			break;
		case 7:
			g.drawNumber7(false, Black, Yellow, x);
			break;
		case 8:
			g.drawNumber8(false, Black, Yellow, x);
			break;
		case 9:
			g.drawNumber9(false, Black, Yellow, x);
			break;
		}
	}
	else if (level >= 10 && level < 100)
	{
		x -= 3;
		std::vector<int> digits;
		while (level > 0) {
			digits.push_back(level % 10);
			level /= 10;
		}
		for (int i = digits.size() - 1; i >= 0; --i) {
			switch (digits[i]) {
			case 0:
				g.drawNumber0(false, Black, Yellow, x);
				break;
			case 1:
				g.drawNumber1(false, Black, Yellow, x);
				break;
			case 2:
				g.drawNumber2(false, Black, Yellow, x);
				break;
			case 3:
				g.drawNumber3(false, Black, Yellow, x);
				break;
			case 4:
				g.drawNumber4(false, Black, Yellow, x);
				break;
			case 5:
				g.drawNumber5(false, Black, Yellow, x);
				break;
			case 6:
				g.drawNumber6(false, Black, Yellow, x);
				break;
			case 7:
				g.drawNumber7(false, Black, Yellow, x);
				break;
			case 8:
				g.drawNumber8(false, Black, Yellow, x);
				break;
			case 9:
				g.drawNumber9(false, Black, Yellow, x);
				break;
			}

			// Move to the next digit position
			x += 5; // Adjust this value based on the spacing between digits
		}
	}
}
int CGame::getScore()
{
	return score;
}
int CGame::getLevel()
{
	return level;
}