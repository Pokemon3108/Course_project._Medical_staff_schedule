#include "pch.h"
#include "AdministrativeStaff.h"


std::istream & operator>>(std::istream & in, AdministrativeStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj); 
	cout << "Кабинет:";
	inputLettersAndNumbers(in, obj.roomNumber); 
	return in;
}

std::ostream & operator<<(std::ostream & out, const AdministrativeStaff & obj)
{
	//вывод объекта в таблицу с разделителями и цветными границами
	using namespace std;
	out << dynamic_cast<const TechnicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(7) << obj.roomNumber<< color<12, 2> << '|' << color<>;  
	return out;
}

std::ifstream & operator>>(std::ifstream & in, AdministrativeStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj);
	std::getline(in, obj.roomNumber, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, AdministrativeStaff & obj)
{
	out << dynamic_cast<TechnicalStaff&>(obj);
	out << obj.roomNumber << '\n';
	return out;
}

//bool AdministrativeStaff::operator==(AdministrativeStaff & obj)
//{
//	return (dynamic_cast<TechnicalStaff&>(obj) == *(dynamic_cast<TechnicalStaff*>(this)) 
//		&& obj.roomNumber == roomNumber);
//}

string AdministrativeStaff::getRoomNumber()
{
	return roomNumber;
}

void AdministrativeStaff::setRoomNumber(string room)
{
	roomNumber = room;
}

void AdministrativeStaff::chooseParameters()
{
	TechnicalStaff::chooseParameters();
	cout << "7-Кабинет" << endl;
}

string AdministrativeStaff::getParameter(int n)
{
	int i = 0;
	string parameter; //параметр, который определяет какое поле было выбрано для поиска
	do
	{
		parameter = TechnicalStaff::getParameter(n); //получаем выбрааное поле родительского класса
		if (parameter == "") //если поля родительских классов не были выбраны
		{
			switch (n)
			{
			case 7:
				std::cout << "Кабинет:";
				inputLettersAndNumbers(cin, roomNumber);
				return "roomNumber";
			default: //проверка на введённое пользователем число в случае невыполнения ни одного из case
				cout << "Введённое число не принадлежит заданному диапазону. Введите новый параметр: ";
				inputNumber(cin, n, 1, 7);
				i = 1; //цикл пройдет заново
			}
		}
	} while (i);
	return parameter;
}

void AdministrativeStaff::table(std::ostream & out)
{
	TechnicalStaff::table(out);
	out << std::setiosflags(std::ios::left) << color<12, 2> << '|' << color<> <<setw(7) << "Кабинет";
}

void AdministrativeStaff::tableLines(std::ostream & out) const
{
	TechnicalStaff::tableLines(out); //вывод линий для полей родительского класса
	string str1(7, '-');
	out << str1 << '+';
	AdministrativeStaff obj;
	obj.graphicLines(out); //вывод линий графика
}

void AdministrativeStaff::edit(int n)
{
	TechnicalStaff::edit(n);
	if (n == 7) 
	{
		std::cout << "Кабинет:";
		inputLetters(cin, roomNumber);
	}
}
