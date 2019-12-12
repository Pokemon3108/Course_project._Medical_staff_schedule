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
			for (size_t i = 0; i < str.length(); ++i)
			{
				if ((str[i]<'А' || str[i]>'я') && str[i] != ' '&& str[i] != '-')
				{
					throw InputError(3, "В введённой строке должны содержаться только буквы и дефисы");
				}
			}
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
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

				if ((str[i]<'А' || str[i]>'я') && (str[i] < '0' || str[i]>'9') && str[i] != ' ' && str[i] != '-')
				{

					throw InputError(4, "В строке могут содержаться буквы,цифры и дефисы");
				}
			}
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
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
			if (str != "Да" && str != "да" && str != "нет" && str!="Нет")
				throw InputError(7, "Необходимо ввести Да/Нет");
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}
