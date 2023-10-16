#include "CGame.h"


int CGame::coorTopLeftX = 2;
int CGame::coorTopLeftY = 1;
int CGame::frameWidth = 85;
int CGame::frameHeight = 28;
CGame::CGame()
{
	level = 1;
	drawFrame();
	drawRoad();

}

void CGame::drawFrame()
{
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY, 220, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX, 219, Black);
	CConsole::drawHorLine(coorTopLeftX, coorTopLeftX + frameWidth - 1, coorTopLeftY + frameHeight * 2 - 1, 223, Black);
	CConsole::drawVerLine(coorTopLeftY, coorTopLeftY + frameHeight - 2, coorTopLeftX + frameWidth - 1, 219, Black);




}

void CGame::drawRoad()
{
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 8, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 16, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 20, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 28, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 32, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 40, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 44, Ngang, Black);
	CConsole::drawHorLine(coorTopLeftX + 1, coorTopLeftX + frameWidth - 2, 52, Ngang, Black);
}

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


void CGame::insertRectSpace(int x, int y, int height, int width, int color)
{
	for (int i = y; i >= y - height; i--) {
		CConsole::drawHorLine(x, x + width, i, 219, color);
	}
}

void CGame::runGame()
{
	CPeople people;
	vector<CCar> carList;
	vector<CCar> carList2;

	createListObstacle<CCar>(carList2, 3, 25-6, 6);
	createListObstacle<CCar>(carList, 3, 25, 4);
	while (1) {
		moveObstacle<CCar>(carList, 1);
		moveObstacle<CCar>(carList2, 2);
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
void CGame::createListObstacle(vector<obstacle>& obs, int x, int y, int number)
{
	obs.push_back(obstacle(x, y));
	int getAvg = frameWidth / number;
	int maxDis = (getAvg - obs.front().getWidth() -1) * 2;
	int minDis = 4;

	for (int i = 1; i < number; i++) {
		int tempX = obs[i - 1].getCoorX() - obs.front().getWidth() - rand() % (maxDis - minDis + 1) - minDis +1;
		obs.push_back(obstacle(tempX, y));
	}
}

template<class obstacle>
void CGame::moveObstacle(vector<obstacle>& obs, int speed) {

	int getAvg = frameWidth / obs.size();
	int maxDis = (getAvg - obs.front().getWidth()) * 2;
	int minDis = 4;


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