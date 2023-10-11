#pragma once
#include "CConsole.h"
#include "CGame.h"
class CPeople
{
	int coorX, coorY;
	int height, width;
	int color;
public:
	CPeople();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void drawPeople(int pColor);

	void peopleMoving(char c);
	bool isInBoard();
};

