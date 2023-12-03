#pragma once

#include <string>
using namespace std;
#include <vector>
#include <iostream>

struct saveInfo {
	int level;
	int score;
	int peopleX;
	int peopleY;
	bool people_isDead;

	int numLane;
	vector<int> coorYLane;

	int numBridge;
	vector<int> coorXBridge;
	vector<int> coorYBridge;

	int numLight;
	vector<string> stateLight;
	vector<int> redTime;
	vector<int> greenTime;
	vector<int> coorXLight;
	vector<int> coorYLight;
	int numTruck;
	vector<int> coorXTruck;
	vector<int> coorYTruck;
	vector<int> truckSpeed;
	vector<string> truckDirect;
	int numTruck2;
	vector<int> coorXTruck2;
	vector<int> coorYTruck2;
	vector<int> truck2Speed;
	vector<string> truck2Direct;


	int numCar;
	vector<int> coorXCar;
	vector<int> coorYCar;
	vector<int> carSpeed;
	vector<string> carDirect;



};
ostream& operator<<(ostream& outDev, const saveInfo& info);

istream& operator>>(istream& inDev, saveInfo& info);


struct fileNames {
	vector<string> names;
};
ostream& operator<<(ostream& outDev, const fileNames& fn);

istream& operator>>(istream& inDev, fileNames& fn);

//istream& operator>>(istream& inDev, saveInfo& info) {
//	inDev >> num;
//
//}