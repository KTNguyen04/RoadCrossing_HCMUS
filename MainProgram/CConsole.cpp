#include "CConsole.h"
void CConsole::setConsole()
{
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
