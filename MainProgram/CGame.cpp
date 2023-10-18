#include "CGame.h"


int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 0;
int CGame::frameWidth = 100;
int CGame::frameHeight = 82;

CGame::CGame()
{
	level = 1;
	drawFrame();
	drawRoad();
	//drawBackGround();

}

void CGame::drawFrame()
{
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY, Ngang, Black);
	CConsole::drawChar(coorTopLeftX, coorTopLeftY, 218, Black);
	CConsole::drawVerLine(coorTopLeftY + 1, coorTopLeftY + frameHeight / 2 - 2, coorTopLeftX, ThangDung, Black);
	CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY, 191, Black);

	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + frameHeight / 2 - 1, Ngang, Black);
	CConsole::drawChar(coorTopLeftX, coorTopLeftY + frameHeight / 2 - 1, 192, Black);

	CConsole::drawVerLine(coorTopLeftY + 1, coorTopLeftY + frameHeight / 2 - 2, coorTopLeftX + frameWidth - 1, ThangDung, Black);
	CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + frameHeight / 2 - 1, 217, Black);





}

void CGame::drawRoad()
{
	for (int i = 0; i < 4; i++) {
		CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + pavement / 2 + i * (lane + pavement) / 2, Ngang, Black);
		CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, coorTopLeftY + (i + 1) * (lane + pavement) / 2, Ngang, Black);
	}
	for (int i = 0; i < 4; i++) {
		CConsole::drawChar(coorTopLeftX, coorTopLeftY + pavement / 2 + i * (lane + pavement) / 2, 195, Black);
		CConsole::drawChar(coorTopLeftX, coorTopLeftY + (i + 1) * (lane + pavement) / 2, 195, Black);

		CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + 4 + i * 9, 180, Black);
		CConsole::drawChar(coorTopLeftX + frameWidth - 1, coorTopLeftY + 9 + i * 9, 180, Black);

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

void CGame::fillRect(int x, int y, int hei, int wid, char c, int color)
{
	for (int i = y; i <= y + hei; i++) {
		CConsole::drawHorLine(x, x + wid, i, c, color);
	}
}

void CGame::runGame()  // just demo
{
	CPeople people;
	vector<CCar> carList;
	vector<CCar> carList2;

	CLane l, l2, l3, l4;

	CRoad r;
	r.drawPavement();
	l.setCoorY(r.sepLane[0]);
	l.drawRoad();

	l2.setCoorY(r.sepLane[1]);
	l2.drawRoad();
	l3.setCoorY(r.sepLane[2]);
	l3.drawRoad();
	l4.setCoorY(r.sepLane[3]);
	l4.drawRoad();


	while (1) {
		char c = CConsole::getInput();
		people.peopleMoving(c);
	}
	createListObstacle<CCar>(carList2, coorTopLeftX + 1, coorTopLeftY + (lane + pavement) / 2 - 1, 1);
	//createListObstacle<CCar>(carList, coorTopLeftX + (lane + street)  - 1, 52, 4);
	//while (1) {
	//	//moveObstacle<CCar>(carList, 1);
	//	moveObstacle<CCar>(carList2, 1);
	//}



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
void CGame::createListObstacle(vector<obstacle>& obs, int x, int y, int number)
{
	obs.push_back(obstacle(x, y));
	int getAvg = frameWidth / number;
	if (number == 1) getAvg = frameWidth - obs.front().getWidth();
	int maxDis = (getAvg - obs.front().getWidth() - 1) * 2;
	int minDis = 4;


	for (int i = 1; i < number; i++) {
		int tempX = obs[i - 1].getCoorX() - obs.front().getWidth() - rand() % (maxDis - minDis) - minDis;
		obs.push_back(obstacle(tempX, y));
	}
}

template<class obstacle>
void CGame::moveObstacle(vector<obstacle>& obs, int speed) {

	/*int getAvg = frameWidth / obs.size();
	int maxDis = (getAvg - obs.front().getWidth()) * 2;
	int minDis = 4;*/


	for (int i = 0; i < obs.size(); i++) {
		obs[i].setSpeed(speed);
		obs[i].move("right");

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