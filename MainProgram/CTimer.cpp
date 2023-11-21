#include "CTimer.h"

CTimer::CTimer()
{
	startTime = std::chrono::high_resolution_clock::now();
	stone = std::chrono::high_resolution_clock::now();
}

int CTimer::timeLapse()
{
	timeNow = std::chrono::high_resolution_clock::now();
	return  std::chrono::duration_cast<std::chrono::seconds>(timeNow - startTime).count();
}

bool CTimer::countDown(int secs)
{
	timeNow = std::chrono::high_resolution_clock::now();
	int t = std::chrono::duration_cast<std::chrono::seconds>(timeNow - stone).count();
	return t >= secs;
}

void CTimer::setStone()
{
	stone =	startTime = std::chrono::high_resolution_clock::now();
}
