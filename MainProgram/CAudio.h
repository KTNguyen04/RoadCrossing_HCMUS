#pragma once
#include <string>
using namespace std;
class Audio {
	static string path;
public:
	Audio();
	static void playSound(string type);
	static void playSound2(string type,bool isOn = true);
	static void stopSound();
};
