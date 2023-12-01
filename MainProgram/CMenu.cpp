#include "CMenu.h"
#include "CAudio.h"
#include "CGame.h"

void CMenu::showMenu() {
	CConsole::showConsoleCursor(false);
	CGame* g = new CGame;
	Sleep(1);
	selectedOption = 0;
	CConsole::clearScreen(Blue);
	while (true) {
		drawTitle(false, Red);
		drawStartOption(false, Black, selectedOption == 0);
		drawLoadOption(false, Black, selectedOption == 1);
		drawOptionsOption(false, Black, selectedOption == 2);
		drawAboutOption(false, Black, selectedOption == 3);
		drawHelpOption(false, Black, selectedOption == 4);
		drawExitOption(false, Black, selectedOption == 5);

		userInput = displayMenuOptions();
		Audio::playSound(tapSound);

		if (userInput == 'w') {
			if (selectedOption >= 0)
			{
				drawStartOption(true, Black, selectedOption == 0);  // Clear previous selection
				selectedOption--;
			}
			if (selectedOption < 0)
			{
				selectedOption = 5;
			}
		}
		else if (userInput == 's') {
			if (selectedOption <= 5)
			{
				drawStartOption(true, Black, selectedOption == 5);  // Clear previous selection
				selectedOption++;
			}
			if (selectedOption > 5)
			{
				selectedOption = 0;
			}

		}

		else if (userInput == 13) {  // Enter key
			char c;



			if (selectedOption == 0) {
				CConsole::clearScreen(White);
				subMenu();
				CRoad::setUpRoad();
				CRoad::drawMap();
				g->initGame();
				g->showScore(g->getScore(), 138);
				c = g->startGame();
				if (c == 'r') {
					CConsole::clearScreen(White);
					showMenu();

				}
				else if (c == 'l') {
					string sPath = g->savePopUp();
					if (sPath != "" && sPath != "newgame") {
						g->saveGame(sPath);
					}
					else if (sPath == "") {
						showMenu();
					}

				}
				else if (c == 'n') {
					delete g;
					g = new CGame;
					//CConsole::clearScreen(White);
					CRoad::setUpRoad();
					CRoad::drawMap();
					g->initGame();
					g->showScore(g->getScore(), 138);
					g->showLevel(g->getLevel(), 176);
					g->startGame();
				}

			}
			else if (selectedOption == 1) {

				CConsole::clearScreen(White);
				string path = g->loadPopUp();
				if (path != "") {
					CRoad::setUpRoad();
					CConsole::clearScreen(White);
					CRoad::drawMap();
					subMenu();
					g->initGame();
					g->loadGame(path);
					g->showScore(g->getScore(), 138);
					c = g->startGame();
					if (c == 'r') {
						CConsole::clearScreen(White);
						showMenu();

					}
					//else if (c == 'n') {
					//	//delete g;
					//	CConsole::clearScreen(White);
					//	showMenu();
					//	setUserInput(13);
					//	setOption(0);
					//	subMenu();
					//	delete g;

					//	/*/g->initGame();
					//	c = g->startGame();*/
					//}
					else if (c == 'l') {
						string sPath = g->savePopUp();
						if (sPath != "" && sPath != "newgame") {
							g->saveGame(sPath);
						}
						else if (sPath == "") {
							showMenu();
						}
						/*else {
							CConsole::clearScreen(White);
							showMenu();
							setUserInput(13);
							setOption(0);
							subMenu();
							delete g;


						}*/
					}
					else if (c == 'n') {
						delete g;
						g = new CGame;
						//CConsole::clearScreen(White);
						CRoad::setUpRoad();
						CRoad::drawMap();
						g->initGame();
						g->showScore(g->getScore(), 138);
						g->showLevel(g->getLevel(), 176);
						g->startGame();
					}

				}
				else showMenu();
				break;
			}
			else if (selectedOption == 2)
			{
				CConsole::clearScreen(White);
				options();
				break;
			}
			else if (selectedOption == 3)
			{
				//About option selected
				CConsole::clearScreen(White);
				about();
				break;
			}
			else if (selectedOption == 4)
			{
				//About option selected
				CConsole::clearScreen(White);
				help();
				break;
			}
			else if (selectedOption == 5) {
				CConsole::clearScreen(White);
				delete g;
				exitGame();
				return;

			}
			if (g != NULL)
				delete g;
		}
	}
	

}

int CMenu::displayMenuOptions() {
	int userInput;
	CConsole::gotoXY(70, 16);
	while (true) {
		userInput = CConsole::getInput();

		// Check for arrow key inputs
		if (userInput == 0xE0) {
			userInput = CConsole::getInput();

			if (userInput == 'H') {  // Up arrow key
				return 'w';
			}
			else if (userInput == 'P') {  // Down arrow key
				return 's';
			}
		}
		else if (userInput == 13 || userInput == 'w' || userInput == 's') {
			return userInput;
		}

	}
}

void CMenu::options()
{
	CConsole::clearScreen(White);
	int Color = Red;
	int backColor = White;
	bool isForRemove = false;
	int selectedOption = 0;
	//Draw Tua 
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung*
		CConsole::drawHorLine(x + 2, x + 33, 5, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 5, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 5, botBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x, block, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 35, block, Color, backColor);
		CConsole::drawChar(x, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 35, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 8, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 8, botBlock, Color, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 9, topBlock, Color, backColor);
		//Ve Options
		//Draw O
		CConsole::drawHorLine(x + 3, x + 4, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 3, x + 4, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 2, 7, block, Color, backColor);
		CConsole::drawChar(x + 5, 7, block, Color, backColor);
		CConsole::drawChar(x + 2, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 5, 6, botBlock, Color, backColor);
		//Draw P
		CConsole::drawVerLine(6, 7, x + 7, block, Color, backColor);
		CConsole::drawChar(x + 7, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 8, x + 9, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 8, x + 9, 7, topBlock, Color, backColor);
		CConsole::drawChar(x + 10, 6, botBlock, Color, backColor);
		//Draw T
		CConsole::drawChar(x + 12, 6, topBlock, Color, backColor);
		CConsole::drawChar(x + 14, 6, topBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 13, block, Color, backColor);
		CConsole::drawChar(x + 13, 8, topBlock, Color, backColor);
		//Draw I
		CConsole::drawVerLine(6, 7, x + 16, block, Color, backColor);
		CConsole::drawChar(x + 16, 8, topBlock, Color, backColor);
		//Draw O
		CConsole::drawHorLine(x + 19, x + 20, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 19, x + 20, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 18, 7, block, Color, backColor);
		CConsole::drawChar(x + 21, 7, block, Color, backColor);
		CConsole::drawChar(x + 18, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 21, 6, botBlock, Color, backColor);
		//Draw N
		CConsole::drawVerLine(6, 7, x + 23, block, Color, backColor);
		CConsole::drawChar(x + 23, 8, topBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 27, block, Color, backColor);
		CConsole::drawChar(x + 27, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 24, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 25, 7, topBlock, Color, backColor);
		CConsole::drawChar(x + 26, 7, botBlock, Color, backColor);
		//Ve S
		CConsole::drawHorLine(x + 30, x + 32, 6, topBlock, Color, backColor);
		CConsole::drawChar(x + 29, 6, botBlock, Color, backColor);
		CConsole::drawHorLine(x + 30, x + 31, 7, topBlock, Color, backColor);
		CConsole::drawChar(x + 32, 7, botBlock, Color, backColor);
		CConsole::drawHorLine(x + 29, x + 31, 8, topBlock, Color, backColor);


	}

	CConsole::gotoXY(85, 50);
	cout << "Press R to return to the main menu...";
	Color = Black;
	while (true)
	{

		//Draw Mute
		drawMute(false, Color, selectedOption == 1);
		//Draw UnMute
		drawUnmute(false, Color, selectedOption == 0);
		int userInput = controlOptions();

		if (userInput == 'a' && selectedOption > 0) {
			drawMute(true, Black, selectedOption == 0);  // Clear previous selection
			selectedOption--;
		}
		else if (userInput == 'd' && selectedOption < 1) {
			drawMute(true, Black, selectedOption == 1);  // Clear previous selection
			selectedOption++;
		}
		else if (userInput == 13) {  // Enter key
			if (selectedOption == 1) {

				Audio::playSound2(menuSound, false);

			}
			else if (selectedOption == 0) {

				Audio::playSound2(menuSound);

			}
		}
		else if (userInput == 'r') {
			showMenu();
		}
	}
	cin.ignore();
}

