#pragma once
#include "pch.h"
#include "Exception.h"
#include <string>

using std::endl;
using std::cerr;

class InputError : public Exception
{
protected:
	int code;
public:
	InputError(int c, std::string text) : Exception(text), code(c)
	{}
	~InputError()
	{};

	int getCode();
};


void inputLetters(std::istream& in, std::string& str) throw (InputError&);
void inputLettersAndNumbers(std::istream& in, std::string& str) throw (InputError&);


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
				throw InputError(1, "Ѕыло введено не число");

			if (n<range1 || n>range2)
				throw InputError(5, "¬ведЄнное число не принадлежит заданному диапазону");

		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Code:" << exception.getCode() << endl << "Description:" << exception.what() << endl;
			in.clear();
			rewind(stdin);
		}
	} while (!flag);
}




