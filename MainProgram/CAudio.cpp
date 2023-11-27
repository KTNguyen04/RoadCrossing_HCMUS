#pragma comment(lib,"winmm.lib")
#include<Windows.h>
#include<iostream>
#include"CAudio.h"
bool isSoundPlaying = false; //sau nay neu out ra vao menu thi nhac ko bi reset lai tu dau
using namespace std;

string Audio ::path;

Audio::Audio()
{
	path = "audio/";
}

void Audio::playSound(string type)
{
	type = path + type +".wav";
	mciSendString(L"close sound ", NULL, 0, NULL);

	wstring wideString(type.begin(), type.end());
    wstring command = L"open \"" + wideString + L"\" type waveaudio alias sound";
	mciSendString(command.c_str(), NULL, 0, NULL);
	//Play sound
	mciSendString(L"play sound", NULL, 0, NULL);
//	mciSendString(L"stop sound", NULL, 0, NULL);

 
}
void Audio::stopSound()
{
	mciSendString(L"stop sound", NULL, 0, NULL);
}