void CMenu::about()
{
	CConsole::clearScreen(White);
	int Color = Red;
	int backColor = White;
	bool isForRemove = false;
	int x = 85;
	//Draw 
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 5, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 5, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 5, botBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x, block, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 35, block, Color, backColor);
		CConsole::drawChar(x, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 35, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 8, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 8, botBlock, Color, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 9, topBlock, Color, backColor);
		//Ve About
 //Draw A       
		CConsole::drawHorLine(x + 7, x + 8, 6, topBlock, Color, backColor);
		CConsole::drawChar(x + 6, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 9, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 6, 7, block, Color, backColor);
		CConsole::drawChar(x + 9, 7, block, Color, backColor);
		CConsole::drawChar(x + 6, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 9, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 7, x + 8, 7, topBlock, Color, backColor);
		//Draw B
		CConsole::drawVerLine(6, 7, x + 11, block, Color, backColor);
		CConsole::drawChar(x + 11, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 7, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 14, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 14, 7, botBlock, Color, backColor);
		//Draw O
		CConsole::drawHorLine(x + 17, x + 18, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 17, x + 18, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 16, 7, block, Color, backColor);
		CConsole::drawChar(x + 19, 7, block, Color, backColor);
		CConsole::drawChar(x + 16, 6, botBlock, Color, backColor);
		CConsole::drawChar(x + 19, 6, botBlock, Color, backColor);
		//Draw U
		CConsole::drawVerLine(6, 7, x + 21, block, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 24, block, Color, backColor);
		CConsole::drawHorLine(x + 22, x + 23, 8, topBlock, Color, backColor);
		//Draw T
		CConsole::drawChar(x + 26, 6, topBlock, Color, backColor);
		CConsole::drawChar(x + 28, 6, topBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 27, block, Color, backColor);
		CConsole::drawChar(x + 27, 8, topBlock, Color, backColor);

		x = x - 5;
		CConsole::gotoXY(x, 12);
		cout << "     DO AN CUOI KI : GAME CROSSING ROAD";
		CConsole::gotoXY(x, 14);
		cout << "     GV HUONG DAN: Thay Truong Toan Thinh";
		CConsole::gotoXY(x + 2, 16);
		cout << "        -------- NHOM 3 --------";
		CConsole::gotoXY(x - 6, 18);
		cout << "- Ho va ten -                                  - MSSV -";
		CConsole::gotoXY(x - 10, 20);
		cout << "Truong Nhat Huy                                    22127168";
		CConsole::gotoXY(x - 10, 22);
		cout << "Do Luong Nhat Minh                                 22127262 ";
		CConsole::gotoXY(x - 10, 24);
		cout << "Nguyen Khanh Toan                                  22127418  ";
		CConsole::gotoXY(x - 10, 26);
		cout << "Nguyen Phuoc Minh Tri                              22127424 ";
		CConsole::gotoXY(x + 2, 30);
		cout << "Press R to return to the main menu...";
		char key = CConsole::getInput();
		if (key == 'r') {
			showMenu();
		}
	}
	cin.ignore();

}
void CMenu::help()
{
	CConsole::clearScreen(White);
	int Color = Red;
	bool isForRemove = false;
	int backColor = White;
	int x = 85;

	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 5, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 5, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 5, botBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x, block, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 35, block, Color, backColor);
		CConsole::drawChar(x, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 35, 8, topBlock, Color, backColor);
		CConsole::drawChar(x + 1, 8, botBlock, Color, backColor);
		CConsole::drawChar(x + 34, 8, botBlock, Color, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 9, topBlock, Color, backColor);
		//Draw H
		CConsole::drawVerLine(6, 7, x + 9, block, Color, backColor);
		CConsole::drawChar(x + 9, 8, topBlock, Color, backColor);
		CConsole::drawVerLine(6, 7, x + 12, block, Color, backColor);
		CConsole::drawChar(x + 12, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 10, x + 11, 7, topBlock, Color, backColor);
		//Draw E
		CConsole::drawVerLine(6, 7, x + 14, block, Color, backColor);
		CConsole::drawChar(x + 14, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 7, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 8, topBlock, Color, backColor);
		//Draw L
		CConsole::drawVerLine(6, 7, x + 18, block, Color, backColor);
		CConsole::drawChar(x + 18, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 19, x + 20, 8, topBlock, Color, backColor);
		//Draw P
		CConsole::drawVerLine(6, 7, x + 22, block, Color, backColor);
		CConsole::drawChar(x + 22, 8, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 6, topBlock, Color, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 7, topBlock, Color, backColor);
		CConsole::drawChar(x + 25, 6, botBlock, Color, backColor);


		x = x - 20;
		CConsole::gotoXY(x, 14);
		cout << "USE W A S D TO MOVE THE PLAYER UP DOWN LEFT AND RIGHT, T TO SAVE GAME";
		CConsole::gotoXY(x, 18);
		cout << "THE VEHICLES WILL MOVE WHEN TRAFFIC LIGHT TURN GREEN AND STOP WHEN TURN RED";
		CConsole::gotoXY(x, 22);
		cout << "KEEP MOVING UNTIL YOU REACH THE MOST BOTTOM LANE";
		CConsole::gotoXY(x, 26);
		cout << "THE SPEED WILL BE HIGHER AFTER EACH ROUND";
		CConsole::gotoXY(x + 15, 30);
		cout << "Press R to return to the main menu...";
		char key = CConsole::getInput();
		if (key == 'r') {
			showMenu();
		}
	}
	cin.ignore();

}
void CMenu::exitGame() {
	int Color = Red;
	bool isForRemove = false;
	int backColor = White;
	CConsole::clearScreen(backColor);
	//Draw Thank You
	if (!isForRemove)
	{
		// Draw T
		CConsole::drawVerLine(15, 19, 33, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 34, block, Color, backColor);
		CConsole::drawHorLine(30, 32, 15, block, Color, backColor);
		CConsole::drawHorLine(35, 37, 15, block, Color, backColor);
		//Draw H
		CConsole::drawVerLine(15, 19, 39, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 40, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 45, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 46, block, Color, backColor);
		CConsole::drawHorLine(41, 44, 17, block, Color, backColor);
		//Draw A
		CConsole::drawVerLine(16, 19, 49, block, Color, backColor);
		CConsole::drawVerLine(16, 19, 50, block, Color, backColor);
		CConsole::drawVerLine(16, 19, 55, block, Color, backColor);
		CConsole::drawVerLine(16, 19, 56, block, Color, backColor);
		CConsole::drawHorLine(51, 54, 15, block, Color, backColor);
		CConsole::drawHorLine(51, 54, 17, block, Color, backColor);
		//Draw N
		CConsole::drawVerLine(15, 19, 58, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 59, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 68, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 69, block, Color, backColor);
		CConsole::drawHorLine(60, 61, 15, block, Color, backColor);
		CConsole::drawHorLine(62, 63, 16, block, Color, backColor);
		CConsole::drawHorLine(64, 65, 17, block, Color, backColor);
		CConsole::drawHorLine(66, 67, 18, block, Color, backColor);
		//Draw H
		CConsole::drawVerLine(15, 19, 71, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 72, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 77, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 78, block, Color, backColor);
		CConsole::drawHorLine(73, 76, 17, block, Color, backColor);
		//Draw Y
		CConsole::drawVerLine(15, 17, 84, block, Color, backColor);
		CConsole::drawVerLine(15, 17, 85, block, Color, backColor);
		CConsole::drawVerLine(15, 17, 88, block, Color, backColor);
		CConsole::drawVerLine(15, 17, 89, block, Color, backColor);
		CConsole::drawVerLine(17, 19, 86, block, Color, backColor);
		CConsole::drawVerLine(17, 19, 87, block, Color, backColor);
		//Draw O
		CConsole::drawHorLine(93, 96, 15, block, Color, backColor);
		CConsole::drawHorLine(93, 96, 19, block, Color, backColor);
		CConsole::drawVerLine(16, 18, 91, block, Color, backColor);
		CConsole::drawVerLine(16, 18, 92, block, Color, backColor);
		CConsole::drawVerLine(16, 18, 97, block, Color, backColor);
		CConsole::drawVerLine(16, 18, 98, block, Color, backColor);
		//Draw U
		CConsole::drawVerLine(15, 19, 100, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 101, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 105, block, Color, backColor);
		CConsole::drawVerLine(15, 19, 106, block, Color, backColor);
		CConsole::drawHorLine(102, 104, 19, block, Color, backColor);
		int Color1 = Color - 3;
		//Draw F
		CConsole::drawVerLine(24, 28, 35, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 36, block, Color1, backColor);
		CConsole::drawHorLine(37, 40, 24, block, Color1, backColor);
		CConsole::drawHorLine(37, 40, 26, block, Color1, backColor);
		//Draw O
		CConsole::drawHorLine(44, 47, 24, block, Color1, backColor);
		CConsole::drawHorLine(44, 47, 28, block, Color1, backColor);
		CConsole::drawVerLine(25, 27, 42, block, Color1, backColor);
		CConsole::drawVerLine(25, 27, 43, block, Color1, backColor);
		CConsole::drawVerLine(25, 27, 48, block, Color1, backColor);
		CConsole::drawVerLine(25, 27, 49, block, Color1, backColor);
		//Draw R
		CConsole::drawVerLine(24, 28, 51, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 52, block, Color1, backColor);
		CConsole::drawHorLine(53, 56, 24, block, Color1, backColor);
		CConsole::drawHorLine(53, 56, 26, block, Color1, backColor);
		CConsole::drawHorLine(55, 56, 27, block, Color1, backColor);
		CConsole::drawHorLine(57, 58, 25, block, Color1, backColor);
		CConsole::drawHorLine(57, 58, 28, block, Color1, backColor);
		//Draw P
		CConsole::drawVerLine(24, 28, 64, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 65, block, Color1, backColor);
		CConsole::drawHorLine(66, 69, 24, block, Color1, backColor);
		CConsole::drawHorLine(66, 69, 26, block, Color1, backColor);
		CConsole::drawHorLine(70, 71, 25, block, Color1, backColor);
		//Draw L
		CConsole::drawVerLine(24, 28, 73, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 74, block, Color1, backColor);
		CConsole::drawHorLine(75, 78, 28, block, Color1, backColor);
		//Draw A
		CConsole::drawVerLine(25, 28, 80, block, Color1, backColor);
		CConsole::drawVerLine(25, 28, 81, block, Color1, backColor);
		CConsole::drawVerLine(25, 28, 86, block, Color1, backColor);
		CConsole::drawVerLine(25, 28, 87, block, Color1, backColor);
		CConsole::drawHorLine(82, 85, 24, block, Color1, backColor);
		CConsole::drawHorLine(82, 85, 26, block, Color1, backColor);
		//Draw Y
		CConsole::drawVerLine(24, 26, 89, block, Color1, backColor);
		CConsole::drawVerLine(24, 26, 90, block, Color1, backColor);
		CConsole::drawVerLine(24, 26, 93, block, Color1, backColor);
		CConsole::drawVerLine(24, 26, 94, block, Color1, backColor);
		CConsole::drawVerLine(26, 28, 91, block, Color1, backColor);
		CConsole::drawVerLine(26, 28, 92, block, Color1, backColor);
		//Draw I
		CConsole::drawVerLine(24, 28, 96, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 97, block, Color1, backColor);
		//Draw N
		CConsole::drawVerLine(24, 28, 99, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 100, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 109, block, Color1, backColor);
		CConsole::drawVerLine(24, 28, 110, block, Color1, backColor);
		CConsole::drawHorLine(101, 102, 24, block, Color1, backColor);
		CConsole::drawHorLine(103, 104, 25, block, Color1, backColor);
		CConsole::drawHorLine(105, 106, 26, block, Color1, backColor);
		CConsole::drawHorLine(107, 108, 27, block, Color1, backColor);
		//Draw G
		CConsole::drawVerLine(25, 27, 112, block, Color1, backColor);
		CConsole::drawVerLine(25, 27, 113, block, Color1, backColor);
		CConsole::drawHorLine(114, 119, 24, block, Color1, backColor);
		CConsole::drawHorLine(116, 119, 26, block, Color1, backColor);
		CConsole::drawHorLine(118, 119, 27, block, Color1, backColor);
		CConsole::drawHorLine(114, 117, 28, block, Color1, backColor);

	}
	// Optionally, you can add any cleanup or save game data logic here.
	// ...
	cin.ignore();
	exit(0);
	// Exit the program
}
void CMenu::subMenu()
{
	drawSubMenu(false, Black);
	drawNumber0(false, Black, Blue, 138);
	drawNumber1(false, Black, Yellow, 171);

}


