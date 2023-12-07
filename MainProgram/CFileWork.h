#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "StructSaveInfo.h"
const string rootP = "savegame/";
using namespace std;


class CFileWork
{
	string rootLocation;
	string fileName;
	fstream file;
	
	
public:
	CFileWork();
	void setPath(const string& name,const string& rootFolder );
	void setFileName(const string& fileName);
	bool openFile();
	void closeFile();

	template<class T>
	void saving(const T& data);
	template<class T>
	T loading();

	bool isEmpty();

};

