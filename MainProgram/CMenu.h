#pragma once
#include "CGame.h"
#include "CRoad.h"
class CMenu 
{
public:
	CMenu() : currentOption(0) {}
    void drawTitle(bool isForRemove, int color);
	void showMenu();
	void start();
	void loadgame();
	void options();
	void about();
	void help();
	void exitGame();
    void drawStartOption(bool isForRemove, int color,bool isSelected );
    void drawAboutOption(bool isForRemove, int color, bool isSelected);
    void drawOptionsOption(bool isForRemove, int color, bool isSelected);
    void drawExitOption(bool isForRemove, int color, bool isSelected);
	void drawLoadOption(bool isForRemove, int color, bool isSelected);
	void drawHelpOption(bool isForRemove, int color, bool isSelected);
	void drawMute(bool isForRemove, int color, bool isSelected);
	void drawUnmute(bool isForRemove, int color, bool isSelected);
private:
	
	int currentOption;
	int displayMenuOptions();
	int controlOptions();
};

