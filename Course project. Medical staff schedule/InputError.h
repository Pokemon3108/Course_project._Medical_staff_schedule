#pragma once
#include "pch.h"
#include "Exception.h"
#include <string>

class InputError : public Exception
{
protected:
	int code; //код ошибки
public:
	InputError(int c, string text) : Exception(text), code(c)
	{}
	~InputError()
	{};

	int getCode(); //возвращает код ошибки
};


void inputLetters(std::istream& in, string& str); //обрабатывает исключения при вводе строк, содержащих только буквы
void inputLettersAndNumbers(std::istream& in, string& str); //обрабатывает исключения при вводе строк, содержащих только буквы и цифры
void inputYesNo(std::istream& in, string& str);//обрабатывает исключения при вводе "Да/Нет"


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
				throw InputError(1, "Было введено не число");

			if (n<range1 || n>range2)
				throw InputError(5, "Введённое число не принадлежит заданному диапазону. Если вы вводили график, проверьте, возможно первый час работы оказался больше последнего");

		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl;
			in.clear();
			rewind(stdin);
		}
	} while (!flag);
}