#pragma once
#include <Windows.h>
#include <windows.h>
#include <winuser.h>
#include <io.h>
#include <fcntl.h>
#include<iostream>
#include <conio.h>
using namespace std;
enum {
	Black,        //0
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkPink,
	DarkYellow,
	DarkWhite,
	Gray,
	Blue,
	Green,
	Cyan,
	Red,
	Pink,
	Yellow,
	White,		//15
};

const int background = Gray;
class CConsole
{
public:
	CConsole();
	//~CConsole();
	
	static void fixConsoleWindow();
	static void removeScrollBar();
	static void setConsole();
	static void gotoXY(int x, int y);
	static int getConsoleWid();
	static int getConsoleHei();
	static void drawChar(int x, int y, wchar_t c, int color, int backGround=background,bool isAscii = false);
	static void setColor(int color);
	static void drawHorLine(int fromX, int toX, int y, wchar_t c, int color,int backColor=15);         //kẻ ngang
	static void drawVerLine(int fromY, int toY, int x, wchar_t c, int color,int backColor=15);
	static void showConsoleCursor(bool showFlag);
	static char getInput();
	static void HideCursor();
	static void disableClick();
	static void clearScreen(int color);
	
};
// colors are 0 = black 1 = blue 2 = green and so on to 15 = white
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236


