#pragma once
#include "pch.h"
#include "Exception.h"
#include <string>

class InputError : public Exception
{
protected:
	int code; //��� ������
public:
	InputError(int c, string text) : Exception(text), code(c)
	{}
	~InputError()
	{};

	int getCode(); //���������� ��� ������
};


void inputLetters(std::istream& in, string& str); //������������ ���������� ��� ����� �����, ���������� ������ �����
void inputLettersAndNumbers(std::istream& in, string& str); //������������ ���������� ��� ����� �����, ���������� ������ ����� � �����
void inputYesNo(std::istream& in, string& str);//������������ ���������� ��� ����� "��/���"


template<typename T>
void inputNumber(std::istream& in, T&n, T range1, T range2)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			in >> n;
			while (in.peek() == ' ') in.get();
			if (!in.good() || in.peek() != '\n')
				throw InputError(1, "���� ������� �� �����");

			if (n<range1 || n>range2)
				throw InputError(5, "�������� ����� �� ����������� ��������� ���������. ���� �� ������� ������, ���������, �������� ������ ��� ������ �������� ������ ����������");

		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "���:" << exception.getCode() << endl << "��������:" << exception.what() << endl;
			in.clear();
			rewind(stdin);
		}
	} while (!flag);
}