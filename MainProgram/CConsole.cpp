#include "CConsole.h"
CConsole::CConsole()
{
	system("color F0");
	fixConsoleWindow();
	removeScrollBar();
	moveConsole();

}
void CConsole::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void CConsole::removeScrollBar()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;
	SetConsoleScreenBufferSize(hOut, newSize);
}

void CConsole::moveConsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int consoleWidth = r.right - r.left;
	int consoleHeight = r.bottom - r.top;
	MoveWindow(console, (screenWidth - consoleWidth) / 2, (screenHeight - consoleHeight) / 2, consoleWidth, consoleHeight, TRUE);
}

void CConsole::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int CConsole::getConsoleHei()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Bottom;

}

void CConsole::drawChar(int x, int y, char c, int color)
{
	gotoXY(x, y);
	color += 15 * 16;
	setColor(color);
	cout << c;
	color = Black + 15 * 16;
	setColor(color);

}

void CConsole::setColor(int color)
{
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, color);
}

int CConsole::getConsoleWid()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right;

}

