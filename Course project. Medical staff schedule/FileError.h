#pragma once
#include "Exception.h"

class FileError : public Exception
{
	string filepath; //путь к файлу
public:
	FileError(string path, string text) : filepath(path), Exception(text) {}
	
	~FileError() {};

	string getFilePath(); //возвращает путь к файлу
	
};

void openForWrite(std::ofstream& out,const char* path); //обрабатывает исключения при открытии файла для записи
void openForRead(std::ifstream& in,const char* path); //обрабатывает исключения при открытии файла для чтения
