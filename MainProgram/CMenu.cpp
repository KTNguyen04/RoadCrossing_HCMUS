#include"CMenu.h"
void CMenu::showMenu() {
    int selectedOption = 0; 
    clearScreen();  

    while (true) {
        drawTitle();
        drawMenuOption(false, Black, selectedOption == 0);
        drawAboutOption(false, Black, selectedOption == 1);
        drawOptionsOption(false, Black, selectedOption == 2);
        drawExitOption(false, Black, selectedOption == 3);

        int userInput = displayMenuOptions();

        if (userInput == 'w' && selectedOption > 0) {
            drawMenuOption(true, Black, selectedOption == 0);  // Clear previous selection
            selectedOption--;
        }
        else if (userInput == 's' && selectedOption < 3) {
            drawMenuOption(true, Black, selectedOption == 3);  // Clear previous selection
            selectedOption++;
        }
        else if (userInput == 13) {  // Enter key
            if (selectedOption == 0) {
                clearScreen();
                start();
            }
            else if (selectedOption == 1) {
                // About option selected
                // Add your logic here
            }
            else if(selectedOption==2)
            {
                //Options option selected
            }
            else if (selectedOption == 3) {
                clearScreen();
                exitGame();
                break;
            }
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

    clearScreen();
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
  
    if (!isForRemove)
    {
        //Draw C 
        drawChar(61, 1, botBlock, Red,15);
        drawChar(62, 1, botBlock, Red,15);
        drawChar(60, 2, block, Red,15);
        drawChar(63, 2, topBlock, Red, 15);
        drawChar(60, 3, block, Red, 15);
        drawChar(60, 4, topBlock, Red, 15);
        drawChar(61, 4, botBlock, Red, 15);
        drawChar(62, 4, botBlock, Red, 15);
        drawChar(63, 4, topBlock, Red, 15);
        //Draw R
        drawChar(65, 1, botBlock, Red, 15);
        drawChar(66, 1, botBlock, Red, 15);
        drawChar(67, 1, botBlock, Red, 15);
        drawVerLine(2, 4, 65, block, Red, 15);
        drawChar(66, 3, topBlock, Red, 15);
        drawChar(67, 3, topBlock, Red, 15);
        drawVerLine(2, 2, 68, block, Red, 15);
        drawChar(68, 3, botBlock, Red, 15);
        drawChar(68, 4, block, Red, 15);
        //Draw O
        drawChar(71, 1, botBlock, Red, 15);
        drawChar(72, 1, botBlock, Red, 15);
        drawVerLine(2, 3, 70, block, Red, 15);
        drawVerLine(2, 3, 73, block, Red, 15);
        drawChar(70, 4, topBlock, Red, 15);
        drawChar(73, 4, topBlock, Red, 15);
        drawChar(71, 4, botBlock, Red, 15);
        drawChar(72, 4, botBlock, Red, 15);
        //Draw S   
        drawChar(76, 1, botBlock, Red, 15);
        drawChar(77, 1, botBlock, Red, 15);
        drawChar(75, 2, block, Red, 15);
        drawChar(78, 2, topBlock, Red, 15);
        drawChar(76, 3, topBlock, Red, 15);
        drawChar(77, 3, botBlock, Red, 15);
        drawChar(75, 4, topBlock, Red, 15);
        drawChar(78, 4, topBlock, Red, 15);
        drawChar(76, 4, botBlock, Red, 15);
        drawChar(77, 4, botBlock, Red, 15);
        //Draw S
        drawChar(81, 1, botBlock, Red, 15);
        drawChar(82, 1, botBlock, Red, 15);
        drawChar(80, 2, block, Red, 15);
        drawChar(83, 2, topBlock, Red, 15);
        drawChar(81, 3, topBlock, Red, 15);
        drawChar(82, 3, botBlock, Red, 15);
        drawChar(80, 4, topBlock, Red, 15);
        drawChar(83, 4, topBlock, Red, 15);
        drawChar(81, 4, botBlock, Red, 15);
        drawChar(82, 4, botBlock, Red, 15);
        //Draw I
        drawChar(85, 1, botBlock, Red, 15);
        drawVerLine(2, 4,85, block, Red, 15);
        //Draw N 
        drawChar(87, 1, botBlock, Red, 15);
        drawVerLine(2, 4, 87, block, Red, 15);
        drawChar(88, 1, botBlock, Red, 15);
        drawChar(89, 2, block, Red, 15);
        drawChar(89, 3, topBlock, Red, 15);
        drawChar(90, 3, botBlock, Red, 15);
        drawChar(90, 4, topBlock, Red, 15);
        drawChar(91, 4, botBlock, Red, 15);
        drawChar(92, 1, botBlock, Red, 15);
        drawVerLine(2, 4, 92, block, Red, 15);
        //Draw G
        drawChar(95, 1, botBlock, Red, 15);
        drawChar(96, 1, botBlock, Red, 15);
        drawChar(97, 2, topBlock, Red, 15);
        drawVerLine(2, 3, 94, block, Red, 15);
        drawChar(94, 4, topBlock, Red, 15);
        drawChar(95, 4, botBlock, Red, 15);
        drawChar(96, 4, botBlock, Red, 15);
        drawChar(97, 4, topBlock, Red, 15);
        drawChar(97, 3, botBlock, Red, 15);
        drawChar(96, 3, botBlock, Red, 15);
        //Draw R(Blue)
        drawChar(69, 6, botBlock, Blue, 15);
        drawChar(70, 6, botBlock, Blue, 15);
        drawChar(71, 6, botBlock, Blue, 15);
        drawVerLine(7, 9, 69, block, Blue, 15);
        drawChar(70, 8, topBlock, Blue, 15);
        drawChar(71, 8, topBlock, Blue, 15);
        drawVerLine(7, 7, 72, block, Blue, 15);
        drawChar(72, 8, botBlock, Blue, 15);
        drawChar(72, 9, block, Blue, 15);
        //Draw O(Blue)
        drawChar(75, 6, botBlock, Blue, 15);
        drawChar(76, 6, botBlock, Blue, 15);
        drawVerLine(7, 8, 74, block, Blue, 15);
        drawVerLine(7, 8, 77, block, Blue, 15);
        drawChar(74, 9, topBlock, Blue, 15);
        drawChar(77, 9, topBlock, Blue, 15);
        drawChar(75, 9, botBlock, Blue, 15);
        drawChar(76, 9, botBlock, Blue, 15);
        //Draw A(Blue)
        drawHorLine(80, 81, 6, botBlock, Blue, 15);
        drawVerLine(7, 9, 79, block, Blue, 15);
        drawVerLine(7, 9, 82, block, Blue, 15);
        drawHorLine(80, 81, 8, topBlock, Blue, 15);
        //Draw D(Blue)
        drawHorLine(84,86,6,botBlock,Blue,15);
        drawVerLine(7, 9, 84, block, Blue, 15);
        drawHorLine(85, 86, 9, botBlock, Blue, 15);
        drawChar(87, 7, topBlock, Blue, 15);
        drawChar(88, 7, botBlock, Blue, 15);
        drawChar(87, 9, topBlock, Blue, 15);
        drawChar(88, 8, block, Blue, 15);

    }
}
void CMenu::drawMenuOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
       drawHorLine(68, 93, 15, topBlock, highlightColor, 15);
       drawChar(67,15,botBlock, highlightColor,15);
       drawChar(94, 15, botBlock, highlightColor, 15);
       drawVerLine(16, 17, 66, block, highlightColor, 15);
       drawVerLine(16, 17, 95, block, highlightColor, 15);
       drawChar(66,18,topBlock, highlightColor,15);
       drawChar(95, 18, topBlock, highlightColor, 15);
       drawChar(67, 18, botBlock, highlightColor, 15);
       drawChar(94, 18, botBlock, highlightColor, 15);
       drawHorLine(68, 93, 19, topBlock, highlightColor, 15);
       //Ve Start
       //Ve S
       drawHorLine(71,73,16,topBlock, highlightColor,15);
       drawChar(70, 16, botBlock, highlightColor, 15);
       drawHorLine(71, 72, 17, topBlock, highlightColor, 15);
       drawChar(73, 17, botBlock, highlightColor, 15);
       drawHorLine(70, 72, 18, topBlock, highlightColor, 15);
       //Ve T
       drawChar(75,16,topBlock, highlightColor,15);
       drawChar(77, 16, topBlock, highlightColor, 15);
       drawVerLine(16,17,76,block, highlightColor,15);
       drawChar(76, 18, topBlock, highlightColor, 15);
       //Draw A       
       drawHorLine(80, 81, 16, topBlock, highlightColor, 15);
       drawChar(79, 16, botBlock, highlightColor, 15);
       drawChar(82, 16, botBlock, highlightColor, 15);
       drawChar(79, 17, block, highlightColor, 15);
       drawChar(82, 17, block, highlightColor, 15);
       drawChar(79, 18, topBlock, highlightColor, 15);
       drawChar(82, 18, topBlock, highlightColor, 15);
       drawHorLine(80, 81, 17, topBlock, highlightColor, 15);
       //Draw R
       drawVerLine(16, 17, 84, block, highlightColor, 15);
       drawChar(84, 18, topBlock, highlightColor, 15);
       drawHorLine(85, 86, 17, topBlock, highlightColor, 15);
       drawHorLine(85, 86, 16, topBlock, highlightColor, 15);
       drawChar(87, 16, botBlock, highlightColor, 15);
       drawChar(87, 17, botBlock, highlightColor, 15);
       drawChar(87, 18, topBlock, highlightColor, 15);
       //Draw T
       drawChar(89, 16, topBlock, highlightColor, 15);
       drawChar(91, 16, topBlock, highlightColor, 15);
       drawVerLine(16, 17, 90, block, highlightColor, 15);
       drawChar(90, 18, topBlock, highlightColor, 15);
    }
}
void CMenu::drawAboutOption(bool isForRemove,int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 22, topBlock, highlightColor, 15);
        drawChar(67, 22, botBlock, highlightColor, 15);
        drawChar(94, 22, botBlock, highlightColor, 15);
        drawVerLine(23, 24, 66, block, highlightColor, 15);
        drawVerLine(23, 24, 95, block, highlightColor, 15);
        drawChar(66, 25, topBlock, highlightColor, 15);
        drawChar(95, 25, topBlock, highlightColor, 15);
        drawChar(67, 25, botBlock, highlightColor, 15);
        drawChar(94, 25, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 26, topBlock, highlightColor, 15);
        //Ve About
        //Draw A       
        drawHorLine(70, 71, 23, topBlock, highlightColor, 15);
        drawChar(69, 23, botBlock, highlightColor, 15);
        drawChar(72, 23, botBlock, highlightColor, 15);
        drawChar(69, 24, block, highlightColor, 15);
        drawChar(72, 24, block, highlightColor, 15);
        drawChar(69, 25, topBlock, highlightColor, 15);
        drawChar(72, 25, topBlock, highlightColor, 15);
        drawHorLine(70, 71, 24, topBlock, highlightColor, 15);
        //Draw B
        drawVerLine(23, 24, 74, block, highlightColor, 15);
        drawChar(74, 25, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 23, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 24, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 25, topBlock, highlightColor, 15);
        drawChar(77, 23, botBlock, highlightColor, 15);
        drawChar(77, 24, botBlock, highlightColor, 15);
        //Draw O
        drawHorLine(80, 81, 23, topBlock, highlightColor, 15);
        drawHorLine(80, 81, 25, topBlock, highlightColor, 15);
        drawChar(79, 24, block, highlightColor, 15);
        drawChar(82, 24, block, highlightColor, 15);
        drawChar(79, 23, botBlock, highlightColor, 15);
        drawChar(82, 23, botBlock, highlightColor, 15);
        //Draw U
        drawVerLine(23, 24, 84, block, highlightColor, 15);
        drawVerLine(23, 24, 87, block, highlightColor, 15);
        drawHorLine(85, 86, 25, topBlock, highlightColor, 15);
        //Draw T
        drawChar(89, 23, topBlock, highlightColor, 15);
        drawChar(91, 23, topBlock, highlightColor, 15);
        drawVerLine(23, 24, 90, block, highlightColor, 15);
        drawChar(90, 25, topBlock, highlightColor, 15);

    }
}
void CMenu::drawOptionsOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung*
        drawHorLine(68, 99, 29, topBlock, highlightColor, 15);
        drawChar(67, 29, botBlock, highlightColor, 15);
        drawChar(100, 29, botBlock, highlightColor, 15);
        drawVerLine(30, 31, 66, block, highlightColor, 15);
        drawVerLine(30, 31, 101, block, highlightColor, 15);
        drawChar(66, 32, topBlock, highlightColor, 15);
        drawChar(101, 32, topBlock, highlightColor, 15);
        drawChar(67, 32, botBlock, highlightColor, 15);
        drawChar(100, 32, botBlock, highlightColor, 15);
        drawHorLine(68, 99, 33, topBlock, highlightColor, 15);
        //Ve Options
        //Draw O
        drawHorLine(69, 70, 30, topBlock, highlightColor, 15);
        drawHorLine(69, 70, 32, topBlock, highlightColor, 15);
        drawChar(68, 31, block, highlightColor, 15);
        drawChar(71, 31, block, highlightColor, 15);
        drawChar(68, 30, botBlock, highlightColor, 15);
        drawChar(71, 30, botBlock, highlightColor, 15);
        //Draw P
        drawVerLine(30, 31, 73, block, highlightColor, 15);
        drawChar(73, 32, topBlock, highlightColor, 15);
        drawHorLine(74, 75, 30, topBlock, highlightColor, 15);
        drawHorLine(74, 75, 31, topBlock, highlightColor, 15);
        drawChar(76, 30, botBlock, highlightColor, 15);
        //Draw T
        drawChar(78, 30, topBlock, highlightColor, 15);
        drawChar(80, 30, topBlock, highlightColor, 15);
        drawVerLine(30, 31, 79, block, highlightColor, 15);
        drawChar(79, 32, topBlock, highlightColor, 15);
        //Draw I
        drawVerLine(30, 31, 82, block, highlightColor, 15);
        drawChar(82, 32, topBlock, highlightColor, 15);
        //Draw O
        drawHorLine(85, 86, 30, topBlock, highlightColor, 15);
        drawHorLine(85, 86, 32, topBlock, highlightColor, 15);
        drawChar(84, 31, block, highlightColor, 15);
        drawChar(87, 31, block, highlightColor, 15);
        drawChar(84, 30, botBlock, highlightColor, 15);
        drawChar(87, 30, botBlock, highlightColor, 15);
        //Draw N
        drawVerLine(30, 31, 89, block, highlightColor, 15);
        drawChar(89, 32, topBlock, highlightColor, 15);
        drawVerLine(30, 31, 93, block, highlightColor, 15);
        drawChar(93, 32, topBlock, highlightColor, 15);
        drawChar(90, 30, botBlock, highlightColor, 15);
        drawChar(91, 31, topBlock, highlightColor, 15);
        drawChar(92, 31, botBlock, highlightColor, 15);
        //Ve S
        drawHorLine(96, 98, 30, topBlock, highlightColor, 15);
        drawChar(95, 30, botBlock, highlightColor, 15);
        drawHorLine(96, 97, 31, topBlock, highlightColor, 15);
        drawChar(98, 31, botBlock, highlightColor, 15);
        drawHorLine(95, 97, 32, topBlock, highlightColor, 15);
    }

}
void CMenu::drawExitOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 36, topBlock, highlightColor, 15);
        drawChar(67, 36, botBlock, highlightColor, 15);
        drawChar(94, 36, botBlock, highlightColor, 15);
        drawVerLine(37, 38, 66, block, highlightColor, 15);
        drawVerLine(37, 38, 95, block, highlightColor, 15);
        drawChar(66, 39, topBlock, highlightColor, 15);
        drawChar(95, 39, topBlock, highlightColor, 15);
        drawChar(67, 39, botBlock, highlightColor, 15);
        drawChar(94, 39, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 40, topBlock, highlightColor, 15);
        //Draw E
        drawVerLine(37, 38, 72, block, highlightColor, 15);
        drawChar(72, 39, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 37, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 38, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 39, topBlock, highlightColor, 15);
        //Draw X
        drawChar(76, 37, topBlock, highlightColor, 15);
        drawChar(76, 39, topBlock, highlightColor, 15);
        drawChar(80, 37, topBlock, highlightColor, 15);
        drawChar(80, 39, topBlock, highlightColor, 15);

        drawChar(77, 37, botBlock, highlightColor, 15);
        drawChar(77, 38, botBlock, highlightColor, 15);
        drawChar(79, 37, botBlock, highlightColor, 15);
        drawChar(79, 38, botBlock, highlightColor, 15);
        drawChar(78, 38, topBlock, highlightColor, 15);
        //Draw I
        drawVerLine(37, 38, 82, block, highlightColor, 15);
        drawChar(82, 39, topBlock, highlightColor, 15);
        //Draw T
        drawChar(84, 37, topBlock, highlightColor, 15);
        drawChar(86, 37, topBlock, highlightColor, 15);
        drawVerLine(37, 38, 85, block, highlightColor, 15);
        drawChar(85, 39, topBlock, highlightColor, 15);

    }
}