#include "CRoad.h"
#include "CGame.h"
#include <random>   
#include <cmath>
#include <chrono>   
vector<int>CRoad::sepLane;
vector<int>CRoad::saveLane;
vector<int>CRoad::sepPave;
map<int, string> CRoad::specifyRoad;
void CRoad::setUpRoad()
{
	for (int i = 0; i < 4; i++) {
		int temp = CGame::getCoorTopLeftY() + pavement + i * (lane + pavement);
		sepLane.push_back(temp);
		saveLane.push_back(temp);
		sepPave.push_back(temp + lane);
	}
}

void CRoad::drawRoad(const int&y,const int &color)
{
	
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, y / 2, block, color, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, y / 2 + 1, block, color, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, y / 2 + 2, block, color, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, y / 2 + 3, block, color, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, y / 2 + 4, block, color, background);
}

void CRoad::drawPavement()
{
	for (int i = 0; i < 4; i++) {
		//int backCl = specifyRoad[saveLane[i]] == "lane" ? laneColor : riverColor;
		CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, sepPave[i] / 2, block, paveColor, background);
		CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, sepPave[i] / 2 + 1, block, paveColor, background);
		CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, sepPave[i] / 2 + 2, block, paveColor, background);
		CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, sepPave[i] / 2 + 3, block, paveColor, background);
		//if (i == 3) backCl = background;
		//else
		//	backCl = specifyRoad[saveLane[i + 1]] == "lane" ? laneColor : riverColor;
		//
		//CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, sepPave[i] / 2 + pavement / 2, topBlock, paveColor, backCl);

	}
}
void CRoad::setCoorY(int y)
{
	this->coorY = y;
}

void CRoad::setCoorX(int x)
{
	this->coorX = x;
}

void CRoad::drawMap()
{
	
	setUpRoad();
	drawWinLane();
	drawRoad(sepLane[0],laneColor);
	drawRoad(sepLane[1],laneColor);
	drawRoad(sepLane[2],laneColor);
	drawRoad(sepLane[3], riverColor);
	drawPavement();
}

void CRoad::drawWinLane()
{
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, CGame::getCoorTopLeftY(), botBlock, winColor, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, CGame::getCoorTopLeftY() + 1, block, winColor, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, CGame::getCoorTopLeftY() + 2, block, winColor, background);
	CConsole::drawHorLine(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftX() + CGame::getWidth() - 1, CGame::getCoorTopLeftY() + 3, block, winColor, background);


}

void CRoad::makeRandomLane() {
	swap(sepLane[0], sepLane[1]);
	swap(sepLane[2], sepLane[3]);
	swap(sepLane[0], sepLane[3]);
	
}

