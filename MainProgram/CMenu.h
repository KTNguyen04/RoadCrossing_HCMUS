#pragma once
#include "CGame.h"
#include "CRoad.h"
class CMenu : public CConsole
{
public:
	CMenu() {
		options.push_back("Start Game");
		options.push_back("Options");
		options.push_back("Exit");
	}
    void drawTitle(bool isForRemove = false);
	void showMenu();
	void start();
	void exitGame();
private:
	std::vector<std::string> options;

    int displayMenuOptions() {
        int selectedOption = 0;

    while (true) {
         // Clear the screen to re-print menu options

        for (size_t i = 0; i < options.size(); ++i) {
            if (i == selectedOption) {
                CConsole::setColor(Cyan);
                CConsole::gotoXY(70, 20 + 2 * i);
                std::cout << "> " << options[i]; // Highlight the selected option
            }
            else {
                CConsole::setColor(White);
                CConsole::gotoXY(70, 20 + 2 * i);
                std::cout << "  " << options[i];
            }
        }

        char key = CConsole::getInput();
        if (key == 'w' && selectedOption > 0) {
            selectedOption--;
        }
        else if (key == 's' && selectedOption < static_cast<int>(options.size()) - 1) {
            selectedOption++;
        }
        else if (key == '\r') {
            // User selected an option, return its index
            return selectedOption;
        }
    }
    }
};

