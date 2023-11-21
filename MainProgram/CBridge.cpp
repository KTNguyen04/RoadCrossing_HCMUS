#include "CBridge.h"
#include "CRoad.h"
#include "CGame.h"
CBridge::CBridge(int x, int y)
{
	coorX = x;
	coorY = y;//botleft
	width = bridgeWidth;
	height = bridgeHeight;
	color = bridgeColor;
}

void CBridge::drawObject(bool isForRemove)
{
	int cl = color;
	int fr = coorX;
	int to = coorX + width - 1;
	if (to > CGame::getCoorTopLeftX() + CGame::getWidth()-1) {
		to = CGame::getCoorTopLeftX() + CGame::getWidth()-1;
	}
	if (!isForRemove) {
		cl = riverColor;
		for (int i = 0; i < height; i++) {
			CConsole::drawHorLine(fr, to, coorY/2 - i/2, block, cl, backColor);
		}
	}
}

void CBridge::setWidth(const int& w)
{
	width = w;
}
