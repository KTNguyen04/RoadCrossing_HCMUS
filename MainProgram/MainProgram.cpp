

#include <iostream>

using namespace std;
#include "CConsole.h"

int main()
{
	CConsole c;
	cout << CConsole::getConsoleHei() << CConsole::getConsoleWid();
	CConsole::drawChar(1, 2, 254, Blue);
	//cout << "hello";
	system("pause>0");
	cout << FOREGROUND_RED;

}


