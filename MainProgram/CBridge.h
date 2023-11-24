#pragma once
#include "CConsole.h"
#include "CObstacle.h"

class CBridge:public CObstacle
{
	int color;
public:
	CBridge() ;
	CBridge(int x, int y);
	void drawObject(bool isForRemove=false);
	void setWidth(const int & w);
};

