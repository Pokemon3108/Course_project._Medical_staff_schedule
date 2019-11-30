#include "pch.h"
#include "InputError.h"
#include <vector>
#include <string>

using std::endl;



void inputLetters(std::istream& in, string & str) throw(InputError &)
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


void inputLettersAndNumbers(std::istream& in, string & str) throw(InputError &)
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

void inputWeekDay(std::istream & in, string & str) throw(InputError &)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			inputLetters(in, str);
			std::vector<string> vect{ "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
			for (int i = 0; i < 7; ++i)
			{
				if (str == vect[i]) return;
			}
			throw InputError(6, "Вы ввели не день неделию. Проверьте, возможно день недели был введён с маленькой буквы");
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Код:" << exception.getCode() << endl << "Описание:" << exception.what() << endl;
			str.clear();
		}

	} while (!flag);
	
}
