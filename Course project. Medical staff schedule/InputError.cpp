#include "pch.h"
#include "InputError.h"
#include <vector>

void inputLetters(std::istream& in, string & str)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			std::getline(in, str);
			for (size_t i = 0; i < str.length(); ++i) //цикл прохода по каждому символа строки
			{
				//если была введена не русская буква или не пробел или не дефис, то выбрасывается исключение
				if ((str[i]<'А' || str[i]>'я') && str[i] != ' '&& str[i] != '-') 
				{
					throw InputError(3, "В введённой строке должны содержаться только буквы и дефисы");
				}
			}
		}
		catch (InputError& exception)
		{
			
			flag = 0; 
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl; //вывод кода и описания ошибки
			str.clear();
		}
	} while (!flag); //цикл будет продолжаться, пока не будет введена нужная строка
}



int InputError::getCode()
{
	return code;
}


void inputLettersAndNumbers(std::istream& in, string & str)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			std::getline(in, str);
			for (size_t i = 0; i < str.length(); ++i)
			{
				//если была введена не русская буква или не пробел или не дефис или не цифра, то выбрасывается исключение
				if ((str[i]<'А' || str[i]>'я') && (str[i] < '0' || str[i]>'9') && str[i] != ' ' && str[i] != '-')
				{
					throw InputError(4, "В строке могут содержаться буквы,цифры и дефисы");
				}
			}
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl; //вывод кода и описания ошибки
			str.clear();
		}
	} while (!flag); //цикл будет продолжаться, пока не будет введена нужная строка
}

void inputYesNo(std::istream & in, string & str)
{
	bool flag;
	do
	{

		try
		{
			flag = 1;
			inputLetters(in, str);
			if (str != "Да" && str != "да" && str != "нет" && str!="Нет") //если пользователь ввёл строку, отличную от да/нет
				throw InputError(7, "Необходимо ввести Да/Нет");
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl; //вывод кода и описания ошибки
			str.clear();
		}
	} while (!flag); //цикл будет продолжаться, пока не будет введена нужная строка
}
