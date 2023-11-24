#include "CFileWork.h"
CFileWork::CFileWork()
{
	rootLocation = rootP;
	fileName = rootLocation;



}
void CFileWork::setPath(const string& name, const string& rootFolder)
{
	rootLocation = rootFolder;
	fileName = name;
}
bool CFileWork::openFile() {
	string fullPath = rootLocation + fileName;
	file.open(fullPath, ios::binary | ios::in | ios::out | ios::app);

	return file.is_open();

}
void CFileWork::closeFile()
{
	if (file.is_open())
		file.close();
}
void CFileWork::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

bool CFileWork::isEmpty()
{
	file.seekg(0, ios::end);
	return (file.tellg() == 0);
}

//void CFileWork::clearList()
//{
//	savedInf.infos.clear();
//}
//
//
//void CFileWork::getInfo(string info)
//{
//	savedInf.infos.push_back(info);
//}

template<class T>
void CFileWork::saving(const T& data) {
	file.seekp(ios::beg);

	file << data;
}
template<class T>
T CFileWork::loading() {
	file.seekg(ios::beg);
	T data;
	file >> data;
	return data;
}

template void CFileWork::saving<saveInfo>(const saveInfo& data);
template saveInfo CFileWork::loading<saveInfo>();

template void CFileWork::saving<fileNames>(const fileNames& data);

template fileNames CFileWork::loading<fileNames>();
