﻿#pragma once
#include "CGame.h"
#include "CRoad.h"
class CMenu : public CConsole
{
public:
	CMenu() : currentOption(0) {}
    void drawTitle(bool isForRemove = false);
	void showMenu();
	void start();
	void exitGame();
    void drawMenuOption(bool isForRemove, int color,bool isSelected );
    void drawAboutOption(bool isForRemove, int color, bool isSelected);
    void drawOptionsOption(bool isForRemove, int color, bool isSelected);
    void drawExitOption(bool isForRemove, int color, bool isSelected);
private:
	std::vector<std::string> options;
	int currentOption;
	int displayMenuOptions();
};

