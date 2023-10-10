#pragma once
#include "CConsole.h"
#include "CGame.h"
class CPeople
{
	int coorX, coorY;
	int height, width;
public:
	CPeople();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void drawPeople();

};

