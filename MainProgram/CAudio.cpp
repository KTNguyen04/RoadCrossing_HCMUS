#pragma comment(lib,"winmm.lib")
#include<Windows.h>
#include<iostream>
#include"CAudio.h"

using namespace std;

string Audio::path = "audio/";

Audio::Audio()
{
}

void Audio::playSound(string type)
{
	type = path + type + ".wav";
	mciSendString(L"close sound ", NULL, 0, NULL);

	wstring wideString(type.begin(), type.end());
	wstring command = L"open \"" + wideString + L"\" type waveaudio alias sound";
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString(L"play sound", NULL, 0, NULL);


}
void Audio::playSound2( string type, bool isOn)
{
	type = path + type + ".wav";
	wstring wideString(type.begin(), type.end());
	if (!isOn)
		PlaySound(0, 0, 0);
	else
		PlaySound(wideString.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);



}
void Audio::stopSound()
{
	mciSendString(L"stop sound", NULL, 0, NULL);
}
