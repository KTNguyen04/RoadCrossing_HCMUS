#include "CFileWork.h"
CFileWork::CFileWork()
{
	rootLocation = "savegame/";
	fileName = rootLocation;
	savedInf.infos.resize(0);
	loadedInf.infos.resize(0);

}
bool CFileWork::openFile(const string& name) {
	fileName = rootLocation + name;
	file.open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
	return file.is_open();

}
void CFileWork::closeFile()
{
	file.close();
}
void CFileWork::setFileName(const string& fileName)
{
	this->fileName = fileName;
}


void CFileWork::getInfo(string info)
{
	savedInf.infos.push_back(info);
}


void CFileWork::saving() {
	
	for (string& e : savedInf.infos) {
	
		file.write(reinterpret_cast<const char*>(e.c_str()), e.length());
		file.put('\0');
	}
	
}

void CFileWork::loading() {
	while (file) {
		string temp;
		getline(file, temp, '\0');
		loadedInf.infos.push_back(temp);

	}
}