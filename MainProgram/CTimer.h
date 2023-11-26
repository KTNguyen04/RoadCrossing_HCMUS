#pragma once
#include <chrono>
using namespace std;
class CTimer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime, stone,stone2;
	
public:
	CTimer();
	int timeLapse();
	bool countDown(int secs);
	void setStone();
};

