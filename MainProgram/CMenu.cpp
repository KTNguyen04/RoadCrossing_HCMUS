#include"CMenu.h"
void CMenu::showMenu() {
	while (true) {
        clearScreen();
        drawTitle();

		int selectedOption = displayMenuOptions();

		if (selectedOption == 0) {
            clearScreen();
            start();
		}
		else if (selectedOption == 1) {
			// Options option selected
		
			// Thực hiện logic cho tùy chọn "Options"
			// ...
			// Sau khi hoàn thành cài đặt tùy chọn, bạn có thể quay lại menu.
		}
		else if (selectedOption == 2) {
            clearScreen();
            exitGame();
			break; // Thoát khỏi menu
		}
	}
}
void CMenu::start()
{
    // Initialize game variables and setup
    int score = 0;
    bool isGameOver = false;

    // Game loop
    //while (!isGameOver) {
    //    // Clear the screen and display game content
    //   
    //    CGame g;
    //    g.runGame();
    //    // Get user input
    //    char key = CConsole::getInput();

    //    // Process user input
    //    if (key == 'q') {
    //        isGameOver = true;
    //    }
    //    else {
    //      
    //    }
    //}

    // Game over screen
    

    // Wait for user input to return to the main menu
    CConsole::getInput();
}
void CMenu::exitGame() {
    
    CConsole::gotoXY(40, 10);
    std::cout << "Exiting the game..." << std::endl;
    CConsole::setColor(White);
    CConsole::gotoXY(40, 12);
    std::cout << "Goodbye!" << std::endl;
    // Optionally, you can add any cleanup or save game data logic here.
    // ...

    // Exit the program
    exit(0);
}
void CMenu::drawTitle(bool isForRemove)
{
    int x = 40;
    int y = 1;
    if (!isForRemove)
    {
        drawHorLine(x, 77, y, block, Red);
        drawVerLine(y, 16,x, block, Blue);
    }
}