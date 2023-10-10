#pragma once
#include <Windows.h>
#include <windows.h>
#include <winuser.h>
#include<iostream>
using namespace std;
enum {
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkPink,
	DarkYellow,
	DarkWhite,
	Grey,
	Blue,
	Green,
	Cyan,
	Red,
	Pink,
	Yellow,
	White,
};
class CConsole
{
public:
	CConsole();
	//~CConsole();
	static void fixConsoleWindow();
	static void removeScrollBar();
	static void moveConsole();
	static void gotoXY(int x, int y);
	static int getConsoleWid();
	static int getConsoleHei();
	static void drawChar(int x, int y, char c, int color);
	static void setColor(int color);
};

// colors are 0 = black 1 = blue 2 = green and so on to 15 = white
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236


