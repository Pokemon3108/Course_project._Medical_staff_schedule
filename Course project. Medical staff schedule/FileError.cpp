#include "pch.h"
#include "FileError.h"
#include <fstream>

void openForWrite(std::ofstream& out, const char* path)
{
	try
	{
		out.open(path);
		if (!out.is_open()) throw FileError(path, "Файл не был открыт для записи. Путь к файлу: ");
	}
	catch (FileError& exception)
	{
		cerr << exception.what() << exception.getFilePath() << endl;
	}
}

void openForRead(std::ifstream& in,const char* path)
{
	try
	{
		
		in.open(path);
		if (!in.is_open()) throw FileError(path, "Файл не был открыт для чтения. Путь к файлу: ");
	}
	catch (FileError& exception)
	{
		cerr << exception.what() << exception.getFilePath() << endl;
	}
}
