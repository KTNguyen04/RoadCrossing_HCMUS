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
	CMenu m;

	m.showMenu();

	/*CGame g;

	g.startGame();*/
	


//	std::promise<void> start,st2,st3;
//	std::future<void> end = start.get_future(), end2 = st2.get_future();
//
//	thread t3(&CGame::runGame,&g,ref(start ));
//	end.get();
//	/*thread t3([&g]() {
//		g.runGame();
//	std::this_thread::sleep_for(std::chrono::seconds(2));
//		});*/
////	g.runGame();
//	CPeople people;
//	//g.runGame();
//	char inp;
//
//	/*thread t1([&inp,&people]() {
//		while (true) {
//			inp = CConsole::getInput();
//			
//			people.peopleMoving(inp);
//
//		}
//		});*/
//	thread t2([&g]() {
//
//		g.runObstacle();
//
//
//		});
//	while (true) {
//		inp = CConsole::getInput();
//		people.peopleMoving(inp);
//		//std::this_thread::sleep_for(std::chrono::seconds());
//
//
//	}
//	

	/*CMenu m;
	m.showMenu();
	*/
	//	t1.join();
	//t2.join();
	//t1.join();
	
	
}


