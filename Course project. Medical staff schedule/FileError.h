#pragma once
#include "Exception.h"

class FileError : public Exception
{
	string filepath; //���� � �����
public:
	FileError(string path, string text) : filepath(path), Exception(text) {}
	
	~FileError() {};

	string getFilePath(); //���������� ���� � �����
	
};

void openForWrite(std::ofstream& out,const char* path); //������������ ���������� ��� �������� ����� ��� ������
void openForRead(std::ifstream& in,const char* path); //������������ ���������� ��� �������� ����� ��� ������
