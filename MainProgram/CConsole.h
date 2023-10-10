#pragma once
#include <Windows.h>
#include <winuser.h>
class CConsole
{
public:
	static void setConsole();
	static void fixConsoleWindow();
	static void removeScrollBar();
	static void moveConsole();
};

