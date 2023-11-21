#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "StructSaveInfo.h"
using namespace std;


class CFileWork
{
	string rootLocation;
	string fileName;
	fstream file;
	saveInfo savedInf;
	saveInfo loadedInf;
public:
	CFileWork();
	bool openFile(const string& name);
	void closeFile();
	void setFileName(const string& fileName);

	void getInfo(string info);	
	void saving();
	void loading();


};