void CMenu::drawTitle(bool isForRemove, int Color)
{
	int Color1 = Color + 1;
	int backColor = Blue;
	int x = 65;
	if (!isForRemove)
	{
		//Draw C 
		CConsole::drawHorLine(x + 2, x + 5, 0, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 1, block, Color, backColor);
		CConsole::drawChar(x + 6, 1, block, Color, backColor);
		CConsole::drawChar(x + 7, 1, block, Color, backColor);
		CConsole::drawChar(x + 6, 3, block, Color, backColor);
		CConsole::drawChar(x + 7, 3, block, Color, backColor);
		CConsole::drawHorLine(x + 2, x + 5, 4, block, Color, backColor);

		//Draw R
		CConsole::drawHorLine(x + 9, x + 14, 0, block, Color, backColor);
		CConsole::drawVerLine(1, 4, x + 9, block, Color, backColor);
		CConsole::drawVerLine(1, 4, x + 10, block, Color, backColor);
		CConsole::drawHorLine(x + 11, x + 14, 2, block, Color, backColor);
		CConsole::drawHorLine(x + 13, x + 14, 3, block, Color, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 1, block, Color, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 4, block, Color, backColor);
		//Draw O
		CConsole::drawHorLine(x + 20, x + 23, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 20, x + 23, 4, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 18, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 19, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 24, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 25, block, Color, backColor);
		//Draw S   

		CConsole::drawHorLine(x + 29, x + 34, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 27, x + 28, 1, block, Color, backColor);
		CConsole::drawHorLine(x + 29, x + 32, 2, block, Color, backColor);
		CConsole::drawHorLine(x + 33, x + 34, 3, block, Color, backColor);
		CConsole::drawHorLine(x + 27, x + 32, 4, block, Color, backColor);
		//Draw S
		CConsole::drawHorLine(x + 38, x + 43, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 36, x + 37, 1, block, Color, backColor);
		CConsole::drawHorLine(x + 38, x + 41, 2, block, Color, backColor);
		CConsole::drawHorLine(x + 42, x + 43, 3, block, Color, backColor);
		CConsole::drawHorLine(x + 36, x + 41, 4, block, Color, backColor);
		//Draw I
		CConsole::drawHorLine(x + 45, x + 46, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 49, x + 50, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 45, x + 46, 4, block, Color, backColor);
		CConsole::drawHorLine(x + 49, x + 50, 4, block, Color, backColor);
		CConsole::drawVerLine(0, 4, x + 47, block, Color, backColor);
		CConsole::drawVerLine(0, 4, x + 48, block, Color, backColor);

		//Draw N 
		CConsole::drawVerLine(0, 4, x + 52, block, Color, backColor);
		CConsole::drawVerLine(0, 4, x + 53, block, Color, backColor);
		CConsole::drawVerLine(0, 4, x + 62, block, Color, backColor);
		CConsole::drawVerLine(0, 4, x + 63, block, Color, backColor);
		CConsole::drawHorLine(x + 54, x + 55, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 56, x + 57, 1, block, Color, backColor);
		CConsole::drawHorLine(x + 58, x + 59, 2, block, Color, backColor);
		CConsole::drawHorLine(x + 60, x + 61, 3, block, Color, backColor);
		//Draw G
		CConsole::drawVerLine(1, 3, x + 65, block, Color, backColor);
		CConsole::drawVerLine(1, 3, x + 66, block, Color, backColor);
		CConsole::drawHorLine(x + 67, x + 72, 0, block, Color, backColor);
		CConsole::drawHorLine(x + 69, x + 72, 2, block, Color, backColor);
		CConsole::drawHorLine(x + 71, x + 72, 3, block, Color, backColor);
		CConsole::drawHorLine(x + 67, x + 70, 4, block, Color, backColor);

		//Draw G(Blue)
		x = x + 20;
		CConsole::drawVerLine(8, 10, x, block, Color1, backColor);
		CConsole::drawVerLine(8, 10, x + 1, block, Color1, backColor);
		CConsole::drawHorLine(x + 2, x + 7, 7, block, Color1, backColor);
		CConsole::drawHorLine(x + 4, x + 7, 9, block, Color1, backColor);
		CConsole::drawHorLine(x + 6, x + 7, 10, block, Color1, backColor);
		CConsole::drawHorLine(x + 2, x + 5, 11, block, Color1, backColor);
		//Draw A(Blue)
		CConsole::drawHorLine(x + 11, x + 14, 7, block, Color1, backColor);
		CConsole::drawVerLine(8, 11, x + 9, block, Color1, backColor);
		CConsole::drawVerLine(8, 11, x + 10, block, Color1, backColor);
		CConsole::drawVerLine(8, 11, x + 15, block, Color1, backColor);
		CConsole::drawVerLine(8, 11, x + 16, block, Color1, backColor);
		CConsole::drawHorLine(x + 11, x + 14, 9, block, Color1, backColor);
		//Draw M(Blue)
		CConsole::drawVerLine(7, 11, x + 19, block, Color1, backColor);
		CConsole::drawVerLine(7, 11, x + 20, block, Color1, backColor);
		CConsole::drawVerLine(7, 11, x + 27, block, Color1, backColor);
		CConsole::drawVerLine(7, 11, x + 28, block, Color1, backColor);
		CConsole::drawHorLine(x + 21, x + 22, 7, block, Color1, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 8, block, Color1, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 9, block, Color1, backColor);
		CConsole::drawHorLine(x + 25, x + 26, 7, block, Color1, backColor);
		//Draw E(Blue)
		CConsole::drawVerLine(7, 11, x + 30, block, Color1, backColor);
		CConsole::drawVerLine(7, 11, x + 31, block, Color1, backColor);
		CConsole::drawHorLine(x + 32, x + 35, 7, block, Color1, backColor);
		CConsole::drawHorLine(x + 32, x + 35, 9, block, Color1, backColor);
		CConsole::drawHorLine(x + 32, x + 35, 11, block, Color1, backColor);




	}
}
void CMenu::drawStartOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 14, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 14, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 14, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(15, 16, x, block, highlightColor, backColor);
		CConsole::drawVerLine(15, 16, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 17, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 17, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 17, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 17, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 18, topBlock, highlightColor, backColor);
		//Ve Start
		//Ve S
		CConsole::drawHorLine(x + 7, x + 9, 15, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 6, 15, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 7, x + 8, 16, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 9, 16, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 6, x + 8, 17, topBlock, highlightColor, backColor);

		//Ve T
		CConsole::drawChar(x + 11, 15, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 13, 15, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(15, 16, x + 12, block, highlightColor, backColor);
		CConsole::drawChar(x + 12, 17, topBlock, highlightColor, backColor);
		//Draw A       
		CConsole::drawHorLine(x + 16, x + 17, 15, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 15, 15, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 18, 15, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 15, 16, block, highlightColor, backColor);
		CConsole::drawChar(x + 18, 16, block, highlightColor, backColor);
		CConsole::drawChar(x + 15, 17, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 18, 17, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 16, x + 17, 16, topBlock, highlightColor, backColor);
		//Draw R
		CConsole::drawVerLine(15, 16, x + 20, block, highlightColor, backColor);
		CConsole::drawChar(x + 20, 17, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 21, x + 22, 16, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 21, x + 22, 15, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 23, 15, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 23, 16, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 23, 17, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 23, 15, botBlock, highlightColor, backColor);
		//Draw T
		CConsole::drawChar(x + 25, 15, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 27, 15, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(15, 16, x + 26, block, highlightColor, backColor);
		CConsole::drawChar(x + 26, 17, topBlock, highlightColor, backColor);



	}
}
void CMenu::drawLoadOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 21, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 21, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 21, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(22, 23, x, block, highlightColor, backColor);
		CConsole::drawVerLine(22, 23, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 24, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 24, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 24, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 24, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 25, topBlock, highlightColor, backColor);
		//Draw L
		CConsole::drawVerLine(22, 23, x + 8, block, highlightColor, backColor);
		CConsole::drawChar(x + 8, 24, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 9, x + 10, 24, topBlock, highlightColor, backColor);
		//Draw O
		CConsole::drawHorLine(x + 13, x + 14, 22, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 13, x + 14, 24, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 12, 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 15, 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 12, 22, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 15, 22, botBlock, highlightColor, backColor);
		//Draw A
		CConsole::drawHorLine(x + 18, x + 19, 22, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 17, 22, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 20, 22, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 17, 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 20, 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 17, 24, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 20, 24, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 18, x + 19, 23, topBlock, highlightColor, backColor);
		//Draw D
		CConsole::drawVerLine(22, 23, x + 22, block, highlightColor, backColor);
		CConsole::drawChar(x + 22, 24, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 22, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 24, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 25, 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 25, 22, botBlock, highlightColor, backColor);



	}
}
void CMenu::drawOptionsOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung*
		CConsole::drawHorLine(x + 2, x + 33, 28, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 28, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 28, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(29, 30, x, block, highlightColor, backColor);
		CConsole::drawVerLine(29, 30, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 31, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 31, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 31, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 31, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 32, topBlock, highlightColor, backColor);
		//Ve Options
		//Draw O
		CConsole::drawHorLine(x + 3, x + 4, 29, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 3, x + 4, 31, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 2, 30, block, highlightColor, backColor);
		CConsole::drawChar(x + 5, 30, block, highlightColor, backColor);
		CConsole::drawChar(x + 2, 29, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 5, 29, botBlock, highlightColor, backColor);
		//Draw P
		CConsole::drawVerLine(29, 30, x + 7, block, highlightColor, backColor);
		CConsole::drawChar(x + 7, 31, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 8, x + 9, 29, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 8, x + 9, 30, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 10, 29, botBlock, highlightColor, backColor);
		//Draw T
		CConsole::drawChar(x + 12, 29, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 14, 29, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(29, 30, x + 13, block, highlightColor, backColor);
		CConsole::drawChar(x + 13, 31, topBlock, highlightColor, backColor);
		//Draw I
		CConsole::drawVerLine(29, 30, x + 16, block, highlightColor, backColor);
		CConsole::drawChar(x + 16, 31, topBlock, highlightColor, backColor);
		//Draw O
		CConsole::drawHorLine(x + 19, x + 20, 29, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 19, x + 20, 31, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 18, 30, block, highlightColor, backColor);
		CConsole::drawChar(x + 21, 30, block, highlightColor, backColor);
		CConsole::drawChar(x + 18, 29, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 21, 29, botBlock, highlightColor, backColor);
		//Draw N
		CConsole::drawVerLine(29, 30, x + 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 23, 31, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(29, 30, x + 27, block, highlightColor, backColor);
		CConsole::drawChar(x + 27, 31, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 24, 29, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 25, 30, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 26, 30, botBlock, highlightColor, backColor);
		//Ve S
		CConsole::drawHorLine(x + 30, x + 32, 29, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 29, 29, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 30, x + 31, 30, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 32, 30, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 29, x + 31, 31, topBlock, highlightColor, backColor);

	}

}
void CMenu::drawAboutOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 35, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 35, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 35, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(36, 37, x, block, highlightColor, backColor);
		CConsole::drawVerLine(36, 37, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 38, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 38, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 38, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 38, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 39, topBlock, highlightColor, backColor);
		//Ve About
 //Draw A       
		CConsole::drawHorLine(x + 7, x + 8, 36, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 6, 36, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 9, 36, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 6, 37, block, highlightColor, backColor);
		CConsole::drawChar(x + 9, 37, block, highlightColor, backColor);
		CConsole::drawChar(x + 6, 38, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 9, 38, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 7, x + 8, 37, topBlock, highlightColor, backColor);
		//Draw B
		CConsole::drawVerLine(36, 37, x + 11, block, highlightColor, backColor);
		CConsole::drawChar(x + 11, 38, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 36, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 37, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 12, x + 13, 38, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 14, 36, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 14, 37, botBlock, highlightColor, backColor);
		//Draw O
		CConsole::drawHorLine(x + 17, x + 18, 36, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 17, x + 18, 38, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 16, 37, block, highlightColor, backColor);
		CConsole::drawChar(x + 19, 37, block, highlightColor, backColor);
		CConsole::drawChar(x + 16, 36, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 19, 36, botBlock, highlightColor, backColor);
		//Draw U
		CConsole::drawVerLine(36, 37, x + 21, block, highlightColor, backColor);
		CConsole::drawVerLine(36, 37, x + 24, block, highlightColor, backColor);
		CConsole::drawHorLine(x + 22, x + 23, 38, topBlock, highlightColor, backColor);
		//Draw T
		CConsole::drawChar(x + 26, 36, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 28, 36, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(36, 37, x + 27, block, highlightColor, backColor);
		CConsole::drawChar(x + 27, 38, topBlock, highlightColor, backColor);

	}
}
void CMenu::drawHelpOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 42, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 42, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 42, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(43, 44, x, block, highlightColor, backColor);
		CConsole::drawVerLine(43, 44, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 45, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 45, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 45, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 45, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 46, topBlock, highlightColor, backColor);
		//Draw H
		CConsole::drawVerLine(43, 44, x + 9, block, highlightColor, backColor);
		CConsole::drawChar(x + 9, 45, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(43, 44, x + 12, block, highlightColor, backColor);
		CConsole::drawChar(x + 12, 45, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 10, x + 11, 44, topBlock, highlightColor, backColor);
		//Draw E
		CConsole::drawVerLine(43, 44, x + 14, block, highlightColor, backColor);
		CConsole::drawChar(x + 14, 45, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 43, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 44, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 15, x + 16, 45, topBlock, highlightColor, backColor);
		//Draw L
		CConsole::drawVerLine(43, 44, x + 18, block, highlightColor, backColor);
		CConsole::drawChar(x + 18, 45, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 19, x + 20, 45, topBlock, highlightColor, backColor);
		//Draw P
		CConsole::drawVerLine(43, 44, x + 22, block, highlightColor, backColor);
		CConsole::drawChar(x + 22, 45, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 43, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 23, x + 24, 44, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 25, 43, botBlock, highlightColor, backColor);


	}
}
void CMenu::drawExitOption(bool isForRemove, int color, bool isSelected)
{
	int highlightColor = isSelected ? Yellow : color;
	int backColor = Blue;
	int x = 85;
	if (!isForRemove)
	{
		//Ve Khung
		CConsole::drawHorLine(x + 2, x + 33, 49, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 49, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 49, botBlock, highlightColor, backColor);
		CConsole::drawVerLine(50, 51, x, block, highlightColor, backColor);
		CConsole::drawVerLine(50, 51, x + 35, block, highlightColor, backColor);
		CConsole::drawChar(x, 52, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 35, 52, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 1, 52, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 34, 52, botBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 2, x + 33, 53, topBlock, highlightColor, backColor);
		//Draw E
		CConsole::drawVerLine(50, 51, x + 10, block, highlightColor, backColor);
		CConsole::drawChar(x + 10, 52, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 11, x + 12, 50, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 11, x + 12, 51, topBlock, highlightColor, backColor);
		CConsole::drawHorLine(x + 11, x + 12, 52, topBlock, highlightColor, backColor);
		//Draw X
		CConsole::drawChar(x + 14, 50, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 14, 52, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 18, 50, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 18, 52, topBlock, highlightColor, backColor);

		CConsole::drawChar(x + 15, 50, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 15, 51, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 17, 50, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 17, 51, botBlock, highlightColor, backColor);
		CConsole::drawChar(x + 16, 51, topBlock, highlightColor, backColor);
		//Draw I
		CConsole::drawVerLine(50, 51, x + 20, block, highlightColor, backColor);
		CConsole::drawChar(x + 20, 52, topBlock, highlightColor, backColor);
		//Draw T
		CConsole::drawChar(x + 22, 50, topBlock, highlightColor, backColor);
		CConsole::drawChar(x + 24, 50, topBlock, highlightColor, backColor);
		CConsole::drawVerLine(50, 51, x + 23, block, highlightColor, backColor);
		CConsole::drawChar(x + 23, 52, topBlock, highlightColor, backColor);

	}
}
void CMenu::drawMute(bool isForRemove, int color, bool isSelected)
{
	int Color = color;
	int Color1 = isSelected ? color + 9 : Gray;
	int x = 130;
	if (!isForRemove)
	{
		CConsole::drawHorLine(x + 7, x + 8, 28, topBlock, Color, 15);
		CConsole::drawChar(x + 6, 28, botBlock, Color, 15);
		CConsole::drawChar(x + 9, 28, botBlock, Color, 15);
		CConsole::drawVerLine(29, 33, x + 9, block, Color, 15);
		CConsole::drawHorLine(x + 7, x + 8, 34, botBlock, Color, 15);
		CConsole::drawChar(x + 6, 34, topBlock, Color, 15);
		CConsole::drawChar(x + 9, 34, topBlock, Color, 15);
		CConsole::drawChar(x + 5, 29, topBlock, Color, 15);
		CConsole::drawChar(x + 4, 29, botBlock, Color, 15);
		CConsole::drawChar(x + 4, 33, topBlock, Color, 15);
		CConsole::drawChar(x + 5, 33, botBlock, Color, 15);
		CConsole::drawHorLine(x + 1, x + 3, 30, topBlock, Color, 15);
		CConsole::drawHorLine(x + 1, x + 3, 32, botBlock, Color, 15);
		CConsole::drawChar(x, 30, botBlock, Color, 15);
		CConsole::drawChar(x, 31, block, Color, 15);
		CConsole::drawChar(x, 32, topBlock, Color, 15);

		CConsole::drawVerLine(29, 33, x + 8, block, Color1, 15);
		CConsole::drawVerLine(29, 33, x + 7, block, Color1, 15);
		CConsole::drawChar(x + 8, 34, topBlock, Color1, Black);
		CConsole::drawChar(x + 7, 34, topBlock, Color1, Black);
		CConsole::drawVerLine(30, 33, x + 6, block, Color1, 15);
		CConsole::drawChar(x + 6, 29, botBlock, Color1, 15);
		CConsole::drawVerLine(30, 32, x + 5, block, Color1, 15);
		CConsole::drawChar(x + 5, 33, topBlock, Color1, Black);
		CConsole::drawVerLine(31, 32, x + 4, block, Color1, 15);
		CConsole::drawChar(x + 4, 30, botBlock, Color1, 15);
		CConsole::drawHorLine(x + 1, x + 3, 31, block, Color1, 15);
		CConsole::drawHorLine(x + 1, x + 3, 32, topBlock, Color1, Black);
		CConsole::drawChar(x + 1, 30, botBlock, Color1, 15);
		//
		CConsole::drawChar(x, 28, topBlock, Color, 15);
		CConsole::drawChar(x + 1, 28, botBlock, Color, 15);
		CConsole::drawChar(x + 2, 29, topBlock, Color, 15);
		CConsole::drawChar(x + 3, 29, botBlock, Color, 15);
		CConsole::drawChar(x + 4, 30, topBlock, Color, Black);
		CConsole::drawChar(x + 5, 30, botBlock, Color, Color1);
		CConsole::drawChar(x + 6, 31, topBlock, Color, Color1);
		CConsole::drawChar(x + 7, 31, botBlock, Color, Color1);
		CConsole::drawChar(x + 8, 32, topBlock, Color, Color1);//
		CConsole::drawChar(x + 10, 33, topBlock, Color, 15);
		CConsole::drawChar(x + 11, 33, botBlock, Color, 15);
		CConsole::drawChar(x + 12, 34, topBlock, Color, 15);
		CConsole::drawChar(x + 13, 34, botBlock, Color, 15);



	}
	if (!isForRemove)
	{
		Color = Black;
		//Draw word Mute
	   //Draw M
		CConsole::drawVerLine(38, 40, x - 4, block, Color, 15);
		CConsole::drawVerLine(38, 40, x, block, Color, 15);
		CConsole::drawChar(x - 4, 41, topBlock, Color, Black);
		CConsole::drawChar(x, 41, topBlock, Color, Black);
		CConsole::drawChar(x - 3, 38, botBlock, Color, Black);
		CConsole::drawChar(x - 1, 38, botBlock, Color, Black);
		CConsole::drawChar(x - 2, 39, block, Color, 15);
		//Draw U
		CConsole::drawVerLine(38, 40, x + 2, block, Color, 15);
		CConsole::drawVerLine(38, 40, x + 6, block, Color, 15);
		CConsole::drawChar(x + 2, 41, topBlock, Color, 15);
		CConsole::drawChar(x + 6, 41, topBlock, Color, 15);
		CConsole::drawHorLine(x + 3, x + 5, 41, botBlock, Color, 15);
		//Draw T
		CConsole::drawVerLine(38, 41, x + 10, block, Color, 15);
		CConsole::drawHorLine(x + 8, x + 9, 38, topBlock, Color, 15);
		CConsole::drawHorLine(x + 11, x + 12, 38, topBlock, Color, 15);
		//Draw E
		CConsole::drawVerLine(38, 40, x + 14, block, Color, 15);
		CConsole::drawChar(x + 14, 41, block, Color, 15);
		CConsole::drawHorLine(x + 15, x + 17, 38, topBlock, Color, 15);
		CConsole::drawHorLine(x + 15, x + 17, 39, botBlock, Color, 15);
		CConsole::drawHorLine(x + 15, x + 17, 41, botBlock, Color, 15);

	}
}
void CMenu::drawUnmute(bool isForRemove, int color, bool isSelected)
{
	int Color = color;
	int Color1 = isSelected ? color + 9 : Gray;
	int x = 61;
	if (!isForRemove)
	{
		Color = Black;
		CConsole::drawHorLine(x + 6, x + 7, 28, topBlock, Color, 15);
		CConsole::drawChar(x + 5, 28, botBlock, Color, 15);
		CConsole::drawChar(x + 8, 28, botBlock, Color, 15);
		CConsole::drawVerLine(29, 33, x + 8, block, Color, 15);
		CConsole::drawHorLine(x + 6, x + 7, 34, botBlock, Color, 15);
		CConsole::drawChar(x + 5, 34, topBlock, Color, 15);
		CConsole::drawChar(x + 8, 34, topBlock, Color, 15);
		CConsole::drawChar(x + 4, 29, topBlock, Color, 15);
		CConsole::drawChar(x + 3, 29, botBlock, Color, 15);
		CConsole::drawChar(x + 3, 33, topBlock, Color, 15);
		CConsole::drawChar(x + 4, 33, botBlock, Color, 15);
		CConsole::drawHorLine(x, x + 2, 30, topBlock, Color, 15);
		CConsole::drawHorLine(x, x + 2, 32, botBlock, Color, 15);
		CConsole::drawChar(x - 1, 30, botBlock, Color, 15);
		CConsole::drawChar(x - 1, 31, block, Color, 15);
		CConsole::drawChar(x - 1, 32, topBlock, Color, 15);
		//
		CConsole::drawVerLine(29, 33, x + 7, block, Color1, 15);
		CConsole::drawVerLine(29, 33, x + 6, block, Color1, 15);
		CConsole::drawChar(x + 7, 34, topBlock, Color1, Black);
		CConsole::drawChar(x + 6, 34, topBlock, Color1, Black);
		CConsole::drawVerLine(30, 33, x + 5, block, Color1, 15);
		CConsole::drawChar(x + 5, 29, botBlock, Color1, 15);
		CConsole::drawVerLine(30, 32, x + 4, block, Color1, 15);
		CConsole::drawChar(x + 4, 33, topBlock, Color1, Black);
		CConsole::drawVerLine(31, 32, x + 3, block, Color1, 15);
		CConsole::drawChar(x + 3, 30, botBlock, Color1, 15);
		CConsole::drawHorLine(x, x + 2, 31, block, Color1, 15);
		CConsole::drawHorLine(x, x + 2, 32, topBlock, Color1, Black);
		CConsole::drawChar(x, 30, botBlock, Color1, 15);
		//
		CConsole::drawVerLine(31, 32, x + 10, block, Color, 15);
		CConsole::drawVerLine(30, 33, x + 12, block, Color, 15);
		CConsole::drawVerLine(29, 34, x + 14, block, Color, 15);


	}
	//Draw word Unmute
	if (!isForRemove)
	{
		x = x - 10;//34
		Color = Black;
		//Draw U
		CConsole::drawVerLine(38, 40, x, block, Color, 15);
		CConsole::drawVerLine(38, 40, x + 4, block, Color, 15);
		CConsole::drawChar(x, 41, topBlock, Color, 15);
		CConsole::drawChar(x + 4, 41, topBlock, Color, 15);
		CConsole::drawHorLine(x + 1, x + 3, 41, botBlock, Color, 15);
		//Draw N
		CConsole::drawVerLine(38, 40, x + 6, block, Color, 15);
		CConsole::drawVerLine(38, 40, x + 11, block, Color, 15);
		CConsole::drawChar(x + 6, 41, block, Color, 15);
		CConsole::drawChar(x + 11, 41, block, Color, 15);
		CConsole::drawChar(x + 7, 38, botBlock, Color, 15);//
		CConsole::drawChar(x + 8, 39, topBlock, Color, 15);
		CConsole::drawChar(x + 9, 39, botBlock, Color, 15);
		CConsole::drawChar(x + 10, 40, topBlock, Color, 15);
		//Draw M
		CConsole::drawVerLine(38, 40, x + 13, block, Color, 15);
		CConsole::drawVerLine(38, 40, x + 17, block, Color, 15);
		CConsole::drawChar(x + 13, 41, topBlock, Color, Black);
		CConsole::drawChar(x + 17, 41, topBlock, Color, Black);
		CConsole::drawChar(x + 14, 38, botBlock, Color, Black);
		CConsole::drawChar(x + 16, 38, botBlock, Color, Black);
		CConsole::drawChar(x + 15, 39, block, Color, 15);
		//Draw U
		CConsole::drawVerLine(38, 40, x + 19, block, Color, 15);
		CConsole::drawVerLine(38, 40, x + 23, block, Color, 15);
		CConsole::drawChar(x + 19, 41, topBlock, Color, 15);
		CConsole::drawChar(x + 23, 41, topBlock, Color, 15);
		CConsole::drawHorLine(x + 20, x + 22, 41, botBlock, Color, 15);
		//Draw T
		CConsole::drawVerLine(38, 41, x + 27, block, Color, 15);
		CConsole::drawHorLine(x + 25, x + 26, 38, topBlock, Color, 15);
		CConsole::drawHorLine(x + 28, x + 29, 38, topBlock, Color, 15);
		//Draw E
		CConsole::drawVerLine(38, 40, x + 31, block, Color, 15);
		CConsole::drawChar(x + 31, 41, block, Color, 15);
		CConsole::drawHorLine(x + 32, x + 34, 38, topBlock, Color, 15);
		CConsole::drawHorLine(x + 32, x + 34, 39, botBlock, Color, 15);
		CConsole::drawHorLine(x + 32, x + 34, 41, botBlock, Color, 15);
	}
}
int CMenu::controlOptions()
{
	int userInput;
	CConsole::gotoXY(70, 16);
	while (true) {
		userInput = CConsole::getInput();
		if (userInput == 13 || userInput == 'a' || userInput == 'd' || userInput == 'r') {
			return userInput;
		}
	}
}
void CMenu::drawSubMenu(bool isForRemove, int color)
{
	//draw Line
	CConsole::drawVerLine(0, 53, 115, block, color, 15);
	//draw Khung Score
	int Color1 = Blue;//khung color
	CConsole::drawVerLine(1, 13, 122, block, color, 15);
	CConsole::drawVerLine(1, 13, 157, block, color, 15);
	CConsole::drawHorLine(123, 156, 1, topBlock, color, Color1);
	CConsole::drawHorLine(123, 156, 13, botBlock, color, Color1);
	//To mau
	for (int i = 123; i < 157; i++)
	{
		for (int j = 2; j < 13; j++)
		{
			CConsole::drawChar(i, j, block, Color1);
		}

	}
	//Draw SCORE
	if (!isForRemove)
	{
		//draw S
		CConsole::drawHorLine(129, 131, 3, topBlock, color, Color1);
		CConsole::drawChar(128, 3, botBlock, color, Color1);
		CConsole::drawHorLine(129, 130, 4, topBlock, color, Color1);
		CConsole::drawChar(131, 4, botBlock, color, Color1);
		CConsole::drawHorLine(128, 130, 5, topBlock, color, Color1);
		//draw C
		CConsole::drawHorLine(134, 136, 3, topBlock, color, Color1);
		CConsole::drawChar(133, 3, botBlock, color, Color1);
		CConsole::drawChar(133, 4, block, color, Color1);
		CConsole::drawHorLine(134, 136, 5, topBlock, color, Color1);
		//draw O
		CConsole::drawHorLine(139, 140, 3, topBlock, color, Color1);
		CConsole::drawHorLine(139, 140, 5, topBlock, color, Color1);
		CConsole::drawChar(138, 4, block, color, Color1);
		CConsole::drawChar(141, 4, block, color, Color1);
		CConsole::drawChar(138, 3, botBlock, color, Color1);
		CConsole::drawChar(141, 3, botBlock, color, Color1);
		//draw R
		CConsole::drawVerLine(3, 4, 143, block, color, Color1);
		CConsole::drawChar(143, 5, topBlock, color, Color1);
		CConsole::drawHorLine(144, 145, 4, topBlock, color, Color1);
		CConsole::drawHorLine(144, 145, 3, topBlock, color, Color1);
		CConsole::drawHorLine(146, 3, botBlock, color, Color1);
		CConsole::drawChar(146, 4, botBlock, color, Color1);
		CConsole::drawChar(146, 5, topBlock, color, Color1);
		CConsole::drawChar(146, 3, botBlock, color, Color1);
		//draw E
		CConsole::drawVerLine(3, 4, 148, block, color, Color1);
		CConsole::drawChar(148, 5, topBlock, color, Color1);
		CConsole::drawHorLine(149, 150, 3, topBlock, color, Color1);
		CConsole::drawHorLine(149, 150, 4, topBlock, color, Color1);
		CConsole::drawHorLine(149, 150, 5, topBlock, color, Color1);
	}
	//Draw Khung Level
	int Color3 = Yellow;//khung color
	CConsole::drawVerLine(1, 13, 160, block, color, 15);
	CConsole::drawVerLine(1, 13, 186, block, color, 15);
	CConsole::drawHorLine(161, 185, 1, topBlock, color, Color3);
	CConsole::drawHorLine(161, 185, 13, botBlock, color, Color3);
	//To mau
	for (int i = 161; i < 186; i++)
	{
		for (int j = 2; j < 13; j++)
		{
			CConsole::drawChar(i, j, block, Color3);
		}

	}
	//Draw LEVEL
	if (!isForRemove)
	{
		//draw L
		CConsole::drawVerLine(3, 4, 163, block, color, Color3);
		CConsole::drawChar(163, 5, topBlock, color, Color3);
		CConsole::drawHorLine(164, 165, 5, topBlock, color, Color3);
		//draw E
		CConsole::drawVerLine(3, 4, 167, block, color, Color3);
		CConsole::drawChar(167, 5, topBlock, color, Color3);
		CConsole::drawHorLine(168, 169, 3, topBlock, color, Color3);
		CConsole::drawHorLine(168, 169, 4, topBlock, color, Color3);
		CConsole::drawHorLine(168, 169, 5, topBlock, color, Color3);
		//Draw V
		CConsole::drawChar(171, 3, block, color, Color3);
		CConsole::drawChar(175, 3, block, color, Color3);
		CConsole::drawChar(171, 4, topBlock, color, Color3);
		CConsole::drawChar(175, 4, topBlock, color, Color3);
		CConsole::drawChar(172, 4, botBlock, color, Color3);
		CConsole::drawChar(173, 5, topBlock, color, Color3);
		CConsole::drawChar(174, 4, botBlock, color, Color3);
		//draw E
		CConsole::drawVerLine(3, 4, 177, block, color, Color3);
		CConsole::drawChar(177, 5, topBlock, color, Color3);
		CConsole::drawHorLine(178, 179, 3, topBlock, color, Color3);
		CConsole::drawHorLine(178, 179, 4, topBlock, color, Color3);
		CConsole::drawHorLine(178, 179, 5, topBlock, color, Color3);
		//draw L
		CConsole::drawVerLine(3, 4, 181, block, color, Color3);
		CConsole::drawChar(181, 5, topBlock, color, Color3);
		CConsole::drawHorLine(182, 183, 5, topBlock, color, Color3);
	}
	//Draw Khung Huong Dan
	int Color2 = Green;
	CConsole::drawVerLine(20, 50, 122, block, color, 15);
	CConsole::drawVerLine(20, 50, 157, block, color, 15);
	CConsole::drawHorLine(123, 156, 20, topBlock, color, Color2);
	CConsole::drawHorLine(123, 156, 50, botBlock, color, Color2);
	//To mau
	for (int i = 123; i < 157; i++)
	{
		for (int j = 21; j < 50; j++)
		{
			CConsole::drawChar(i, j, block, Color2);
		}

	}
	//Draw R: EXIT
	if (!isForRemove)
	{
		//draw R
		CConsole::drawVerLine(22, 23, 124, block, color, Color2);
		CConsole::drawChar(124, 24, topBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 23, topBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 22, topBlock, color, Color2);
		CConsole::drawHorLine(127, 22, botBlock, color, Color2);
		CConsole::drawChar(127, 23, botBlock, color, Color2);
		CConsole::drawChar(127, 24, topBlock, color, Color2);
		CConsole::drawChar(127, 22, botBlock, color, Color2);
		//draw :
		CConsole::drawChar(129, 23, topBlock, color, Color2);
		CConsole::drawChar(129, 24, topBlock, color, Color2);
		//draw E
		CConsole::drawVerLine(22, 23, 132, block, color, Color2);
		CConsole::drawChar(132, 24, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 22, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 23, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 24, topBlock, color, Color2);
		//Draw X
		CConsole::drawChar(136, 22, topBlock, color, Color2);
		CConsole::drawChar(136, 24, topBlock, color, Color2);
		CConsole::drawChar(140, 22, topBlock, color, Color2);
		CConsole::drawChar(140, 24, topBlock, color, Color2);
		CConsole::drawChar(137, 22, botBlock, color, Color2);
		CConsole::drawChar(137, 23, botBlock, color, Color2);
		CConsole::drawChar(139, 22, botBlock, color, Color2);
		CConsole::drawChar(139, 23, botBlock, color, Color2);
		CConsole::drawChar(138, 23, topBlock, color, Color2);
		//Draw I
		CConsole::drawVerLine(22, 23, 142, block, color, Color2);
		CConsole::drawChar(142, 24, topBlock, color, Color2);
		//Draw T
		CConsole::drawChar(144, 22, topBlock, color, Color2);
		CConsole::drawChar(146, 22, topBlock, color, Color2);
		CConsole::drawVerLine(22, 23, 145, block, color, Color2);
		CConsole::drawChar(145, 24, topBlock, color, Color2);
	}
	//Draw L: SAVE
	if (!isForRemove)
	{


		//draw L
		CConsole::drawVerLine(26, 27, 124, block, color, Color2);
		CConsole::drawChar(124, 28, topBlock, color, Color2);
		CConsole::drawHorLine(124, 126, 28, topBlock, color, Color2);
		//draw :
		CConsole::drawChar(128, 27, topBlock, color, Color2);
		CConsole::drawChar(128, 28, topBlock, color, Color2);
		//draw S
		CConsole::drawHorLine(132, 134, 26, topBlock, color, Color2);
		CConsole::drawChar(131, 26, botBlock, color, Color2);
		CConsole::drawHorLine(132, 133, 27, topBlock, color, Color2);
		CConsole::drawChar(134, 27, botBlock, color, Color2);
		CConsole::drawHorLine(131, 133, 28, topBlock, color, Color2);
		//Draw A       
		CConsole::drawHorLine(137, 138, 26, topBlock, color, Color2);
		CConsole::drawChar(136, 26, botBlock, color, Color2);
		CConsole::drawChar(139, 26, botBlock, color, Color2);
		CConsole::drawChar(136, 27, block, color, Color2);
		CConsole::drawChar(139, 27, block, color, Color2);
		CConsole::drawChar(136, 28, topBlock, color, Color2);
		CConsole::drawChar(139, 28, topBlock, color, Color2);
		CConsole::drawHorLine(137, 138, 27, topBlock, color, Color2);
		//Draw V
		CConsole::drawChar(141, 26, block, color, Color2);
		CConsole::drawChar(145, 26, block, color, Color2);
		CConsole::drawChar(141, 27, topBlock, color, Color2);
		CConsole::drawChar(145, 27, topBlock, color, Color2);
		CConsole::drawChar(142, 27, botBlock, color, Color2);
		CConsole::drawChar(143, 28, topBlock, color, Color2);
		CConsole::drawChar(144, 27, botBlock, color, Color2);
		//draw E
		CConsole::drawVerLine(26, 27, 147, block, color, Color2);
		CConsole::drawChar(147, 28, topBlock, color, Color2);
		CConsole::drawHorLine(148, 149, 26, topBlock, color, Color2);
		CConsole::drawHorLine(148, 149, 27, topBlock, color, Color2);
		CConsole::drawHorLine(148, 149, 28, topBlock, color, Color2);
	}
	//Draw T: LOAD
	if (!isForRemove)
	{
		//Draw T
		CConsole::drawChar(124, 30, topBlock, color, Color2);
		CConsole::drawChar(126, 30, topBlock, color, Color2);
		CConsole::drawVerLine(30, 31, 125, block, color, Color2);
		CConsole::drawChar(125, 32, topBlock, color, Color2);
		//draw :
		CConsole::drawChar(128, 31, topBlock, color, Color2);
		CConsole::drawChar(128, 32, topBlock, color, Color2);
		//draw L
		CConsole::drawVerLine(30, 31, 131, block, color, Color2);
		CConsole::drawChar(131, 32, topBlock, color, Color2);
		CConsole::drawHorLine(131, 133, 32, topBlock, color, Color2);
		//draw O
		CConsole::drawHorLine(136, 137, 30, topBlock, color, Color2);
		CConsole::drawHorLine(136, 137, 32, topBlock, color, Color2);
		CConsole::drawChar(135, 31, block, color, Color2);
		CConsole::drawChar(138, 31, block, color, Color2);
		CConsole::drawChar(135, 30, botBlock, color, Color2);
		CConsole::drawChar(138, 30, botBlock, color, Color2);
		//Draw A       
		CConsole::drawHorLine(141, 142, 30, topBlock, color, Color2);
		CConsole::drawChar(140, 30, botBlock, color, Color2);
		CConsole::drawChar(143, 30, botBlock, color, Color2);
		CConsole::drawChar(140, 31, block, color, Color2);
		CConsole::drawChar(143, 31, block, color, Color2);
		CConsole::drawChar(140, 32, topBlock, color, Color2);
		CConsole::drawChar(143, 32, topBlock, color, Color2);
		CConsole::drawHorLine(141, 142, 31, topBlock, color, Color2);
		//draw D
		CConsole::drawVerLine(30, 31, 145, block, color, Color2);
		CConsole::drawChar(145, 32, topBlock, color, Color2);
		CConsole::drawHorLine(146, 147, 30, topBlock, color, Color2);
		CConsole::drawHorLine(146, 147, 32, topBlock, color, Color2);
		CConsole::drawChar(148, 31, block, color, Color2);
		CConsole::drawChar(148, 30, botBlock, color, Color2);
	}
	//draw W: UP
	if (!isForRemove)
	{
		//Draw W
		CConsole::drawVerLine(34, 35, 124, block, color, Color2);
		CConsole::drawVerLine(34, 35, 128, block, color, Color2);
		CConsole::drawChar(125, 36, topBlock, color, Color2);
		CConsole::drawChar(127, 36, topBlock, color, Color2);
		CConsole::drawChar(126, 35, botBlock, color, Color2);
		//draw :
		CConsole::drawChar(130, 35, topBlock, color, Color2);
		CConsole::drawChar(130, 36, topBlock, color, Color2);
		//draw U
		CConsole::drawVerLine(34, 35, 133, block, color, Color2);
		CConsole::drawVerLine(34, 35, 136, block, color, Color2);
		CConsole::drawHorLine(134, 135, 36, topBlock, color, Color2);
		//draw P
		CConsole::drawVerLine(34, 35, 138, block, color, Color2);
		CConsole::drawChar(138, 36, topBlock, color, Color2);
		CConsole::drawHorLine(139, 140, 34, topBlock, color, Color2);
		CConsole::drawHorLine(139, 140, 35, topBlock, color, Color2);
		CConsole::drawChar(141, 34, botBlock, color, Color2);
	}
	//draw S: DOWN
	if (!isForRemove)
	{
		//draw S
		CConsole::drawHorLine(125, 127, 38, topBlock, color, Color2);
		CConsole::drawChar(124, 38, botBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 39, topBlock, color, Color2);
		CConsole::drawChar(127, 39, botBlock, color, Color2);
		CConsole::drawHorLine(124, 126, 40, topBlock, color, Color2);
		//draw :
		CConsole::drawChar(129, 39, topBlock, color, Color2);
		CConsole::drawChar(129, 40, topBlock, color, Color2);
		//draw D
		CConsole::drawVerLine(38, 39, 132, block, color, Color2);
		CConsole::drawChar(132, 40, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 38, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 40, topBlock, color, Color2);
		CConsole::drawChar(135, 39, block, color, Color2);
		CConsole::drawChar(135, 38, botBlock, color, Color2);
		//draw O
		CConsole::drawHorLine(138, 139, 38, topBlock, color, Color2);
		CConsole::drawHorLine(138, 139, 40, topBlock, color, Color2);
		CConsole::drawChar(137, 39, block, color, Color2);
		CConsole::drawChar(140, 39, block, color, Color2);
		CConsole::drawChar(137, 38, botBlock, color, Color2);
		CConsole::drawChar(140, 38, botBlock, color, Color2);
		//draw W
		CConsole::drawVerLine(38, 39, 142, block, color, Color2);
		CConsole::drawVerLine(38, 39, 146, block, color, Color2);
		CConsole::drawChar(143, 40, topBlock, color, Color2);
		CConsole::drawChar(145, 40, topBlock, color, Color2);
		CConsole::drawChar(144, 39, botBlock, color, Color2);
		//draw N
		CConsole::drawVerLine(38, 39, 148, block, color, Color2);
		CConsole::drawChar(148, 40, topBlock, color, Color2);
		CConsole::drawVerLine(38, 39, 152, block, color, Color2);
		CConsole::drawChar(152, 40, topBlock, color, Color2);
		CConsole::drawChar(149, 38, botBlock, color, Color2);
		CConsole::drawChar(150, 39, topBlock, color, Color2);
		CConsole::drawChar(151, 39, botBlock, color, Color2);
	}
	//draw A: LEFT
	if (!isForRemove)
	{
		//draw A
		CConsole::drawHorLine(125, 126, 42, topBlock, color, Color2);
		CConsole::drawChar(124, 42, botBlock, color, Color2);
		CConsole::drawChar(127, 42, botBlock, color, Color2);
		CConsole::drawChar(124, 43, block, color, Color2);
		CConsole::drawChar(127, 43, block, color, Color2);
		CConsole::drawChar(124, 44, topBlock, color, Color2);
		CConsole::drawChar(127, 44, topBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 43, topBlock, color, Color2);
		//draw :
		CConsole::drawChar(129, 43, topBlock, color, Color2);
		CConsole::drawChar(129, 44, topBlock, color, Color2);
		//draw L
		CConsole::drawVerLine(42, 43, 132, block, color, Color2);
		CConsole::drawChar(132, 44, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 44, topBlock, color, Color2);
		//draw E
		CConsole::drawVerLine(42, 43, 136, block, color, Color2);
		CConsole::drawChar(136, 44, topBlock, color, Color2);
		CConsole::drawHorLine(137, 138, 42, topBlock, color, Color2);
		CConsole::drawHorLine(137, 138, 43, topBlock, color, Color2);
		CConsole::drawHorLine(137, 138, 44, topBlock, color, Color2);
		//draw F
		CConsole::drawVerLine(42, 43, 140, block, color, Color2);
		CConsole::drawChar(140, 44, topBlock, color, Color2);
		CConsole::drawHorLine(141, 142, 42, topBlock, color, Color2);
		CConsole::drawHorLine(141, 142, 43, topBlock, color, Color2);
		//draw T
		CConsole::drawChar(144, 42, topBlock, color, Color2);
		CConsole::drawChar(146, 42, topBlock, color, Color2);
		CConsole::drawVerLine(42, 43, 145, block, color, Color2);
		CConsole::drawChar(145, 44, topBlock, color, Color2);
	}
	//Draw D: RIGHT
	if (!isForRemove)
	{
		//draw D
		CConsole::drawVerLine(46, 47, 124, block, color, Color2);
		CConsole::drawChar(124, 48, topBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 46, topBlock, color, Color2);
		CConsole::drawHorLine(125, 126, 48, topBlock, color, Color2);
		CConsole::drawChar(127, 47, block, color, Color2);
		CConsole::drawChar(127, 46, botBlock, color, Color2);
		//draw :
		CConsole::drawChar(129, 47, topBlock, color, Color2);
		CConsole::drawChar(129, 48, topBlock, color, Color2);
		//draw R
		CConsole::drawVerLine(46, 47, 132, block, color, Color2);
		CConsole::drawChar(132, 48, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 47, topBlock, color, Color2);
		CConsole::drawHorLine(133, 134, 46, topBlock, color, Color2);
		CConsole::drawHorLine(135, 46, botBlock, color, Color2);
		CConsole::drawChar(135, 47, botBlock, color, Color2);
		CConsole::drawChar(135, 48, topBlock, color, Color2);
		CConsole::drawChar(135, 46, botBlock, color, Color2);
		//draw I
		CConsole::drawVerLine(46, 47, 137, block, color, Color2);
		CConsole::drawChar(137, 48, topBlock, color, Color2);
		//draw G
		CConsole::drawHorLine(140, 142, 46, topBlock, color, Color2);
		CConsole::drawHorLine(140, 141, 48, topBlock, color, Color2);
		CConsole::drawChar(139, 46, botBlock, color, Color2);
		CConsole::drawChar(139, 47, block, color, Color2);
		CConsole::drawChar(142, 47, block, color, Color2);
		CConsole::drawChar(141, 47, topBlock, color, Color2);
		//draw H
		CConsole::drawVerLine(46, 47, 144, block, color, Color2);
		CConsole::drawChar(144, 48, topBlock, color, Color2);
		CConsole::drawChar(145, 47, topBlock, color, Color2);
		CConsole::drawVerLine(46, 47, 146, block, color, Color2);
		CConsole::drawChar(146, 48, topBlock, color, Color2);
		//draw T
		CConsole::drawChar(148, 46, topBlock, color, Color2);
		CConsole::drawChar(150, 46, topBlock, color, Color2);
		CConsole::drawVerLine(46, 47, 149, block, color, Color2);
		CConsole::drawChar(149, 48, topBlock, color, Color2);
	}
}
void CMenu::drawNumber0(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawHorLine(x + 1, x + 2, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 10, topBlock, color, Color1);
		CConsole::drawVerLine(8, 9, x, block, color, Color1);
		CConsole::drawChar(x, 7, botBlock, color, Color1);
		CConsole::drawVerLine(8, 9, x + 3, block, color, Color1);
		CConsole::drawChar(x + 3, 7, botBlock, color, Color1);
	}
}
void CMenu::drawNumber1(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawChar(x, 7, botBlock, color, Color1);
		CConsole::drawHorLine(x, x + 2, 10, topBlock, color, Color1);
		CConsole::drawVerLine(7, 9, x + 1, block, color, Color1);
	}
}
void CMenu::drawNumber2(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawChar(x, 7, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 7, botBlock, color, Color1);
		CConsole::drawChar(x, 9, botBlock, color, Color1);
		CConsole::drawChar(x + 1, 9, topBlock, color, Color1);
		CConsole::drawChar(x + 2, 8, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 8, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x, x + 3, 10, topBlock, color, Color1);
	}
}
void CMenu::drawNumber3(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawChar(x, 7, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 7, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 8, topBlock, color, Color1);
		CConsole::drawChar(x, 9, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 9, block, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 10, topBlock, color, Color1);

	}
}
void CMenu::drawNumber4(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawVerLine(7, 8, x, block, color, Color1);
		CConsole::drawVerLine(7, 9, x + 3, block, color, Color1);
		CConsole::drawChar(x + 3, 10, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
	}
}
void CMenu::drawNumber5(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawVerLine(7, 8, x, block, color, Color1);
		CConsole::drawHorLine(x + 1, x + 3, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
		CConsole::drawHorLine(x, x + 3, 10, topBlock, color, Color1);
		CConsole::drawChar(x + 3, 8, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 9, block, color, Color1);
	}
}
void CMenu::drawNumber6(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawVerLine(7, 9, x, block, color, Color1);
		CConsole::drawChar(x + 3, 8, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 9, block, color, Color1);
		CConsole::drawHorLine(x + 1, x + 3, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
		CConsole::drawHorLine(x, x + 3, 10, topBlock, color, Color1);
	}
}
void CMenu::drawNumber7(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawHorLine(x, x + 3, 7, topBlock, color, Color1);
		CConsole::drawChar(x, 7, botBlock, color, color);
		CConsole::drawChar(x + 3, 7, botBlock, color, color);
		CConsole::drawChar(x + 3, 8, topBlock, color, Color1);
		CConsole::drawChar(x + 2, 8, botBlock, color, Color1);
		CConsole::drawChar(x + 2, 9, topBlock, color, Color1);
		CConsole::drawChar(x + 1, 9, botBlock, color, Color1);
		CConsole::drawChar(x + 1, 10, topBlock, color, Color1);

	}
}
void CMenu::drawNumber8(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawHorLine(x + 1, x + 2, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 10, topBlock, color, Color1);
		CConsole::drawChar(x, 7, botBlock, color, Color1);
		CConsole::drawChar(x + 3, 7, botBlock, color, Color1);
		CConsole::drawChar(x, 8, topBlock, color, Color1);
		CConsole::drawChar(x + 3, 8, topBlock, color, Color1);
		CConsole::drawChar(x, 9, block, color, Color1);
		CConsole::drawChar(x + 3, 9, block, color, Color1);
	}
}
void CMenu::drawNumber9(bool isForRemove, int color, int backColor, int x)
{
	int Color1 = backColor;
	if (!isForRemove)
	{
		CConsole::drawVerLine(7, 8, x, block, color, Color1);
		CConsole::drawVerLine(7, 9, x + 3, block, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 7, topBlock, color, Color1);
		CConsole::drawHorLine(x + 1, x + 2, 8, botBlock, color, Color1);
		CConsole::drawHorLine(x, x + 3, 10, topBlock, color, Color1);
	}
}

void CMenu::clearScoreBoard(bool isForRemove, int color)
{
	int Color1 = color;
	for (int i = 123; i < 157; i++)
	{
		for (int j = 7; j < 13; j++)
		{
			CConsole::drawChar(i, j, block, color);
		}

	}


}
void CMenu::clearLevelBoard(bool isForRemove, int color)
{
	int Color1 = color;
	for (int i = 161; i < 186; i++)
	{
		for (int j = 7; j < 13; j++)
		{
			CConsole::drawChar(i, j, block, color);
		}

	}
}
void CMenu::setOption(const int& c)
{
	selectedOption = c;
}

void CMenu::setUserInput(const int& c)
{
	userInput = c;
}

