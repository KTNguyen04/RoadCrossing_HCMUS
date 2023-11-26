#pragma once
#include "CGame.h"
#include "CRoad.h"
class CMenu 
{
public:
	CMenu() : currentOption(0) {}
    void drawTitle(bool isForRemove, int color);
	void showMenu();
	//void loadgame();
	void options();
	void about();
	void help();
	void exitGame();
	void subMenu();
    void drawStartOption(bool isForRemove, int color,bool isSelected );
    void drawAboutOption(bool isForRemove, int color, bool isSelected);
    void drawOptionsOption(bool isForRemove, int color, bool isSelected);
    void drawExitOption(bool isForRemove, int color, bool isSelected);
	void drawLoadOption(bool isForRemove, int color, bool isSelected);
	void drawHelpOption(bool isForRemove, int color, bool isSelected);
	void drawMute(bool isForRemove, int color, bool isSelected);
	void drawUnmute(bool isForRemove, int color, bool isSelected);
	void drawSubMenu(bool isForRemove, int color);

	void drawNumber0(bool isForRemove, int color, int x);
	void drawNumber1(bool isForRemove, int color,int x);
	void drawNumber2(bool isForRemove, int color, int x);
	void drawNumber3(bool isForRemove, int color, int x);
	void drawNumber4(bool isForRemove, int color, int x);
	void drawNumber5(bool isForRemove, int color, int x);
	void drawNumber6(bool isForRemove, int color, int x);
	void drawNumber7(bool isForRemove, int color, int x);
	void drawNumber8(bool isForRemove, int color, int x);
	void drawNumber9(bool isForRemove, int color, int x);
    void clearScoreBoard(bool isForRemove,int color);

private:
	
	int currentOption;
	int displayMenuOptions();
	int controlOptions();
};
