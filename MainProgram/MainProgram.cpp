#include <iostream>

using namespace std;
#include "CConsole.h"
#include "CGame.h"
#include "CPeople.h"
#include "CAudio.h"
int main()
{
	system("pause");
	srand(time(NULL));
	CConsole c;

	CGame g;
	g.runGame();
	system("pause");
	
	

}


