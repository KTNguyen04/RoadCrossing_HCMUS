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
void CTrafficLight::drawTrafficLight(bool isForRemove)
{
	int cl = color;
	if (isForRemove) cl = background;

	for (int i = 0; i < height; i++)
		CConsole::drawHorLine(coorX, coorX + width, coorY / 2 + i/2, block, cl, background);


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

int CTrafficLight::getRedTime() const
{
	
	return redTime;
}
int CTrafficLight::getGreenTime() const
{
	
	return greenTime;
}

string CTrafficLight::getState() const
{
	return lightState;
}

int CTrafficLight::getCoorX() const
{
	return coorX;
}
int CTrafficLight::getTime() const
{
	if (lightState == "green") return greenTime;
	return redTime;
	return 0;
}
int CTrafficLight::getCoorY() const
{
	return coorY;
}

void CTrafficLight::changeLight()
{
	changeState();
	lightUp();
}

void CTrafficLight::setState(const string & ls)
{
	lightState = ls;
}

void CTrafficLight::changeState()
{
	if (lightState == "green") {
		lightState = "red";
	}
	else lightState = "green";
}



