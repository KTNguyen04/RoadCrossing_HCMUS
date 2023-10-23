#include "CConsole.h"
CConsole::CConsole()
{

	system("color 80");
	fixConsoleWindow();
	setConsole();
	removeScrollBar();
	disableClick();
	showConsoleCursor(false);

}
void CConsole::setRange()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csbi;
	csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	// Lấy thông tin cửa sổ console hiện tại
	GetConsoleScreenBufferInfoEx(console, &csbi);

	// Thay đổi độ chia (số dòng trên một trang) thành 50
	csbi.dwSize.Y = 50;

	// Đặt lại kích thước buffer theo độ chia mới
	csbi.srWindow.Bottom = csbi.srWindow.Top + csbi.dwSize.Y - 1;

	// Áp dụng thay đổi
	SetConsoleScreenBufferInfoEx(console, &csbi);

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
	int consoleWidth = r.right - r.left + 170;
	int consoleHeight = r.bottom - r.top + 200;
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

void CConsole::drawChar(int x, int y, wchar_t c, int color,int backGround,bool isAscii)
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
void CConsole::setColor(int color)
{
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, color);

}

void CConsole::drawHorLine(int fromX, int toX, int y, wchar_t c, int color, int backColor )
{
	for (int i = fromX; i <= toX; i++) {
		drawChar(i, y , c, color,backColor);
	}
}

void CConsole::drawVerLine(int fromY, int toY, int x, wchar_t c, int color, int backColor )
{
	for (int i = fromY; i <= toY; i++) {
		drawChar(x, i, c, color,backColor);
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
	return tolower(_getch());
}

void CConsole::disableClick()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

