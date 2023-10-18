#include "CRoad.h"
#include "CGame.h"

CRoad::CRoad()
{
	for (int i = 0; i < 4; i++)
		sepLane.push_back(CGame::getCoorTopLeftY() + pavement / 2 + i * (lane + pavement) / 2);
}

void CRoad::drawPavement()
{
	for (int i = 0; i < 4; i++) {
		CGame::fillRect(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftY() + (pavement + lane) / 2 + i * (pavement + lane) / 2 , 0, CGame::getWidth() - 1, 220, paveColor);
		CGame::fillRect(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftY() + (pavement + lane) / 2 + i * (pavement + lane) / 2 + 1, pavement / 2 - 1, CGame::getWidth() - 1, 219, paveColor);
		CGame::fillRect(CGame::getCoorTopLeftX(), CGame::getCoorTopLeftY() + (pavement + lane) / 2 + pavement / 2 + i * (pavement + lane) / 2, 0, CGame::getWidth() - 1, 219, paveColor);
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
template<class makeRoad>
void CRoad::makeRandomLane() {

}