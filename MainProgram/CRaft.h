#pragma once
#include "CObstacle.h"
class CRaft:public CObstacle
{
public:
	CRaft(int x, int y, string direct, int speed = 1);
	void drawObject(bool isForRemove=false);
};

