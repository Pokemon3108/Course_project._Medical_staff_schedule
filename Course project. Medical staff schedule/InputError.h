#pragma once
#include "pch.h"
#include "Exception.h"
#include <string>

class InputError : public Exception
{
protected:
	int code;
public:
	InputError(int c, string text) : Exception(text), code(c)
	{}
	~InputError()
	{};

	int getCode();
};


void inputLetters(std::istream& in, string& str) throw (InputError&);
void inputLettersAndNumbers(std::istream& in, string& str) throw (InputError&);
void inputWeekDay(std::istream& in, string& str) throw (InputError&);


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
			if (!in.good() || in.peek() != '\n')
				throw InputError(1, "���� ������� �� �����");

			if (n<range1 || n>range2)
				throw InputError(5, "�������� ����� �� ����������� ��������� ���������. ���������, �������� ������ ��� ������ �������� ������ ����������");

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




