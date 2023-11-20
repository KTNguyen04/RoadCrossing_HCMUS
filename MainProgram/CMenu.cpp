#include"CMenu.h"
#include "CAudio.h"
void CMenu::showMenu() {
    Audio au;
    au.mainMenuAudio();
    int selectedOption = 0; 
    CConsole::clearScreen();  

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
            drawStartOption(true, Black, selectedOption == 5);  // Clear previous selection
            selectedOption++;
        }
        else if (userInput == 13) {  // Enter key
            if (selectedOption == 0) {
                CConsole::clearScreen();
                CGame g;
                g.startGame();
            }
            else if (selectedOption == 1) {

                // load game
                
            }
            else if(selectedOption==2)
            {
                CConsole::clearScreen();
                options();
                break;
            }
            else if (selectedOption == 3)
            {
                //About option selected
                CConsole::clearScreen();
                about();
                break;
            }
            else if (selectedOption == 4)
            {
                //About option selected
                CConsole::clearScreen();
                help();
                break;
            }
            else if (selectedOption == 5) {
                CConsole::clearScreen();
                about();
                break;
            }
            else if (selectedOption == 4) {
                CConsole::clearScreen();
                help();
                break;
            }
            else if (selectedOption == 5) {
                CConsole::clearScreen();
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


void CMenu::options()
{
    CConsole::clearScreen();
    int Color = Red;
    bool isForRemove = false;
    int selectedOption = 0;
    //Draw Tua 
    if (!isForRemove)
    {
        //Ve Khung*
        CConsole::drawHorLine(68, 99, 5, topBlock, Color, 15);
        CConsole::drawChar(67, 5, botBlock, Color, 15);
        CConsole::drawChar(100, 5, botBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 66, block, Color, 15);
        CConsole::drawVerLine(6, 7, 101, block, Color, 15);
        CConsole::drawChar(66, 8, topBlock, Color, 15);
        CConsole::drawChar(101, 8, topBlock, Color, 15);
        CConsole::drawChar(67, 8, botBlock, Color, 15);
        CConsole::drawChar(100, 8, botBlock, Color, 15);
        CConsole::drawHorLine(68, 99, 9, topBlock, Color, 15);
        //Ve Options
        //Draw O
        CConsole::drawHorLine(69, 70, 6, topBlock, Color, 15);
        CConsole::drawHorLine(69, 70, 8, topBlock, Color, 15);
        CConsole::drawChar(68, 7, block, Color, 15);
        CConsole::drawChar(71, 7, block, Color, 15);
        CConsole::drawChar(68, 6, botBlock, Color, 15);
        CConsole::drawChar(71, 6, botBlock, Color, 15);
        //Draw P
        CConsole::drawVerLine(6, 7, 73, block, Color, 15);
        CConsole::drawChar(73, 8, topBlock, Color, 15);
        CConsole::drawHorLine(74, 75, 6, topBlock, Color, 15);
        CConsole::drawHorLine(74, 75, 7, topBlock, Color, 15);
        CConsole::drawChar(76, 6, botBlock, Color, 15);
        //Draw T
        CConsole::drawChar(78, 6, topBlock, Color, 15);
        CConsole::drawChar(80, 6, topBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 79, block, Color, 15);
        CConsole::drawChar(79, 8, topBlock, Color, 15);
        //Draw I
        CConsole::drawVerLine(6, 7, 82, block, Color, 15);
        CConsole::drawChar(82, 8, topBlock, Color, 15);
        //Draw O
        CConsole::drawHorLine(85, 86, 6, topBlock, Color, 15);
        CConsole::drawHorLine(85, 86, 8, topBlock, Color, 15);
        CConsole::drawChar(84, 7, block, Color, 15);
        CConsole::drawChar(87, 7, block, Color, 15);
        CConsole::drawChar(84, 6, botBlock, Color, 15);
        CConsole::drawChar(87, 6, botBlock, Color, 15);
        //Draw N
        CConsole::drawVerLine(6, 7, 89, block, Color, 15);
        CConsole::drawChar(89, 8, topBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 93, block, Color, 15);
        CConsole::drawChar(93, 8, topBlock, Color, 15);
        CConsole::drawChar(90, 6, botBlock, Color, 15);
        CConsole::drawChar(91, 7, topBlock, Color, 15);
        CConsole::drawChar(92, 7, botBlock, Color, 15);
        //Ve S
        CConsole::drawHorLine(96, 98, 6, topBlock, Color, 15);
        CConsole::drawChar(95, 6, botBlock, Color, 15);
        CConsole::drawHorLine(96, 97, 7, topBlock, Color, 15);
        CConsole::drawChar(98, 7, botBlock, Color, 15);
        CConsole::drawHorLine(95, 97, 8, topBlock, Color, 15);
    }
    Color = Black;
    while (true)
    {
        CConsole::gotoXY(62, 28);
        cout << "Press R to return to the main menu...";
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
                Audio au;
                au.stopAudio();
            }
            else if (selectedOption == 0) {
                Audio au;
                au.mainMenuAudio();
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
    CConsole::clearScreen();
    int Color = Red;
    bool isForRemove = false;
    //Draw 
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 5, topBlock, Color, 15);
        CConsole::drawChar(67, 5, botBlock, Color, 15);
        CConsole::drawChar(94, 5, botBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 66, block, Color, 15);
        CConsole::drawVerLine(6, 7, 95, block, Color, 15);
        CConsole::drawChar(66, 8, topBlock, Color, 15);
        CConsole::drawChar(95, 8, topBlock, Color, 15);
        CConsole::drawChar(67, 8, botBlock, Color, 15);
        CConsole::drawChar(94, 8, botBlock, Color, 15);
        CConsole::drawHorLine(68, 93, 9, topBlock, Color, 15);
        //Ve About
        //Draw A       
        CConsole::drawHorLine(70, 71, 6, topBlock, Color, 15);
        CConsole::drawChar(69, 6, botBlock, Color, 15);
        CConsole::drawChar(72, 6, botBlock, Color, 15);
        CConsole::drawChar(69, 7, block, Color, 15);
        CConsole::drawChar(72, 7, block, Color, 15);
        CConsole::drawChar(69, 8, topBlock, Color, 15);
        CConsole::drawChar(72, 8, topBlock, Color, 15);
        CConsole::drawHorLine(70, 71, 7, topBlock, Color, 15);
        //Draw B
        CConsole::drawVerLine(6, 7, 74, block, Color, 15);
        CConsole::drawChar(74, 8, topBlock, Color, 15);
        CConsole::drawHorLine(75, 76, 6, topBlock, Color, 15);
        CConsole::drawHorLine(75, 76, 7, topBlock, Color, 15);
        CConsole::drawHorLine(75, 76, 8, topBlock, Color, 15);
        CConsole::drawChar(77, 6, botBlock, Color, 15);
        CConsole::drawChar(77, 7, botBlock, Color, 15);
        //Draw O
        CConsole::drawHorLine(80, 81, 6, topBlock, Color, 15);
        CConsole::drawHorLine(80, 81, 8, topBlock, Color, 15);
        CConsole::drawChar(79, 7, block, Color, 15);
        CConsole::drawChar(82, 7, block, Color, 15);
        CConsole::drawChar(79, 6, botBlock, Color, 15);
        CConsole::drawChar(82, 6, botBlock, Color, 15);
        //Draw U
        CConsole::drawVerLine(6, 7, 84, block, Color, 15);
        CConsole::drawVerLine(6, 7, 87, block, Color, 15);
        CConsole::drawHorLine(85, 86, 8, topBlock, Color, 15);
        //Draw T
        CConsole::drawChar(89, 6, topBlock, Color, 15);
        CConsole::drawChar(91, 6, topBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 90, block, Color, 15);
        CConsole::drawChar(90, 8, topBlock, Color, 15);

        CConsole::gotoXY(60, 12);
        cout << "     DO AN CUOI KI : GAME CROSSING ROAD";
        CConsole::gotoXY(60, 14);
        cout << "     GV HUONG DAN: Thay Truong Toan Thinh";
        CConsole::gotoXY(62, 16);
        cout << "        -------- NHOM 3 --------";
        CConsole::gotoXY(54, 18);
        cout << "- Ho va ten -                                  - MSSV -";
        CConsole::gotoXY(50, 20);
        cout << "Truong Nhat Huy                                    22127168";
        CConsole::gotoXY(50, 22);
        cout << "Do Luong Nhat Minh                                 22127262 ";
        CConsole::gotoXY(50, 24);
        cout << "Nguyen Khanh Toan                                  22127418  ";
        CConsole::gotoXY(50, 26);
        cout << "Nguyen Phuoc Minh Tri                              22127424 ";
        CConsole::gotoXY(62, 30);
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
    CConsole::clearScreen();
    int Color = Red;
    bool isForRemove = false;
    //Draw 
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 5, topBlock, Color, 15);
        CConsole::drawChar(67, 5, botBlock, Color, 15);
        CConsole::drawChar(94, 5, botBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 66, block, Color, 15);
        CConsole::drawVerLine(6, 7, 95, block, Color, 15);
        CConsole::drawChar(66, 8, topBlock, Color, 15);
        CConsole::drawChar(95, 8, topBlock, Color, 15);
        CConsole::drawChar(67, 8, botBlock, Color, 15);
        CConsole::drawChar(94, 8, botBlock, Color, 15);
        CConsole::drawHorLine(68, 93, 9, topBlock, Color, 15);
        //Draw H
        CConsole::drawVerLine(6, 7, 72, block, Color, 15);
        CConsole::drawChar(72, 8, topBlock, Color, 15);
        CConsole::drawVerLine(6, 7, 75, block, Color, 15);
        CConsole::drawChar(75, 8, topBlock, Color, 15);
        CConsole::drawHorLine(73, 74, 7, topBlock, Color, 15);
        //Draw E
        CConsole::drawVerLine(6, 7, 77, block, Color, 15);
        CConsole::drawChar(77, 8, topBlock, Color, 15);
        CConsole::drawHorLine(78, 79, 6, topBlock, Color, 15);
        CConsole::drawHorLine(78, 79, 7, topBlock, Color, 15);
        CConsole::drawHorLine(78, 79, 8, topBlock, Color, 15);
        //Draw L
        CConsole::drawVerLine(6, 7, 81, block, Color, 15);
        CConsole::drawChar(81, 8, topBlock, Color, 15);
        CConsole::drawHorLine(82, 83, 8, topBlock, Color, 15);
        //Draw P
        CConsole::drawVerLine(6, 7, 85, block, Color, 15);
        CConsole::drawChar(85, 8, topBlock, Color, 15);
        CConsole::drawHorLine(86, 87, 6, topBlock, Color, 15);
        CConsole::drawHorLine(86, 87, 7, topBlock, Color, 15);
        CConsole::drawChar(88, 6, botBlock, Color, 15);

        CConsole::gotoXY(20, 14);
        cout << "USE W A S D TO MOVE THE PLAYER UP DOWN LEFT AND RIGHT, T TO SAVE GAME";
        CConsole::gotoXY(20, 18);
        cout << "THE VEHICLES WILL MOVE WHEN TRAFFIC LIGHT TURN GREEN AND STOP WHEN TURN RED";
        CConsole::gotoXY(20, 22);
        cout << "KEEP MOVING UNTIL YOU REACH THE MOST BOTTOM LANE";
        CConsole::gotoXY(20, 26);
        cout << "THE SPEED WILL BE HIGHER AFTER EACH ROUND";
        CConsole::gotoXY(62, 30);
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
    bool isForRemove=false;
    CConsole::clearScreen();
    //Draw Thank You
    if (!isForRemove)
    {
        // Draw T
        CConsole::drawVerLine(15, 19, 33, block, Color, 15);
        CConsole::drawVerLine(15, 19, 34, block, Color, 15);
        CConsole::drawHorLine(30, 32, 15, block, Color, 15);
        CConsole::drawHorLine(35, 37, 15, block, Color, 15);
        //Draw H
        CConsole::drawVerLine(15, 19, 39, block, Color, 15);
        CConsole::drawVerLine(15, 19, 40, block, Color, 15);
        CConsole::drawVerLine(15, 19, 45, block, Color, 15);
        CConsole::drawVerLine(15, 19, 46, block, Color, 15);
        CConsole::drawHorLine(41, 44, 17, block, Color, 15);
        //Draw A
        CConsole::drawVerLine(16, 19, 49, block, Color, 15);
        CConsole::drawVerLine(16, 19, 50, block, Color, 15);
        CConsole::drawVerLine(16, 19, 55, block, Color, 15);
        CConsole::drawVerLine(16, 19, 56, block, Color, 15);
        CConsole::drawHorLine(51, 54, 15, block, Color, 15);
        CConsole::drawHorLine(51, 54, 17, block, Color, 15);
        //Draw N
        CConsole::drawVerLine(15, 19, 58, block, Color, 15);
        CConsole::drawVerLine(15, 19, 59, block, Color, 15);
        CConsole::drawVerLine(15, 19, 68, block, Color, 15);
        CConsole::drawVerLine(15, 19, 69, block, Color, 15);
        CConsole::drawHorLine(60, 61, 15, block, Color, 15);
        CConsole::drawHorLine(62, 63, 16, block, Color, 15);
        CConsole::drawHorLine(64, 65, 17, block, Color, 15);
        CConsole::drawHorLine(66, 67, 18, block, Color, 15);
        //Draw H
        CConsole::drawVerLine(15, 19, 71, block, Color, 15);
        CConsole::drawVerLine(15, 19, 72, block, Color, 15);
        CConsole::drawVerLine(15, 19, 77, block, Color, 15);
        CConsole::drawVerLine(15, 19, 78, block, Color, 15);
        CConsole::drawHorLine(73, 76, 17, block, Color, 15);
        //Draw Y
        CConsole::drawVerLine(15, 17, 84, block, Color, 15);
        CConsole::drawVerLine(15, 17, 85, block, Color, 15);
        CConsole::drawVerLine(15, 17, 88, block, Color, 15);
        CConsole::drawVerLine(15, 17, 89, block, Color, 15);
        CConsole::drawVerLine(17, 19, 86, block, Color, 15);
        CConsole::drawVerLine(17, 19, 87, block, Color, 15);
        //Draw O
        CConsole::drawHorLine(93, 96, 15, block, Color, 15);
        CConsole::drawHorLine(93, 96, 19, block, Color, 15);
        CConsole::drawVerLine(16, 18, 91, block, Color, 15);
        CConsole::drawVerLine(16, 18, 92, block, Color, 15);
        CConsole::drawVerLine(16, 18, 97, block, Color, 15);
        CConsole::drawVerLine(16, 18, 98, block, Color, 15);
        //Draw U
        CConsole::drawVerLine(15, 19, 100, block, Color, 15);
        CConsole::drawVerLine(15, 19, 101, block, Color, 15);
        CConsole::drawVerLine(15, 19, 105, block, Color, 15);
        CConsole::drawVerLine(15, 19, 106, block, Color, 15);
        CConsole::drawHorLine(102, 104, 19, block, Color, 15);
        int Color1 = Color - 3;
        //Draw F
        CConsole::drawVerLine(24, 28, 35, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 36, block, Color1, 15);
        CConsole::drawHorLine(37, 40, 24, block, Color1, 15);
        CConsole::drawHorLine(37, 40, 26, block, Color1, 15);
        //Draw O
        CConsole::drawHorLine(44, 47, 24, block, Color1, 15);
        CConsole::drawHorLine(44, 47, 28, block, Color1, 15);
        CConsole::drawVerLine(25, 27, 42, block, Color1, 15);
        CConsole::drawVerLine(25, 27, 43, block, Color1, 15);
        CConsole::drawVerLine(25, 27, 48, block, Color1, 15);
        CConsole::drawVerLine(25, 27, 49, block, Color1, 15);
        //Draw R
        CConsole::drawVerLine(24, 28, 51, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 52, block, Color1, 15);
        CConsole::drawHorLine(53, 56, 24, block, Color1, 15);
        CConsole::drawHorLine(53, 56, 26, block, Color1, 15);
        CConsole::drawHorLine(55, 56, 27, block, Color1, 15);
        CConsole::drawHorLine(57, 58, 25, block, Color1, 15);
        CConsole::drawHorLine(57, 58, 28, block, Color1, 15);
        //Draw P
        CConsole::drawVerLine(24, 28, 64, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 65, block, Color1, 15);
        CConsole::drawHorLine(66, 69, 24, block, Color1, 15);
        CConsole::drawHorLine(66, 69, 26, block, Color1, 15);
        CConsole::drawHorLine(70, 71, 25, block, Color1, 15);
        //Draw L
        CConsole::drawVerLine(24, 28, 73, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 74, block, Color1, 15);
        CConsole::drawHorLine(75, 78, 28, block, Color1, 15);
        //Draw A
        CConsole::drawVerLine(25, 28, 80, block, Color1, 15);
        CConsole::drawVerLine(25, 28, 81, block, Color1, 15);
        CConsole::drawVerLine(25, 28, 86, block, Color1, 15);
        CConsole::drawVerLine(25, 28, 87, block, Color1, 15);
        CConsole::drawHorLine(82, 85, 24, block, Color1, 15);
        CConsole::drawHorLine(82, 85, 26, block, Color1, 15);
        //Draw Y
        CConsole::drawVerLine(24, 26, 89, block, Color1, 15);
        CConsole::drawVerLine(24, 26, 90, block, Color1, 15);
        CConsole::drawVerLine(24, 26, 93, block, Color1, 15);
        CConsole::drawVerLine(24, 26, 94, block, Color1, 15);
        CConsole::drawVerLine(26, 28, 91, block, Color1, 15);
        CConsole::drawVerLine(26, 28, 92, block, Color1, 15);
        //Draw I
        CConsole::drawVerLine(24, 28, 96, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 97, block, Color1, 15);
        //Draw N
        CConsole::drawVerLine(24, 28, 99, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 100, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 109, block, Color1, 15);
        CConsole::drawVerLine(24, 28, 110, block, Color1, 15);
        CConsole::drawHorLine(101, 102, 24, block, Color1, 15);
        CConsole::drawHorLine(103, 104, 25, block, Color1, 15);
        CConsole::drawHorLine(105, 106, 26, block, Color1, 15);
        CConsole::drawHorLine(107, 108, 27, block, Color1, 15);
        //Draw G
        CConsole::drawVerLine(25, 27, 112, block, Color1, 15);
        CConsole::drawVerLine(25, 27, 113, block, Color1, 15);
        CConsole::drawHorLine(114, 119, 24, block, Color1, 15);
        CConsole::drawHorLine(116, 119, 26, block, Color1, 15);
        CConsole::drawHorLine(118, 119, 27, block, Color1, 15);
        CConsole::drawHorLine(114, 117, 28, block, Color1, 15);
    }
    // Optionally, you can add any cleanup or save game data logic here.
    // ...
    cin.ignore();
    // Exit the program
}
void CMenu::drawTitle(bool isForRemove,int Color)
{
    int Color1 = Color + 1;
    if (!isForRemove)
    {
        //Draw C 
        CConsole::drawHorLine(47, 50, 0, block, Color, 15);
        CConsole::drawVerLine(1, 3, 45, block, Color, 15);
        CConsole::drawVerLine(1, 3, 46, block, Color, 15);
        CConsole::drawChar(51, 1, block, Color, 15);
        CConsole::drawChar(52, 1, block, Color, 15);
        CConsole::drawChar(51, 3, block, Color, 15);
        CConsole::drawChar(52, 3, block, Color, 15);
        CConsole::drawHorLine(47, 50, 4, block, Color, 15);

        //Draw R
        CConsole::drawHorLine(54, 59, 0, block, Color, 15);
        CConsole::drawVerLine(1, 4, 54, block, Color, 15);
        CConsole::drawVerLine(1, 4, 55, block, Color, 15);
        CConsole::drawHorLine(56, 59, 2, block, Color, 15);
        CConsole::drawHorLine(58, 59, 3, block, Color, 15);
        CConsole::drawHorLine(60, 61, 1, block, Color, 15);
        CConsole::drawHorLine(60, 61, 4, block, Color, 15);
        //Draw O
        CConsole::drawHorLine(65, 68, 0, block, Color, 15);
        CConsole::drawHorLine(65, 68, 4, block, Color, 15);
        CConsole::drawVerLine(1, 3, 63, block, Color, 15);
        CConsole::drawVerLine(1, 3, 64, block, Color, 15);
        CConsole::drawVerLine(1, 3, 69, block, Color, 15);
        CConsole::drawVerLine(1, 3, 70, block, Color, 15);
        //Draw S   
        CConsole::drawHorLine(74, 79, 0, block, Color, 15);
        CConsole::drawHorLine(72, 73, 1, block, Color, 15);
        CConsole::drawHorLine(74, 77, 2, block, Color, 15);
        CConsole::drawHorLine(78, 79, 3, block, Color, 15);
        CConsole::drawHorLine(72, 77, 4, block, Color, 15);

        //Draw S
        CConsole::drawHorLine(83, 88, 0, block, Color, 15);
        CConsole::drawHorLine(81, 82, 1, block, Color, 15);
        CConsole::drawHorLine(83, 86, 2, block, Color, 15);
        CConsole::drawHorLine(87, 88, 3, block, Color, 15);
        CConsole::drawHorLine(81, 87, 4, block, Color, 15);
        //Draw I
        CConsole::drawHorLine(90, 91, 0, block, Color, 15);
        CConsole::drawHorLine(94, 95, 0, block, Color, 15);
        CConsole::drawHorLine(90, 91, 4, block, Color, 15);
        CConsole::drawHorLine(94, 95, 4, block, Color, 15);
        CConsole::drawVerLine(0, 4, 92, block, Color, 15);
        CConsole::drawVerLine(0, 4, 93, block, Color, 15);

        //Draw N 
        CConsole::drawVerLine(0, 4, 97, block, Color, 15);
        CConsole::drawVerLine(0, 4, 98, block, Color, 15);
        CConsole::drawVerLine(0, 4, 107, block, Color, 15);
        CConsole::drawVerLine(0, 4, 108, block, Color, 15);
        CConsole::drawHorLine(99, 100, 0, block, Color, 15);
        CConsole::drawHorLine(101, 102, 1, block, Color, 15);
        CConsole::drawHorLine(103, 104, 2, block, Color, 15);
        CConsole::drawHorLine(105, 106, 3, block, Color, 15);
        //Draw G
        CConsole::drawVerLine(1, 3, 110, block, Color, 15);
        CConsole::drawVerLine(1, 3, 111, block, Color, 15);
        CConsole::drawHorLine(112, 117, 0, block, Color, 15);
        CConsole::drawHorLine(114, 117, 2, block, Color, 15);
        CConsole::drawHorLine(116, 117, 3, block, Color, 15);
        CConsole::drawHorLine(112, 115, 4, block, Color, 15);

        //Draw G(Blue)
        CConsole::drawVerLine(8, 10, 65, block, Color1, 15);
        CConsole::drawVerLine(8, 10, 66, block, Color1, 15);
        CConsole::drawHorLine(67, 72, 7, block, Color1, 15);
        CConsole::drawHorLine(69, 72, 9, block, Color1, 15);
        CConsole::drawHorLine(71, 72, 10, block, Color1, 15);
        CConsole::drawHorLine(67, 70, 11, block, Color1, 15);
        //Draw A(Blue)
        CConsole::drawHorLine(76, 79, 7, block, Color1, 15);
        CConsole::drawVerLine(8, 11, 74, block, Color1, 15);
        CConsole::drawVerLine(8, 11, 75, block, Color1, 15);
        CConsole::drawVerLine(8, 11, 80, block, Color1, 15);
        CConsole::drawVerLine(8, 11, 81, block, Color1, 15);
        CConsole::drawHorLine(76, 79, 9, block, Color1, 15);
        //Draw M(Blue)
        CConsole::drawVerLine(7, 11, 84, block, Color1, 15);
        CConsole::drawVerLine(7, 11, 85, block, Color1, 15);
        CConsole::drawVerLine(7, 11, 92, block, Color1, 15);
        CConsole::drawVerLine(7, 11, 93, block, Color1, 15);
        CConsole::drawHorLine(86, 87, 7, block, Color1, 15);
        CConsole::drawHorLine(88, 89, 8, block, Color1, 15);
        CConsole::drawHorLine(88, 89, 9, block, Color1, 15);
        CConsole::drawHorLine(90, 91, 7, block, Color1, 15);
        //Draw E(Blue)
        CConsole::drawVerLine(7, 11, 95, block, Color1, 15);
        CConsole::drawVerLine(7, 11, 96, block, Color1, 15);
        CConsole::drawHorLine(97, 100, 7, block, Color1, 15);
        CConsole::drawHorLine(97, 100, 9, block, Color1, 15);
        CConsole::drawHorLine(97, 100, 11, block, Color1, 15);



    }
}
void CMenu::drawStartOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 14, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 14, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 14, botBlock, highlightColor, 15);
        CConsole::drawVerLine(15, 16, 66, block, highlightColor, 15);
        CConsole::drawVerLine(15, 16, 95, block, highlightColor, 15);
        CConsole::drawChar(66, 17, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 17, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 17, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 17, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 93, 18, topBlock, highlightColor, 15);
        //Ve Start
        //Ve S
        CConsole::drawHorLine(71, 73, 15, topBlock, highlightColor, 15);
        CConsole::drawChar(70, 15, botBlock, highlightColor, 15);
        CConsole::drawHorLine(71, 72, 16, topBlock, highlightColor, 15);
        CConsole::drawChar(73, 16, botBlock, highlightColor, 15);
        CConsole::drawHorLine(70, 72, 17, topBlock, highlightColor, 15);

        //Ve T
        CConsole::drawChar(75, 15, topBlock, highlightColor, 15);
        CConsole::drawChar(77, 15, topBlock, highlightColor, 15);
        CConsole::drawVerLine(15, 16, 76, block, highlightColor, 15);
        CConsole::drawChar(76, 17, topBlock, highlightColor, 15);
        //Draw A       
        CConsole::drawHorLine(80, 81, 15, topBlock, highlightColor, 15);
        CConsole::drawChar(79, 15, botBlock, highlightColor, 15);
        CConsole::drawChar(82, 15, botBlock, highlightColor, 15);
        CConsole::drawChar(79, 16, block, highlightColor, 15);
        CConsole::drawChar(82, 16, block, highlightColor, 15);
        CConsole::drawChar(79, 17, topBlock, highlightColor, 15);
        CConsole::drawChar(82, 17, topBlock, highlightColor, 15);
        CConsole::drawHorLine(80, 81, 16, topBlock, highlightColor, 15);
        //Draw R
        CConsole::drawVerLine(15, 16, 84, block, highlightColor, 15);
        CConsole::drawChar(84, 17, topBlock, highlightColor, 15);
        CConsole::drawHorLine(85, 86, 16, topBlock, highlightColor, 15);
        CConsole::drawHorLine(85, 86, 15, topBlock, highlightColor, 15);
        CConsole::drawHorLine(87, 15, botBlock, highlightColor, 15);
        CConsole::drawChar(87, 16, botBlock, highlightColor, 15);
        CConsole::drawChar(87, 17, topBlock, highlightColor, 15);
        //Draw T
        CConsole::drawChar(89, 15, topBlock, highlightColor, 15);
        CConsole::drawChar(91, 15, topBlock, highlightColor, 15);
        CConsole::drawVerLine(15, 16, 90, block, highlightColor, 15);
        CConsole::drawChar(90, 17, topBlock, highlightColor, 15);


    }
}
void CMenu::drawLoadOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 21, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 21, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 21, botBlock, highlightColor, 15);
        CConsole::drawVerLine(22, 23, 66, block, highlightColor, 15);
        CConsole::drawVerLine(22, 23, 95, block, highlightColor, 15);
        CConsole::drawChar(66, 24, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 24, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 24, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 24, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 93, 25, topBlock, highlightColor, 15);
        //Draw L
        CConsole::drawVerLine(22, 23, 71, block, highlightColor, 15);
        CConsole::drawChar(71, 24, topBlock, highlightColor, 15);
        CConsole::drawHorLine(72, 73, 24, topBlock, highlightColor, 15);
        //Draw O
        CConsole::drawHorLine(76, 77, 22, topBlock, highlightColor, 15);
        CConsole::drawHorLine(76, 77, 24, topBlock, highlightColor, 15);
        CConsole::drawChar(75, 23, block, highlightColor, 15);
        CConsole::drawChar(78, 23, block, highlightColor, 15);
        CConsole::drawChar(75, 22, botBlock, highlightColor, 15);
        CConsole::drawChar(78, 22, botBlock, highlightColor, 15);
        //Draw A
        CConsole::drawHorLine(81, 82, 22, topBlock, highlightColor, 15);
        CConsole::drawChar(80, 22, botBlock, highlightColor, 15);
        CConsole::drawChar(83, 22, botBlock, highlightColor, 15);
        CConsole::drawChar(80, 23, block, highlightColor, 15);
        CConsole::drawChar(83, 23, block, highlightColor, 15);
        CConsole::drawChar(80, 24, topBlock, highlightColor, 15);
        CConsole::drawChar(83, 24, topBlock, highlightColor, 15);
        CConsole::drawHorLine(81, 82, 23, topBlock, highlightColor, 15);
        //Draw D
        CConsole::drawVerLine(22, 23, 85, block, highlightColor, 15);
        CConsole::drawChar(85, 24, topBlock, highlightColor, 15);
        CConsole::drawHorLine(86, 87, 22, topBlock, highlightColor, 15);
        CConsole::drawHorLine(86, 87, 24, topBlock, highlightColor, 15);
        CConsole::drawChar(88, 23, block, highlightColor, 15);
        CConsole::drawChar(88, 22, botBlock, highlightColor, 15);


    }
}
void CMenu::drawOptionsOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung*
        CConsole::drawHorLine(68, 99, 28, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 28, botBlock, highlightColor, 15);
        CConsole::drawChar(100, 28, botBlock, highlightColor, 15);
        CConsole::drawVerLine(29, 30, 66, block, highlightColor, 15);
        CConsole::drawVerLine(29, 30, 101, block, highlightColor, 15);
        CConsole::drawChar(66, 31, topBlock, highlightColor, 15);
        CConsole::drawChar(101, 31, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 31, botBlock, highlightColor, 15);
        CConsole::drawChar(100, 31, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 99, 32, topBlock, highlightColor, 15);
        //Ve Options
        //Draw O
        CConsole::drawHorLine(69, 70, 29, topBlock, highlightColor, 15);
        CConsole::drawHorLine(69, 70, 31, topBlock, highlightColor, 15);
        CConsole::drawChar(68, 30, block, highlightColor, 15);
        CConsole::drawChar(71, 30, block, highlightColor, 15);
        CConsole::drawChar(68, 29, botBlock, highlightColor, 15);
        CConsole::drawChar(71, 29, botBlock, highlightColor, 15);
        //Draw P
        CConsole::drawVerLine(29, 30, 73, block, highlightColor, 15);
        CConsole::drawChar(73, 31, topBlock, highlightColor, 15);
        CConsole::drawHorLine(74, 75, 29, topBlock, highlightColor, 15);
        CConsole::drawHorLine(74, 75, 30, topBlock, highlightColor, 15);
        CConsole::drawChar(76, 29, botBlock, highlightColor, 15);
        //Draw T
        CConsole::drawChar(78, 29, topBlock, highlightColor, 15);
        CConsole::drawChar(80, 29, topBlock, highlightColor, 15);
        CConsole::drawVerLine(29, 30, 79, block, highlightColor, 15);
        CConsole::drawChar(79, 31, topBlock, highlightColor, 15);
        //Draw I
        CConsole::drawVerLine(29, 30, 82, block, highlightColor, 15);
        CConsole::drawChar(82, 31, topBlock, highlightColor, 15);
        //Draw O
        CConsole::drawHorLine(85, 86, 29, topBlock, highlightColor, 15);
        CConsole::drawHorLine(85, 86, 31, topBlock, highlightColor, 15);
        CConsole::drawChar(84, 30, block, highlightColor, 15);
        CConsole::drawChar(87, 30, block, highlightColor, 15);
        CConsole::drawChar(84, 29, botBlock, highlightColor, 15);
        CConsole::drawChar(87, 29, botBlock, highlightColor, 15);
        //Draw N
        CConsole::drawVerLine(29, 30, 89, block, highlightColor, 15);
        CConsole::drawChar(89, 31, topBlock, highlightColor, 15);
        CConsole::drawVerLine(29, 30, 93, block, highlightColor, 15);
        CConsole::drawChar(93, 31, topBlock, highlightColor, 15);
        CConsole::drawChar(90, 29, botBlock, highlightColor, 15);
        CConsole::drawChar(91, 30, topBlock, highlightColor, 15);
        CConsole::drawChar(92, 30, botBlock, highlightColor, 15);
        //Ve S
        CConsole::drawHorLine(96, 98, 29, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 29, botBlock, highlightColor, 15);
        CConsole::drawHorLine(96, 97, 30, topBlock, highlightColor, 15);
        CConsole::drawChar(98, 30, botBlock, highlightColor, 15);
        CConsole::drawHorLine(95, 97, 31, topBlock, highlightColor, 15);
    }

}
void CMenu::drawAboutOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 35, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 35, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 35, botBlock, highlightColor, 15);
        CConsole::drawVerLine(36, 37, 66, block, highlightColor, 15);
        CConsole::drawVerLine(36, 37, 95, block, highlightColor, 15);
        CConsole::drawChar(66, 38, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 38, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 38, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 38, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 93, 39, topBlock, highlightColor, 15);
        //Ve About
        //Draw A       
        CConsole::drawHorLine(70, 71, 36, topBlock, highlightColor, 15);
        CConsole::drawChar(69, 36, botBlock, highlightColor, 15);
        CConsole::drawChar(72, 36, botBlock, highlightColor, 15);
        CConsole::drawChar(69, 37, block, highlightColor, 15);
        CConsole::drawChar(72, 37, block, highlightColor, 15);
        CConsole::drawChar(69, 38, topBlock, highlightColor, 15);
        CConsole::drawChar(72, 38, topBlock, highlightColor, 15);
        CConsole::drawHorLine(70, 71, 37, topBlock, highlightColor, 15);
        //Draw B
        CConsole::drawVerLine(36, 37, 74, block, highlightColor, 15);
        CConsole::drawChar(74, 38, topBlock, highlightColor, 15);
        CConsole::drawHorLine(75, 76, 36, topBlock, highlightColor, 15);
        CConsole::drawHorLine(75, 76, 37, topBlock, highlightColor, 15);
        CConsole::drawHorLine(75, 76, 38, topBlock, highlightColor, 15);
        CConsole::drawChar(77, 36, botBlock, highlightColor, 15);
        CConsole::drawChar(77, 37, botBlock, highlightColor, 15);
        //Draw O
        CConsole::drawHorLine(80, 81, 36, topBlock, highlightColor, 15);
        CConsole::drawHorLine(80, 81, 38, topBlock, highlightColor, 15);
        CConsole::drawChar(79, 37, block, highlightColor, 15);
        CConsole::drawChar(82, 37, block, highlightColor, 15);
        CConsole::drawChar(79, 36, botBlock, highlightColor, 15);
        CConsole::drawChar(82, 36, botBlock, highlightColor, 15);
        //Draw U
        CConsole::drawVerLine(36, 37, 84, block, highlightColor, 15);
        CConsole::drawVerLine(36, 37, 87, block, highlightColor, 15);
        CConsole::drawHorLine(85, 86, 38, topBlock, highlightColor, 15);
        //Draw T
        CConsole::drawChar(89, 36, topBlock, highlightColor, 15);
        CConsole::drawChar(91, 36, topBlock, highlightColor, 15);
        CConsole::drawVerLine(36, 37, 90, block, highlightColor, 15);
        CConsole::drawChar(90, 38, topBlock, highlightColor, 15);
    }
}
void CMenu::drawHelpOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 42, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 42, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 42, botBlock, highlightColor, 15);
        CConsole::drawVerLine(43, 44, 66, block, highlightColor, 15);
        CConsole::drawVerLine(43, 44, 95, block, highlightColor, 15);
        CConsole::drawChar(66, 45, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 45, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 45, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 45, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 93, 46, topBlock, highlightColor, 15);
        //Draw H
        CConsole::drawVerLine(43, 44, 72, block, highlightColor, 15);
        CConsole::drawChar(72, 45, topBlock, highlightColor, 15);
        CConsole::drawVerLine(43, 44, 75, block, highlightColor, 15);
        CConsole::drawChar(75, 45, topBlock, highlightColor, 15);
        CConsole::drawHorLine(73, 74, 44, topBlock, highlightColor, 15);
        //Draw E
        CConsole::drawVerLine(43, 44, 77, block, highlightColor, 15);
        CConsole::drawChar(77, 45, topBlock, highlightColor, 15);
        CConsole::drawHorLine(78, 79, 43, topBlock, highlightColor, 15);
        CConsole::drawHorLine(78, 79, 44, topBlock, highlightColor, 15);
        CConsole::drawHorLine(78, 79, 45, topBlock, highlightColor, 15);
        //Draw L
        CConsole::drawVerLine(43, 44, 81, block, highlightColor, 15);
        CConsole::drawChar(81, 45, topBlock, highlightColor, 15);
        CConsole::drawHorLine(82, 83, 45, topBlock, highlightColor, 15);
        //Draw P
        CConsole::drawVerLine(43, 44, 85, block, highlightColor, 15);
        CConsole::drawChar(85, 45, topBlock, highlightColor, 15);
        CConsole::drawHorLine(86, 87, 43, topBlock, highlightColor, 15);
        CConsole::drawHorLine(86, 87, 44, topBlock, highlightColor, 15);
        CConsole::drawChar(88, 43, botBlock, highlightColor, 15);

    }
}
void CMenu::drawExitOption(bool isForRemove, int color, bool isSelected)
{
    int highlightColor = isSelected ? Green : color;
    if (!isForRemove)
    {
        //Ve Khung
        CConsole::drawHorLine(68, 93, 49, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 49, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 49, botBlock, highlightColor, 15);
        CConsole::drawVerLine(50, 51, 66, block, highlightColor, 15);
        CConsole::drawVerLine(50, 51, 95, block, highlightColor, 15);
        CConsole::drawChar(66, 52, topBlock, highlightColor, 15);
        CConsole::drawChar(95, 52, topBlock, highlightColor, 15);
        CConsole::drawChar(67, 52, botBlock, highlightColor, 15);
        CConsole::drawChar(94, 52, botBlock, highlightColor, 15);
        CConsole::drawHorLine(68, 93, 53, topBlock, highlightColor, 15);
        //Draw E
        CConsole::drawVerLine(50, 51, 72, block, highlightColor, 15);
        CConsole::drawChar(72, 52, topBlock, highlightColor, 15);
        CConsole::drawHorLine(73, 74, 50, topBlock, highlightColor, 15);
        CConsole::drawHorLine(73, 74, 51, topBlock, highlightColor, 15);
        CConsole::drawHorLine(73, 74, 52, topBlock, highlightColor, 15);
        //Draw X
        CConsole::drawChar(76, 50, topBlock, highlightColor, 15);
        CConsole::drawChar(76, 52, topBlock, highlightColor, 15);
        CConsole::drawChar(80, 50, topBlock, highlightColor, 15);
        CConsole::drawChar(80, 52, topBlock, highlightColor, 15);

        CConsole::drawChar(77, 50, botBlock, highlightColor, 15);
        CConsole::drawChar(77, 51, botBlock, highlightColor, 15);
        CConsole::drawChar(79, 50, botBlock, highlightColor, 15);
        CConsole::drawChar(79, 51, botBlock, highlightColor, 15);
        CConsole::drawChar(78, 51, topBlock, highlightColor, 15);
        //Draw I
        CConsole::drawVerLine(50, 51, 82, block, highlightColor, 15);
        CConsole::drawChar(82, 52, topBlock, highlightColor, 15);
        //Draw T
        CConsole::drawChar(84, 50, topBlock, highlightColor, 15);
        CConsole::drawChar(86, 50, topBlock, highlightColor, 15);
        CConsole::drawVerLine(50, 51, 85, block, highlightColor, 15);
        CConsole::drawChar(85, 52, topBlock, highlightColor, 15);
    }
}
void CMenu::drawMute(bool isForRemove, int color, bool isSelected)
{
    int Color = color;
    int Color1 = isSelected ? color + 9 : Gray;
    if (!isForRemove)
    {
        CConsole::drawHorLine(120, 121, 28, topBlock, Color, 15);
        CConsole::drawChar(119, 28, botBlock, Color, 15);
        CConsole::drawChar(122, 28, botBlock, Color, 15);
        CConsole::drawVerLine(29, 33, 122, block, Color, 15);
        CConsole::drawHorLine(120, 121, 34, botBlock, Color, 15);
        CConsole::drawChar(119, 34, topBlock, Color, 15);
        CConsole::drawChar(122, 34, topBlock, Color, 15);
        CConsole::drawChar(118, 29, topBlock, Color, 15);
        CConsole::drawChar(117, 29, botBlock, Color, 15);
        CConsole::drawChar(117, 33, topBlock, Color, 15);
        CConsole::drawChar(118, 33, botBlock, Color, 15);
        CConsole::drawHorLine(114, 116, 30, topBlock, Color, 15);
        CConsole::drawHorLine(114, 116, 32, botBlock, Color, 15);
        CConsole::drawChar(113, 30, botBlock, Color, 15);
        CConsole::drawChar(113, 31, block, Color, 15);
        CConsole::drawChar(113, 32, topBlock, Color, 15);

        CConsole::drawVerLine(29, 33, 121, block, Color1, 15);
        CConsole::drawVerLine(29, 33, 120, block, Color1, 15);
        CConsole::drawChar(121, 34, topBlock, Color1, Black);
        CConsole::drawChar(120, 34, topBlock, Color1, Black);
        CConsole::drawVerLine(30, 33, 119, block, Color1, 15);
        CConsole::drawChar(119, 29, botBlock, Color1, 15);
        CConsole::drawVerLine(30, 32, 118, block, Color1, 15);
        CConsole::drawChar(118, 33, topBlock, Color1, Black);
        CConsole::drawVerLine(31, 32, 117, block, Color1, 15);
        CConsole::drawChar(117, 30, botBlock, Color1, 15);
        CConsole::drawHorLine(114, 116, 31, block, Color1, 15);
        CConsole::drawHorLine(114, 116, 32, topBlock, Color1, Black);
        CConsole::drawChar(114, 30, botBlock, Color1, 15);
        //
        CConsole::drawChar(113, 28, topBlock, Color, 15);
        CConsole::drawChar(114, 28, botBlock, Color, 15);
        CConsole::drawChar(115, 29, topBlock, Color, 15);
        CConsole::drawChar(116, 29, botBlock, Color, 15);
        CConsole::drawChar(117, 30, topBlock, Color, Black);
        CConsole::drawChar(118, 30, botBlock, Color, Color1);
        CConsole::drawChar(119, 31, topBlock, Color, Color1);
        CConsole::drawChar(120, 31, botBlock, Color, Color1);
        CConsole::drawChar(121, 32, topBlock, Color, Color1);//
        CConsole::drawChar(123, 33, topBlock, Color, 15);
        CConsole::drawChar(124, 33, botBlock, Color, 15);
        CConsole::drawChar(125, 34, topBlock, Color, 15);
        CConsole::drawChar(126, 34, botBlock, Color, 15);


    }
    if (!isForRemove)
    {
        Color = Black;
        //Draw word Mute
       //Draw M
        CConsole::drawVerLine(38, 40, 109, block, Color, 15);
        CConsole::drawVerLine(38, 40, 113, block, Color, 15);
        CConsole::drawChar(109, 41, topBlock, Color, Black);
        CConsole::drawChar(113, 41, topBlock, Color, Black);
        CConsole::drawChar(110, 38, botBlock, Color, Black);
        CConsole::drawChar(112, 38, botBlock, Color, Black);
        CConsole::drawChar(111, 39, block, Color, 15);
        //Draw U
        CConsole::drawVerLine(38, 40, 115, block, Color, 15);
        CConsole::drawVerLine(38, 40, 119, block, Color, 15);
        CConsole::drawChar(115, 41, topBlock, Color, 15);
        CConsole::drawChar(119, 41, topBlock, Color, 15);
        CConsole::drawHorLine(116, 118, 41, botBlock, Color, 15);
        //Draw T
        CConsole::drawVerLine(38, 41, 123, block, Color, 15);
        CConsole::drawHorLine(121, 122, 38, topBlock, Color, 15);
        CConsole::drawHorLine(124, 125, 38, topBlock, Color, 15);
        //Draw E
        CConsole::drawVerLine(38, 40, 127, block, Color, 15);
        CConsole::drawChar(127, 41, block, Color, 15);
        CConsole::drawHorLine(128, 130, 38, topBlock, Color, 15);
        CConsole::drawHorLine(128, 130, 39, botBlock, Color, 15);
        CConsole::drawHorLine(128, 130, 41, botBlock, Color, 15);
    }
}
void CMenu::drawUnmute(bool isForRemove, int color, bool isSelected)
{
    int Color = color;
    int Color1 = isSelected ? color + 9 : Gray;
    if (!isForRemove)
    {
        Color = Black;
        CConsole::drawHorLine(50, 51, 28, topBlock, Color, 15);
        CConsole::drawChar(49, 28, botBlock, Color, 15);
        CConsole::drawChar(52, 28, botBlock, Color, 15);
        CConsole::drawVerLine(29, 33, 52, block, Color, 15);
        CConsole::drawHorLine(50, 51, 34, botBlock, Color, 15);
        CConsole::drawChar(49, 34, topBlock, Color, 15);
        CConsole::drawChar(52, 34, topBlock, Color, 15);
        CConsole::drawChar(48, 29, topBlock, Color, 15);
        CConsole::drawChar(47, 29, botBlock, Color, 15);
        CConsole::drawChar(47, 33, topBlock, Color, 15);
        CConsole::drawChar(48, 33, botBlock, Color, 15);
        CConsole::drawHorLine(44, 46, 30, topBlock, Color, 15);
        CConsole::drawHorLine(44, 46, 32, botBlock, Color, 15);
        CConsole::drawChar(43, 30, botBlock, Color, 15);
        CConsole::drawChar(43, 31, block, Color, 15);
        CConsole::drawChar(43, 32, topBlock, Color, 15);
        //
        CConsole::drawVerLine(29, 33, 51, block, Color1, 15);
        CConsole::drawVerLine(29, 33, 50, block, Color1, 15);
        CConsole::drawChar(51, 34, topBlock, Color1, Black);
        CConsole::drawChar(50, 34, topBlock, Color1, Black);
        CConsole::drawVerLine(30, 33, 49, block, Color1, 15);
        CConsole::drawChar(49, 29, botBlock, Color1, 15);
        CConsole::drawVerLine(30, 32, 48, block, Color1, 15);
        CConsole::drawChar(48, 33, topBlock, Color1, Black);
        CConsole::drawVerLine(31, 32, 47, block, Color1, 15);
        CConsole::drawChar(47, 30, botBlock, Color1, 15);
        CConsole::drawHorLine(44, 46, 31, block, Color1, 15);
        CConsole::drawHorLine(44, 46, 32, topBlock, Color1, Black);
        CConsole::drawChar(44, 30, botBlock, Color1, 15);
        //
        CConsole::drawVerLine(31, 32, 54, block, Color, 15);
        CConsole::drawVerLine(30, 33, 56, block, Color, 15);
        CConsole::drawVerLine(29, 34, 58, block, Color, 15);
    }
    //Draw word Unmute
    if (!isForRemove)
    {
        Color = Black;
        //Draw U
        CConsole::drawVerLine(38, 40, 34, block, Color, 15);
        CConsole::drawVerLine(38, 40, 38, block, Color, 15);
        CConsole::drawChar(34, 41, topBlock, Color, 15);
        CConsole::drawChar(38, 41, topBlock, Color, 15);
        CConsole::drawHorLine(35, 37, 41, botBlock, Color, 15);
        //Draw N
        CConsole::drawVerLine(38, 40, 40, block, Color, 15);
        CConsole::drawVerLine(38, 40, 45, block, Color, 15);
        CConsole::drawChar(40, 41, block, Color, 15);
        CConsole::drawChar(45, 41, block, Color, 15);
        CConsole::drawChar(41, 38, botBlock, Color, 15);//
        CConsole::drawChar(42, 39, topBlock, Color, 15);
        CConsole::drawChar(43, 39, botBlock, Color, 15);
        CConsole::drawChar(44, 40, topBlock, Color, 15);
        //Draw M
        CConsole::drawVerLine(38, 40, 47, block, Color, 15);
        CConsole::drawVerLine(38, 40, 51, block, Color, 15);
        CConsole::drawChar(47, 41, topBlock, Color, Black);
        CConsole::drawChar(51, 41, topBlock, Color, Black);
        CConsole::drawChar(48, 38, botBlock, Color, Black);
        CConsole::drawChar(50, 38, botBlock, Color, Black);
        CConsole::drawChar(49, 39, block, Color, 15);
        //Draw U
        CConsole::drawVerLine(38, 40, 53, block, Color, 15);
        CConsole::drawVerLine(38, 40, 57, block, Color, 15);
        CConsole::drawChar(53, 41, topBlock, Color, 15);
        CConsole::drawChar(57, 41, topBlock, Color, 15);
        CConsole::drawHorLine(54, 56, 41, botBlock, Color, 15);
        //Draw T
        CConsole::drawVerLine(38, 41, 61, block, Color, 15);
        CConsole::drawHorLine(59, 60, 38, topBlock, Color, 15);
        CConsole::drawHorLine(62, 63, 38, topBlock, Color, 15);
        //Draw E
        CConsole::drawVerLine(38, 40, 65, block, Color, 15);
        CConsole::drawChar(65, 41, block, Color, 15);
        CConsole::drawHorLine(66, 68, 38, topBlock, Color, 15);
        CConsole::drawHorLine(66, 68, 39, botBlock, Color, 15);
        CConsole::drawHorLine(66, 68, 41, botBlock, Color, 15);
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
