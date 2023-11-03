#pragma comment(lib,"winmm.lib")
#include<Windows.h>
#include<iostream>
#include"CAudio.h"
bool isSoundPlaying = false; //sau nay neu out ra vao menu thi nhac ko bi reset lai tu dau
using namespace std;

void Audio::mainMenuAudio() {
	if (!isSoundPlaying) {
		DWORD volumeMenu = 8000;
		waveOutSetVolume(NULL, MAKELONG(volumeMenu, volumeMenu));
		PlaySound(TEXT("Menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
		isSoundPlaying = true;
	}
}

void Audio::stopAudio() // tat tieng
{
	PlaySound(NULL, NULL, SND_ASYNC);
	isSoundPlaying = false; // gan lai de neu bat am thanh len lai thi nhac lai choi
}

void Audio::dashAudio() {
	PlaySound(TEXT("Dash.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void Audio::hitAudio() {
	PlaySound(TEXT("Dash.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Audio::gameVictoryAudio() {
	PlaySound(TEXT("Victory.wav"), NULL, SND_FILENAME | SND_ASYNC);

}

void Audio::gameOverAudio() {
	PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Audio::carHornAudio() {
	PlaySound(TEXT("CarHorn.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Audio::tapAudio() {
	PlaySound(TEXT("Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);

}