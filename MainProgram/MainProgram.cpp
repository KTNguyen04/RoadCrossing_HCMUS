#include <iostream>
#include "CConsole.h"
#include "CGame.h"
#include "CPeople.h"
#include "CMenu.h"
#include "CAudio.h"
#include<mutex>
#include <future>

using namespace std;
int main()
{
	srand(time(NULL));
	int choice = 0;
	CConsole c;
	CConsole::setUpConsole();
	CRoad::setUpRoad();

	Sleep(100);
	CMenu m;
	while (1) {
		m.showMenu();
		m.run();
	}


}


