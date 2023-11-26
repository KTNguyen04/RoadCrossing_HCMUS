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

//void Audio::mainMenuAudio() {
//	if (!isSoundPlaying) {
//		DWORD volumeMenu = 8000;
//		waveOutSetVolume(NULL, MAKELONG(volumeMenu, volumeMenu));
//		PlaySound(TEXT("Menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
//		isSoundPlaying = true;
//	}
//}
//
//void Audio::stopAudio() // tat tieng
//{
//	PlaySound(NULL, NULL, SND_ASYNC);
//	isSoundPlaying = false; // gan lai de neu bat am thanh len lai thi nhac lai choi
//}
//
//void Audio::dashAudio() {
//	PlaySound(TEXT("Dash.wav"), NULL, SND_FILENAME | SND_ASYNC);
//}
//void Audio::hitAudio() {
//	PlaySound(TEXT("Dash.wav"), NULL, SND_FILENAME | SND_ASYNC);
//}
//
//void Audio::gameVictoryAudio() {
//	PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//}
//
//void Audio::gameOverAudio() {
//	PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
//}
//
//void Audio::carHornAudio() {
//	PlaySound(TEXT("CarHorn.wav"), NULL, SND_FILENAME | SND_ASYNC);
//}
//
//void Audio::tapAudio() {
//	PlaySound(TEXT("Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//}
