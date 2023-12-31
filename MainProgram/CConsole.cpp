﻿#include "CConsole.h"




void CConsole::setUpConsole()
{
	system("color 80");
	fixConsoleWindow();
	removeScrollBar();
	disableClick();
	showConsoleCursor(false);
	setConsole();
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

void CConsole::setConsole()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int consoleWidth = r.right - r.left + 500;
	int consoleHeight = r.bottom - r.top + 400;
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

int CConsole::getConsoleWid()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right;

}

void CConsole::drawChar(int x, int y, wchar_t c, int color, int backGround, bool isAscii)
{
	if (!isAscii) {
		int old_mode = _setmode(_fileno(stdout), _O_U16TEXT);
		gotoXY(x, y);
		color += backGround * 16;
		setColor(color);
		wcout << c;
		color = Black + backGround * 16;
		setColor(color);
		_setmode(_fileno(stdout), old_mode);
	}
	else {
		gotoXY(x, y);
		color += backGround * 16;
		setColor(color);
		cout << (char)c;
		color = Black + backGround * 16;
		setColor(color);
	}

}
void CConsole::drawString(int x, int y, string s, int color, int backGround)
{
	

		gotoXY(x, y);
		color += backGround * 16;
		setColor(color);
		cout << s;
		color = Black + backGround * 16;
		setColor(color);
	
	
}
void CConsole::setColor(int color)
{
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, color);

}

void CConsole::drawHorLine(int fromX, int toX, int y, wchar_t c, int color, int backColor)
{
	for (int i = fromX; i <= toX; i++) {
		drawChar(i, y, c, color, backColor);
	}
}

void CConsole::drawVerLine(int fromY, int toY, int x, wchar_t c, int color, int backColor)
{
	for (int i = fromY; i <= toY; i++) {
		drawChar(x, i, c, color, backColor);
	}
}

void CConsole::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

char CConsole::getInput()
{
	char input = 0;

	while (true)
	{
		//Sleep(20);

		input = _getch();
		if (input == 0 || input == 224) // Check for special keys
		{
			input = _getch(); // Discard the second character of a special key
		}
		else
		{
			return tolower(input);
		}
	}
}

void CConsole::disableClick()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

void CConsole::HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void CConsole::clearScreen(int color) {
	system("cls");
	COORD topLeft = { 0, 0 };
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(console, &csbi);
	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;


	CConsole::setColor(color);
	CConsole::drawHorLine(0, CConsole::getConsoleWid(), 0, ' ', color, color);
	for (int i = 1; i < CConsole::getConsoleHei(); ++i) {
		CConsole::drawHorLine(0, CConsole::getConsoleWid(), i, ' ', color, color);
	}


	SetConsoleCursorPosition(console, topLeft);
	
}