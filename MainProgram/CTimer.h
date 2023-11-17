#pragma once
#include <chrono>
using namespace std;
class CTimer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime, timeNow,stone;
	
public:
	CTimer();
	int timeLapse();
	bool countDown(int secs);

};

