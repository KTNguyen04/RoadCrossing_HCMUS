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
	vector<int> coorXLight;
	vector<int> coorYLight;
	int numTruck;
	vector<int> coorXTruck;
	vector<int> coorYTruck;
	int numTruck2;
	vector<int> coorXTruck2;
	vector<int> coorYTruck2;
	int numCar;
	vector<int> coorXCar;
	vector<int> coorYCar;

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