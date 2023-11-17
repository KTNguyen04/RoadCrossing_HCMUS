#include "CTrafficLight.h"
#include "CGame.h"

CTrafficLight::CTrafficLight() {
	lightState = "green";
	redTime = 2;
	greenTime = 3;
	height = 8;
	width = 4;
	color = Black;
	greenColor = Green;
	redColor = DarkRed;
}
CTrafficLight::CTrafficLight(int x, int y):CTrafficLight()
{
	coorX = x;
	coorY = y;
}
void CTrafficLight::drawTrafficLight()
{

	for (int i = 0; i < height; i++)
		CConsole::drawHorLine(coorX, coorX + width, coorY / 2 + i/2, block, color, background);


}

void CTrafficLight::setCoorX(const int& x)
{
	this->coorX = x;
}


void CTrafficLight::setCoorY(const int& y)
{
	this->coorY = y;
}

void CTrafficLight::setRedTime(const int& r)
{
	redTime = r;
}

void CTrafficLight::setGreenTime(const int& g)
{
	greenTime = g;
}

void CTrafficLight::lightUp()
{
	drawTrafficLight();
	if (lightState == "green") {
		for (int i = 0; i < height/2; i++)
			CConsole::drawHorLine(coorX, coorX + width, coorY / 2 + i / 2, block, greenColor, background);
	}
	else {
		for (int i = height/2; i < height ; i++)
			CConsole::drawHorLine(coorX, coorX + width, coorY / 2 + i / 2, block, redColor, background);
	}
}

int CTrafficLight::getTime()
{
	if (lightState == "green") return greenTime;
	return redTime;
}

string CTrafficLight::getState()
{
	return lightState;
}

void CTrafficLight::changeLight()
{
	changeState();
	lightUp();
}

void CTrafficLight::changeState()
{
	if (lightState == "green") {
		lightState = "red";
	}
	else lightState = "green";
}



