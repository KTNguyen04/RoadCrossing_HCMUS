#include "CPeople.h"
#include "CGame.h"

CPeople::CPeople()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2 - 2;       //bottom left
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight() / 2 - 2;
	height = 6;
	width = 8;
	color = Black;
	backColor = paveColor;
	isDead = false;
	oldX = coorX;
	oldY = coorY;
	bcl.resize(height / 2);
	//drawPeople(color);
}


void CPeople::moveUp() {   // test, not real4
	int temp = coorY;
	if (isInBoard(coorX, coorY - 3)) {
		coorY -= 3;
		oldY = temp;
		oldX = coorX;

	}
}
void CPeople::moveDown() {
	int temp = coorY;
	if (isInBoard(coorX, coorY + 3)) {
		coorY += 3;
		oldY = temp;
		oldX = coorX;
	}
}
void CPeople::moveLeft() {
	int temp = coorX;
	if (isInBoard(coorX - 4, coorY)) {
		coorX -= 4;
		oldX = temp;
		oldY = coorY;
	}
}
void CPeople::moveRight() {
	int temp = coorX;
	if (isInBoard(coorX + 4, coorY)) {
		coorX += 4;
		oldX = temp;
		oldY = coorY;
	}
}

void CPeople::drawPeople(bool isForRemove)
{
	int x, y;

	int bcl0 = -1, bcl1 = -1, bcl2 = -1;

	if (!isForRemove) {

		x = coorX;
		y = coorY;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, botBlock, DarkRed, bcl1);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, block, DarkRed, bcl1);


		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, DarkRed, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, block, Black, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, topBlock, Black, DarkGreen);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, Black, bcl0);
		CConsole::drawChar(x, y - 1, block, Black, bcl1);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, block, Black, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, Black, DarkRed);
		CConsole::drawChar(x, y - 2, topBlock, Black, DarkGreen);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		//CConsole::drawChar(x, y, topBlock, DarkRed, backColor);
		CConsole::drawChar(x, y - 1, topBlock, Black, bcl1);
		CConsole::drawChar(x, y - 2, block, Black, bcl2);
	}
	else {
		x = oldX;
		y = oldY;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);

		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, botBlock, bcl1, bcl1);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, block, bcl1, bcl1);


		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, block, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, topBlock, bcl2, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, topBlock, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, block, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		CConsole::drawChar(x, y, block, bcl0, bcl0);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, topBlock, bcl2, bcl2);

		x++;
		bcl0 = relaxBackGround(y, x);
		bcl1 = relaxBackGround(y - 1, x);
		bcl2 = relaxBackGround(y - 2, x);
		//CConsole::drawChar(x, y, topBlock, DarkRed, backColor);
		CConsole::drawChar(x, y - 1, topBlock, bcl1, bcl1);
		CConsole::drawChar(x, y - 2, block, bcl2, bcl2);
	}

}

bool CPeople::IS_DEAD()
{
	return isDead;
}

void CPeople::dead()
{
	isDead = true;
}

void CPeople::peopleMoving(char c)
{


	if (c == 'w') moveUp();
	else if (c == 'a') moveLeft();
	else if (c == 's') moveDown();
	else if (c == 'd') moveRight();
	/*drawPeople(true);
	drawPeople();*/
	//this_thread::sleep_for(chrono::milliseconds(100));
	//mPeo.unlock();


	//CGame::drawRoad();

}

bool CPeople::isInBoard(int x, int y)
{
	bool b1 = x >= CGame::getCoorTopLeftX() && (x + width) <= CGame::getCoorTopLeftX() + CGame::getWidth();
	bool b2 = (y - height / 2) >= CGame::getCoorTopLeftY() && y <= CGame::getCoorTopLeftY() + CGame::getHeight() / 2;
	return b1 && b2;
}

void CPeople::setBackColor(const int& bcl)
{
	backColor = bcl;
}

bool CPeople::isNeedDraw()
{
	return (oldX != coorX || oldY != coorY);
}

bool CPeople::levelComplete()
{
	return (coorY <= CRoad::saveLane[0] - 1);
}

void CPeople::resetPos()
{
	coorX = CGame::getCoorTopLeftX() + CGame::getWidth() / 2 - 2;       //bottom left
	coorY = CGame::getCoorTopLeftY() + CGame::getHeight() / 2 - 2;
}

bool CPeople::isCollide(const CObstacle& obs)
{
	if (coorX <= obs.getCoorX() + obs.getWidth() - 1 && coorX >= obs.getCoorX()) {
		if (coorY - height / 2 + 1 <= obs.getCoorY() && coorY - height / 2 >= obs.getCoorY() - obs.getHeight() / 2) return true;
		if (coorY >= obs.getCoorY() - obs.getHeight() / 2 + 1 && coorY <= obs.getCoorY()) return true;
	}
	if (coorX + width - 1 >= obs.getCoorX() && coorX + width <= obs.getCoorX() + obs.getWidth()) {
		if (coorY - height / 2 + 1 <= obs.getCoorY() && coorY - height / 2 >= obs.getCoorY() - obs.getHeight() / 2) return true;
		if (coorY >= obs.getCoorY() - obs.getHeight() / 2 + 1 && coorY <= obs.getCoorY()) return true;
	}
	return false;
}

bool CPeople::isDrown(const CBridge& br)
{
	if (coorY <= br.getCoorY() / 2 && coorY >= br.getCoorY() / 2 - br.getHeight() / 2 + 1)
		return (coorX < br.getCoorX()) || (coorX + width > (br.getCoorX() + br.getWidth()));
	return false;
}

int CPeople::relaxBackGround(const int& y, const int& x)
{
	int backColor = -1;
	//if (y >= CRoad::sepPave[3]) backColor = paveColor;
	if (y >= CRoad::sepLane[3] / 2 && y < CRoad::sepLane[3] / 2 + lane / 2) {
		/*if (CRoad::specifyRoad[CRoad::sepLane[3]] == "lane") {
			backColor = laneColor;
		}*/
		backColor = riverColor;
		for (int i = 0; i < CGame::sepBridges.size(); i++) {
			if (x >= CGame::sepBridges[i] && x < CGame::sepBridges[i] + bridgeWidth )
				backColor = bridgeColor;
		}
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
	return backColor;
}
