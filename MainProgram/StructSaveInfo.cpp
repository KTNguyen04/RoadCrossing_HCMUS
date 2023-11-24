#include "StructSaveInfo.h"

ostream& operator<<(ostream& outDev, const saveInfo& info) {


	outDev << info.level;
	outDev << '\n';
	outDev << info.score;
	outDev << '\n';
	outDev << info.peopleX;
	outDev << '\n';
	outDev << '\n';
	outDev << info.peopleY;
	outDev << '\n';
	outDev << info.people_isDead;
	outDev << '\n';
	outDev << info.numLane;
	outDev << '\n';
	for (auto& i : info.coorYLane) {
		outDev << i;
		outDev << '\n';
	}

	outDev << info.numBridge;
	outDev << '\n';
	for (auto& i : info.coorXBridge) {
		outDev << i;
		outDev << '\n';
	}
	outDev << '\n';
	for (auto& i : info.coorYBridge) {
		outDev << i;
		outDev << '\n';

	}

	outDev << info.numLight;
	outDev << '\n';

	for (auto& i : info.stateLight) {
		outDev << i;
		outDev << '\n';

	}
	for (auto& i : info.coorXLight) {
		outDev << i;
		outDev << '\n';

	}
	for (auto& i : info.coorYLight) {
		outDev << i;
		outDev << '\n';

	}
	outDev << info.numTruck;
	outDev << '\n';

	for (auto& i : info.coorXTruck) {
		outDev << i;
		outDev << '\n';

	}
	for (auto& i : info.coorYTruck) {
		outDev << i;
		outDev << '\n';

	}

	outDev << info.numTruck2;
	outDev << '\n';

	for (auto& i : info.coorXTruck2) {
		outDev << i;
		outDev << '\n';

	}
	for (auto& i : info.coorYTruck2) {
		outDev << i;
		outDev << '\n';

	}

	outDev << info.numCar;
	outDev << '\n';

	for (auto& i : info.coorXCar) {
		outDev << i;
		outDev << '\n';

	}
	for (auto& i : info.coorYCar) {
		outDev << i;
		outDev << '\n';

	}
	return outDev;

}


istream& operator>>(istream& inDev, saveInfo& info) {


	inDev >> info.level;
	inDev >> info.score;
	inDev >> info.peopleX;
	inDev >> info.peopleY;
	inDev >> info.people_isDead;

	inDev >> info.numLane;
	info.coorYLane.resize(info.numLane);
	for (int i = 0; i < info.numLane; i++)
		inDev >> info.coorYLane[i];

	inDev >> info.numBridge;
	info.coorXBridge.resize(info.numBridge);
	for (int i = 0; i < info.numBridge; i++)
		inDev >> info.coorXBridge[i];
	info.coorYBridge.resize(info.numBridge);
	for (int i = 0; i < info.numBridge; i++)
		inDev >> info.coorYBridge[i];


	inDev >> info.numLight;
	info.stateLight.resize(info.numLight);
	for (int i = 0; i < info.numLight; i++)
		inDev >> info.stateLight[i];
	info.coorXLight.resize(info.numLight);
	for (int i = 0; i < info.numLight; i++)
		inDev >> info.coorXLight[i];
	info.coorYLight.resize(info.numLight);
	for (int i = 0; i < info.numLight; i++)
		inDev >> info.coorYLight[i];


	inDev >> info.numTruck;
	info.coorXTruck.resize(info.numTruck);
	for (int i = 0; i < info.numTruck; i++)
		inDev >> info.coorXTruck[i];
	info.coorYTruck.resize(info.numTruck);
	for (int i = 0; i < info.numTruck; i++)
		inDev >> info.coorYTruck[i];

	inDev >> info.numTruck2;
	info.coorXTruck2.resize(info.numTruck2);
	for (int i = 0; i < info.numTruck2; i++)
		inDev >> info.coorXTruck2[i];
	info.coorYTruck2.resize(info.numTruck2);
	for (int i = 0; i < info.numTruck2; i++)

		inDev >> info.numCar;
	info.coorXCar.resize(info.numCar);
	for (int i = 0; i < info.numTruck; i++)
		inDev >> info.coorXCar[i];
	info.coorYCar.resize(info.numCar);
	for (int i = 0; i < info.numCar; i++)
		inDev >> info.coorYCar[i];
	return inDev;

}

ostream& operator<<(ostream& outDev, const fileNames& fn) {
	for (auto& i : fn.names) {
		outDev << i;
		outDev << '\n';
	}
	return outDev;
}

istream& operator>>(istream& inDev, fileNames& fn) {
	decltype(fn.names)::value_type temp;

	while (inDev>>temp) {
		fn.names.push_back(temp);
	}
	return inDev;
}
