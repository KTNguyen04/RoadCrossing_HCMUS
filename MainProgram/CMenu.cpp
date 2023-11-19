#include"CMenu.h"
void CMenu::showMenu() {
    int selectedOption = 0; 
    clearScreen();  

    while (true) {
        drawTitle(false,Red);
        drawStartOption(false, Black, selectedOption == 0);
        drawLoadOption(false, Black, selectedOption == 1);
        drawOptionsOption(false, Black, selectedOption == 2);
        drawAboutOption(false, Black, selectedOption == 3);
        drawHelpOption(false, Black, selectedOption == 4);
        drawExitOption(false, Black, selectedOption == 5);

        int userInput = displayMenuOptions();

        if (userInput == 'w' && selectedOption > 0) {
            drawStartOption(true, Black, selectedOption == 0);  // Clear previous selection
            selectedOption--;
        }
        else if (userInput == 's' && selectedOption < 5) {
            drawStartOption(true, Black, selectedOption == 3);  // Clear previous selection
            selectedOption++;
        }
        else if (userInput == 13) {  // Enter key
            if (selectedOption == 0) {
                clearScreen();
                CGame g;
                g.startGame();
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
void CMenu::drawTitle(bool isForRemove,int Color)
{
    int Color1 = Color + 1;
    if (!isForRemove)
    {
        //Draw C 
        drawHorLine(47, 50, 0, block, Color, 15);
        drawVerLine(1, 3, 45, block, Color, 15);
        drawVerLine(1, 3, 46, block, Color, 15);
        drawChar(51, 1, block, Color, 15);
        drawChar(52, 1, block, Color, 15);
        drawChar(51, 3, block, Color, 15);
        drawChar(52, 3, block, Color, 15);
        drawHorLine(47, 50, 4, block, Color, 15);

        //Draw R
        drawHorLine(54, 59, 0, block, Color, 15);
        drawVerLine(1, 4, 54, block, Color, 15);
        drawVerLine(1, 4, 55, block, Color, 15);
        drawHorLine(56, 59, 2, block, Color, 15);
        drawHorLine(58, 59, 3, block, Color, 15);
        drawHorLine(60, 61, 1, block, Color, 15);
        drawHorLine(60, 61, 4, block, Color, 15);
        //Draw O
        drawHorLine(65, 68, 0, block, Color, 15);
        drawHorLine(65, 68, 4, block, Color, 15);
        drawVerLine(1, 3, 63, block, Color, 15);
        drawVerLine(1, 3, 64, block, Color, 15);
        drawVerLine(1, 3, 69, block, Color, 15);
        drawVerLine(1, 3, 70, block, Color, 15);
        //Draw S   
        drawHorLine(74, 79, 0, block, Color, 15);
        drawHorLine(72, 73, 1, block, Color, 15);
        drawHorLine(74, 77, 2, block, Color, 15);
        drawHorLine(78, 79, 3, block, Color, 15);
        drawHorLine(72, 77, 4, block, Color, 15);

        //Draw S
        drawHorLine(83, 88, 0, block, Color, 15);
        drawHorLine(81, 82, 1, block, Color, 15);
        drawHorLine(83, 86, 2, block, Color, 15);
        drawHorLine(87, 88, 3, block, Color, 15);
        drawHorLine(81, 87, 4, block, Color, 15);
        //Draw I
        drawHorLine(90, 91, 0, block, Color, 15);
        drawHorLine(94, 95, 0, block, Color, 15);
        drawHorLine(90, 91, 4, block, Color, 15);
        drawHorLine(94, 95, 4, block, Color, 15);
        drawVerLine(0, 4, 92, block, Color, 15);
        drawVerLine(0, 4, 93, block, Color, 15);

        //Draw N 
        drawVerLine(0, 4, 97, block, Color, 15);
        drawVerLine(0, 4, 98, block, Color, 15);
        drawVerLine(0, 4, 107, block, Color, 15);
        drawVerLine(0, 4, 108, block, Color, 15);
        drawHorLine(99, 100, 0, block, Color, 15);
        drawHorLine(101, 102, 1, block, Color, 15);
        drawHorLine(103, 104, 2, block, Color, 15);
        drawHorLine(105, 106, 3, block, Color, 15);
        //Draw G
        drawVerLine(1, 3, 110, block, Color, 15);
        drawVerLine(1, 3, 111, block, Color, 15);
        drawHorLine(112, 117, 0, block, Color, 15);
        drawHorLine(114, 117, 2, block, Color, 15);
        drawHorLine(116, 117, 3, block, Color, 15);
        drawHorLine(112, 115, 4, block, Color, 15);

        //Draw G(Blue)
        drawVerLine(8, 10, 65, block, Color1, 15);
        drawVerLine(8, 10, 66, block, Color1, 15);
        drawHorLine(67, 72, 7, block, Color1, 15);
        drawHorLine(69, 72, 9, block, Color1, 15);
        drawHorLine(71, 72, 10, block, Color1, 15);
        drawHorLine(67, 70, 11, block, Color1, 15);
        //Draw A(Blue)
        drawHorLine(76, 79, 7, block, Color1, 15);
        drawVerLine(8, 11, 74, block, Color1, 15);
        drawVerLine(8, 11, 75, block, Color1, 15);
        drawVerLine(8, 11, 80, block, Color1, 15);
        drawVerLine(8, 11, 81, block, Color1, 15);
        drawHorLine(76, 79, 9, block, Color1, 15);
        //Draw M(Blue)
        drawVerLine(7, 11, 84, block, Color1, 15);
        drawVerLine(7, 11, 85, block, Color1, 15);
        drawVerLine(7, 11, 92, block, Color1, 15);
        drawVerLine(7, 11, 93, block, Color1, 15);
        drawHorLine(86, 87, 7, block, Color1, 15);
        drawHorLine(88, 89, 8, block, Color1, 15);
        drawHorLine(88, 89, 9, block, Color1, 15);
        drawHorLine(90, 91, 7, block, Color1, 15);
        //Draw E(Blue)
        drawVerLine(7, 11, 95, block, Color1, 15);
        drawVerLine(7, 11, 96, block, Color1, 15);
        drawHorLine(97, 100, 7, block, Color1, 15);
        drawHorLine(97, 100, 9, block, Color1, 15);
        drawHorLine(97, 100, 11, block, Color1, 15);



    }
}
void CMenu::drawStartOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 14, topBlock, highlightColor, 15);
        drawChar(67, 14, botBlock, highlightColor, 15);
        drawChar(94, 14, botBlock, highlightColor, 15);
        drawVerLine(15, 16, 66, block, highlightColor, 15);
        drawVerLine(15, 16, 95, block, highlightColor, 15);
        drawChar(66, 17, topBlock, highlightColor, 15);
        drawChar(95, 17, topBlock, highlightColor, 15);
        drawChar(67, 17, botBlock, highlightColor, 15);
        drawChar(94, 17, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 18, topBlock, highlightColor, 15);
        //Ve Start
        //Ve S
        drawHorLine(71, 73, 15, topBlock, highlightColor, 15);
        drawChar(70, 15, botBlock, highlightColor, 15);
        drawHorLine(71, 72, 16, topBlock, highlightColor, 15);
        drawChar(73, 16, botBlock, highlightColor, 15);
        drawHorLine(70, 72, 17, topBlock, highlightColor, 15);

        //Ve T
        drawChar(75, 15, topBlock, highlightColor, 15);
        drawChar(77, 15, topBlock, highlightColor, 15);
        drawVerLine(15, 16, 76, block, highlightColor, 15);
        drawChar(76, 17, topBlock, highlightColor, 15);
        //Draw A       
        drawHorLine(80, 81, 15, topBlock, highlightColor, 15);
        drawChar(79, 15, botBlock, highlightColor, 15);
        drawChar(82, 15, botBlock, highlightColor, 15);
        drawChar(79, 16, block, highlightColor, 15);
        drawChar(82, 16, block, highlightColor, 15);
        drawChar(79, 17, topBlock, highlightColor, 15);
        drawChar(82, 17, topBlock, highlightColor, 15);
        drawHorLine(80, 81, 16, topBlock, highlightColor, 15);
        //Draw R
        drawVerLine(15, 16, 84, block, highlightColor, 15);
        drawChar(84, 17, topBlock, highlightColor, 15);
        drawHorLine(85, 86, 16, topBlock, highlightColor, 15);
        drawHorLine(85, 86, 15, topBlock, highlightColor, 15);
        drawChar(87, 15, botBlock, highlightColor, 15);
        drawChar(87, 16, botBlock, highlightColor, 15);
        drawChar(87, 17, topBlock, highlightColor, 15);
        //Draw T
        drawChar(89, 15, topBlock, highlightColor, 15);
        drawChar(91, 15, topBlock, highlightColor, 15);
        drawVerLine(15, 16, 90, block, highlightColor, 15);
        drawChar(90, 17, topBlock, highlightColor, 15);


    }
}
void CMenu::drawLoadOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 21, topBlock, highlightColor, 15);
        drawChar(67, 21, botBlock, highlightColor, 15);
        drawChar(94, 21, botBlock, highlightColor, 15);
        drawVerLine(22, 23, 66, block, highlightColor, 15);
        drawVerLine(22, 23, 95, block, highlightColor, 15);
        drawChar(66, 24, topBlock, highlightColor, 15);
        drawChar(95, 24, topBlock, highlightColor, 15);
        drawChar(67, 24, botBlock, highlightColor, 15);
        drawChar(94, 24, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 25, topBlock, highlightColor, 15);
        //Draw L
        drawVerLine(22, 23, 71, block, highlightColor, 15);
        drawChar(71, 24, topBlock, highlightColor, 15);
        drawHorLine(72, 73, 24, topBlock, highlightColor, 15);
        //Draw O
        drawHorLine(76, 77, 22, topBlock, highlightColor, 15);
        drawHorLine(76, 77, 24, topBlock, highlightColor, 15);
        drawChar(75, 23, block, highlightColor, 15);
        drawChar(78, 23, block, highlightColor, 15);
        drawChar(75, 22, botBlock, highlightColor, 15);
        drawChar(78, 22, botBlock, highlightColor, 15);
        //Draw A
        drawHorLine(81, 82, 22, topBlock, highlightColor, 15);
        drawChar(80, 22, botBlock, highlightColor, 15);
        drawChar(83, 22, botBlock, highlightColor, 15);
        drawChar(80, 23, block, highlightColor, 15);
        drawChar(83, 23, block, highlightColor, 15);
        drawChar(80, 24, topBlock, highlightColor, 15);
        drawChar(83, 24, topBlock, highlightColor, 15);
        drawHorLine(81, 82, 23, topBlock, highlightColor, 15);
        //Draw D
        drawVerLine(22, 23, 85, block, highlightColor, 15);
        drawChar(85, 24, topBlock, highlightColor, 15);
        drawHorLine(86, 87, 22, topBlock, highlightColor, 15);
        drawHorLine(86, 87, 24, topBlock, highlightColor, 15);
        drawChar(88, 23, block, highlightColor, 15);
        drawChar(88, 22, botBlock, highlightColor, 15);


    }
}
void CMenu::drawOptionsOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung*
        drawHorLine(68, 99, 28, topBlock, highlightColor, 15);
        drawChar(67, 28, botBlock, highlightColor, 15);
        drawChar(100, 28, botBlock, highlightColor, 15);
        drawVerLine(29, 30, 66, block, highlightColor, 15);
        drawVerLine(29, 30, 101, block, highlightColor, 15);
        drawChar(66, 31, topBlock, highlightColor, 15);
        drawChar(101, 31, topBlock, highlightColor, 15);
        drawChar(67, 31, botBlock, highlightColor, 15);
        drawChar(100, 31, botBlock, highlightColor, 15);
        drawHorLine(68, 99, 32, topBlock, highlightColor, 15);
        //Ve Options
        //Draw O
        drawHorLine(69, 70, 29, topBlock, highlightColor, 15);
        drawHorLine(69, 70, 31, topBlock, highlightColor, 15);
        drawChar(68, 30, block, highlightColor, 15);
        drawChar(71, 30, block, highlightColor, 15);
        drawChar(68, 29, botBlock, highlightColor, 15);
        drawChar(71, 29, botBlock, highlightColor, 15);
        //Draw P
        drawVerLine(29, 30, 73, block, highlightColor, 15);
        drawChar(73, 31, topBlock, highlightColor, 15);
        drawHorLine(74, 75, 29, topBlock, highlightColor, 15);
        drawHorLine(74, 75, 30, topBlock, highlightColor, 15);
        drawChar(76, 29, botBlock, highlightColor, 15);
        //Draw T
        drawChar(78, 29, topBlock, highlightColor, 15);
        drawChar(80, 29, topBlock, highlightColor, 15);
        drawVerLine(29, 30, 79, block, highlightColor, 15);
        drawChar(79, 31, topBlock, highlightColor, 15);
        //Draw I
        drawVerLine(29, 30, 82, block, highlightColor, 15);
        drawChar(82, 31, topBlock, highlightColor, 15);
        //Draw O
        drawHorLine(85, 86, 29, topBlock, highlightColor, 15);
        drawHorLine(85, 86, 31, topBlock, highlightColor, 15);
        drawChar(84, 30, block, highlightColor, 15);
        drawChar(87, 30, block, highlightColor, 15);
        drawChar(84, 29, botBlock, highlightColor, 15);
        drawChar(87, 29, botBlock, highlightColor, 15);
        //Draw N
        drawVerLine(29, 30, 89, block, highlightColor, 15);
        drawChar(89, 31, topBlock, highlightColor, 15);
        drawVerLine(29, 30, 93, block, highlightColor, 15);
        drawChar(93, 31, topBlock, highlightColor, 15);
        drawChar(90, 29, botBlock, highlightColor, 15);
        drawChar(91, 30, topBlock, highlightColor, 15);
        drawChar(92, 30, botBlock, highlightColor, 15);
        //Ve S
        drawHorLine(96, 98, 29, topBlock, highlightColor, 15);
        drawChar(95, 29, botBlock, highlightColor, 15);
        drawHorLine(96, 97, 30, topBlock, highlightColor, 15);
        drawChar(98, 30, botBlock, highlightColor, 15);
        drawHorLine(95, 97, 31, topBlock, highlightColor, 15);



    }

}
void CMenu::drawAboutOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 35, topBlock, highlightColor, 15);
        drawChar(67, 35, botBlock, highlightColor, 15);
        drawChar(94, 35, botBlock, highlightColor, 15);
        drawVerLine(36, 37, 66, block, highlightColor, 15);
        drawVerLine(36, 37, 95, block, highlightColor, 15);
        drawChar(66, 38, topBlock, highlightColor, 15);
        drawChar(95, 38, topBlock, highlightColor, 15);
        drawChar(67, 38, botBlock, highlightColor, 15);
        drawChar(94, 38, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 39, topBlock, highlightColor, 15);
        //Ve About
        //Draw A       
        drawHorLine(70, 71, 36, topBlock, highlightColor, 15);
        drawChar(69, 36, botBlock, highlightColor, 15);
        drawChar(72, 36, botBlock, highlightColor, 15);
        drawChar(69, 37, block, highlightColor, 15);
        drawChar(72, 37, block, highlightColor, 15);
        drawChar(69, 38, topBlock, highlightColor, 15);
        drawChar(72, 38, topBlock, highlightColor, 15);
        drawHorLine(70, 71, 37, topBlock, highlightColor, 15);
        //Draw B
        drawVerLine(36, 37, 74, block, highlightColor, 15);
        drawChar(74, 38, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 36, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 37, topBlock, highlightColor, 15);
        drawHorLine(75, 76, 38, topBlock, highlightColor, 15);
        drawChar(77, 36, botBlock, highlightColor, 15);
        drawChar(77, 37, botBlock, highlightColor, 15);
        //Draw O
        drawHorLine(80, 81, 36, topBlock, highlightColor, 15);
        drawHorLine(80, 81, 38, topBlock, highlightColor, 15);
        drawChar(79, 37, block, highlightColor, 15);
        drawChar(82, 37, block, highlightColor, 15);
        drawChar(79, 36, botBlock, highlightColor, 15);
        drawChar(82, 36, botBlock, highlightColor, 15);
        //Draw U
        drawVerLine(36, 37, 84, block, highlightColor, 15);
        drawVerLine(36, 37, 87, block, highlightColor, 15);
        drawHorLine(85, 86, 38, topBlock, highlightColor, 15);
        //Draw T
        drawChar(89, 36, topBlock, highlightColor, 15);
        drawChar(91, 36, topBlock, highlightColor, 15);
        drawVerLine(36, 37, 90, block, highlightColor, 15);
        drawChar(90, 38, topBlock, highlightColor, 15);




    }
}
void CMenu::drawHelpOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 42, topBlock, highlightColor, 15);
        drawChar(67, 42, botBlock, highlightColor, 15);
        drawChar(94, 42, botBlock, highlightColor, 15);
        drawVerLine(43, 44, 66, block, highlightColor, 15);
        drawVerLine(43, 44, 95, block, highlightColor, 15);
        drawChar(66, 45, topBlock, highlightColor, 15);
        drawChar(95, 45, topBlock, highlightColor, 15);
        drawChar(67, 45, botBlock, highlightColor, 15);
        drawChar(94, 45, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 46, topBlock, highlightColor, 15);
        //Draw H
        drawVerLine(43, 44, 72, block, highlightColor, 15);
        drawChar(72, 45, topBlock, highlightColor, 15);
        drawVerLine(43, 44, 75, block, highlightColor, 15);
        drawChar(75, 45, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 44, topBlock, highlightColor, 15);
        //Draw E
        drawVerLine(43, 44, 77, block, highlightColor, 15);
        drawChar(77, 45, topBlock, highlightColor, 15);
        drawHorLine(78, 79, 43, topBlock, highlightColor, 15);
        drawHorLine(78, 79, 44, topBlock, highlightColor, 15);
        drawHorLine(78, 79, 45, topBlock, highlightColor, 15);
        //Draw L
        drawVerLine(43, 44, 81, block, highlightColor, 15);
        drawChar(81, 45, topBlock, highlightColor, 15);
        drawHorLine(82, 83, 45, topBlock, highlightColor, 15);
        //Draw P
        drawVerLine(43, 44, 85, block, highlightColor, 15);
        drawChar(85, 45, topBlock, highlightColor, 15);
        drawHorLine(86, 87, 43, topBlock, highlightColor, 15);
        drawHorLine(86, 87, 44, topBlock, highlightColor, 15);
        drawChar(88, 43, botBlock, highlightColor, 15);

    }
}
void CMenu::drawExitOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        drawHorLine(68, 93, 49, topBlock, highlightColor, 15);
        drawChar(67, 49, botBlock, highlightColor, 15);
        drawChar(94, 49, botBlock, highlightColor, 15);
        drawVerLine(50, 51, 66, block, highlightColor, 15);
        drawVerLine(50, 51, 95, block, highlightColor, 15);
        drawChar(66, 52, topBlock, highlightColor, 15);
        drawChar(95, 52, topBlock, highlightColor, 15);
        drawChar(67, 52, botBlock, highlightColor, 15);
        drawChar(94, 52, botBlock, highlightColor, 15);
        drawHorLine(68, 93, 53, topBlock, highlightColor, 15);
        //Draw E
        drawVerLine(50, 51, 72, block, highlightColor, 15);
        drawChar(72, 52, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 50, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 51, topBlock, highlightColor, 15);
        drawHorLine(73, 74, 52, topBlock, highlightColor, 15);
        //Draw X
        drawChar(76, 50, topBlock, highlightColor, 15);
        drawChar(76, 52, topBlock, highlightColor, 15);
        drawChar(80, 50, topBlock, highlightColor, 15);
        drawChar(80, 52, topBlock, highlightColor, 15);

        drawChar(77, 50, botBlock, highlightColor, 15);
        drawChar(77, 51, botBlock, highlightColor, 15);
        drawChar(79, 50, botBlock, highlightColor, 15);
        drawChar(79, 51, botBlock, highlightColor, 15);
        drawChar(78, 51, topBlock, highlightColor, 15);
        //Draw I
        drawVerLine(50, 51, 82, block, highlightColor, 15);
        drawChar(82, 52, topBlock, highlightColor, 15);
        //Draw T
        drawChar(84, 50, topBlock, highlightColor, 15);
        drawChar(86, 50, topBlock, highlightColor, 15);
        drawVerLine(50, 51, 85, block, highlightColor, 15);
        drawChar(85, 52, topBlock, highlightColor, 15);


    }
}