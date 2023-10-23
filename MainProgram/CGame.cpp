#include "CGame.h"
#include "CRoad.h"

int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 0;
int CGame::frameWidth = 100;
int CGame::frameHeight = 82;

CGame::CGame()
{
	level = 1;
	//drawFrame();
	//drawRoad();
	//drawBackGround();

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

void CGame::runGame()  // just demo
{
	vector<CCar> carList;
	vector<CTruck> truckL;

	CLane l, l2, l3;
	CRiver rv;

	CRoad r;
	r.drawWinLane();
	//cout << r.sepLane.size();
	//for (auto i : r.sepLane) cout << i << " ";
	r.setUpRoad();
	r.makeRandomLane();
	l.setCoorY(r.sepLane[0]);
	r.specifyRoad[r.sepLane[0]] = "lane";

	l2.setCoorY(r.sepLane[1]);
	r.specifyRoad[r.sepLane[1]] = "lane";

	l3.setCoorY(r.sepLane[2]);
	r.specifyRoad[r.sepLane[2]] = "lane";


	rv.setCoorY(r.sepLane[3]);
	r.specifyRoad[r.sepLane[3]] = "river";

	l.drawRoad();
	l2.drawRoad();
	l3.drawRoad();
	rv.drawRoad();
	r.drawPavement();
	CPeople people;

	/*while (1) {
		char c = CConsole::getInput();
		people.peopleMoving(c);
	}*/


	int tmp = coorTopLeftX + 1 - carWidth;
	createListObstacle<CTruck>(truckL, coorTopLeftX + 1 - carWidth, coorTopLeftY + (lane + pavement) / 2 -1, 3, "right");
	createListObstacle<CCar>(carList, coorTopLeftX + 1 + CGame::getWidth(), coorTopLeftY + 2 * (lane + pavement) / 2-1, 3, "left");
	//createListObstacle<CCar>(carList, coorTopLeftX + (lane + pavement)  - 1, 52, 4);
	while (1) {
		moveObstacle<CCar>(carList, 1);
		//moveObstacle<CTruck>(truckL, 1);
	}



}

void CGame::relaxBackGround(const int& y, int& backColor)
{

	//if (y >= CRoad::sepPave[3]) backColor = paveColor;
	if (y >= CRoad::sepLane[3] / 2 && y < CRoad::sepLane[3] / 2 + lane / 2) {
		if (CRoad::specifyRoad[CRoad::sepLane[3]] == "lane") {
			backColor = laneColor;
		}
		else backColor = riverColor;
	}
	else if (y >= CRoad::sepLane[2] / 2 && y < CRoad::sepLane[2] / 2 + lane / 2) {
		if (CRoad::specifyRoad[CRoad::sepLane[2]] == "lane") {
			backColor = laneColor;
		}
		else backColor = riverColor;
	}
	else if (y >= CRoad::sepLane[1] / 2 && y < CRoad::sepLane[1] / 2 + lane / 2) {
		if (CRoad::specifyRoad[CRoad::sepLane[1]] == "lane") {
			backColor = laneColor;
		}
		else backColor = riverColor;
	}
	else if (y >= CRoad::sepLane[0] / 2 && y < CRoad::sepLane[0] / 2 + lane / 2) {
		if (CRoad::specifyRoad[CRoad::sepLane[0]] == "lane") {
			backColor = laneColor;
		}
		else backColor = riverColor;
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

template<class obstacle>
void CGame::createListObstacle(vector<obstacle>& obs, int x, int y, int number, string direct)
{
	if (direct == "right") {
		obs.push_back(obstacle(x, y, "right"));
		int getAvg = frameWidth / number;
		if (number == 1) getAvg = frameWidth - obs.front().getWidth();
		int maxDis = (getAvg - obs.front().getWidth() ) * 2;
		int minDis = 4;


		for (int i = 1; i < number; i++) {
			int tempX = obs[i - 1].getCoorX() - obs.front().getWidth() - rand() % (maxDis - minDis) - minDis;
			obs.push_back(obstacle(tempX, y, "right"));
		}
	}
	else {
		obs.push_back(obstacle(x, y, "left"));
		int getAvg = frameWidth / number;
		if (number == 1) getAvg = frameWidth - obs.front().getWidth();
		int maxDis = (getAvg - obs.front().getWidth() - 1) * 2;
		int minDis = 4;


		for (int i = 1; i < number; i++) {
			int tempX = obs[i - 1].getCoorX() + obs.front().getWidth() + rand() % (maxDis - minDis) + minDis;
			obs.push_back(obstacle(tempX, y, "left"));
		}
	}
}

template<class obstacle>
void CGame::moveObstacle(vector<obstacle>& obs, int speed) {

	/*int getAvg = frameWidth / obs.size();
	int maxDis = (getAvg - obs.front().getWidth()) * 2;
	int minDis = 4;*/


	for (int i = 0; i < obs.size(); i++) {
		obs[i].setSpeed(speed);
		obs[i].move();

	}


	//for (int i = 0; i < obs.size(); i++) {
	//	if (!obs[i].isInBoard()) {
	//		int temp = obs[i].getCoorX;
	//		int tempX = obs[i].getCoorX() + (rand() % 2 == 0 ? 1 : -1) * (rand() % (maxDis - minDis + 1) + minDis);     //re random coorx
	//		obs[i].setCoorX(tempX);
	//		if(!obs[i].isInBoard())  
	//			obs[i].setCoorX(temp);

	//	}
	//}

}