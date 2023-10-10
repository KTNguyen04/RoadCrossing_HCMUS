#pragma once
#include "CConsole.h"
#include "CPeople.h"

#define ThangDung 179
#define Ngang 196
#define Vuong 254
class CGame
{
	static int coorTopLeftX, coorTopLeftY;
	static int frameWidth, frameHeight;
public:
	CGame();
	void drawBackGround();
	static int getWidth();
	static int getHeight();
	static int getCoorTopLeftX();
	static int getCoorTopLeftY();
};

