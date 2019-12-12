#include "pch.h"
#include "AdministrativeStaff.h"


std::istream & operator>>(std::istream & in, AdministrativeStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj); 
	cout << " абинет:";
	inputLettersAndNumbers(in, obj.roomNumber); 
	return in;
}

std::ostream & operator<<(std::ostream & out, const AdministrativeStaff & obj)
{
	//вывод объекта в таблицу с разделител€ми и цветными границами
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
	cout << "7- абинет" << endl;
}

string AdministrativeStaff::getParameter(int n)
{
	int i = 0;
	string parameter; //параметр, который определ€ет какое поле было выбрано дл€ поиска
	do
	{
		parameter = TechnicalStaff::getParameter(n); //получаем выбранное поле родительского класса
		if (parameter == "") //если пол€ родительских классов не были выбраны
		{
			switch (n)
			{
			case 7:
				std::cout << " абинет:";
				inputLettersAndNumbers(cin, roomNumber);
				return "roomNumber";
			default: //проверка на введЄнное пользователем число в случае невыполнени€ ни одного из case
				cout << "¬ведЄнное число не принадлежит заданному диапазону. ¬ведите новый параметр: ";
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
	out << std::setiosflags(std::ios::left) << color<12, 2> << '|' << color<> <<setw(7) << " абинет";
}

void AdministrativeStaff::tableLines(std::ostream & out) const
{
	TechnicalStaff::tableLines(out); //вывод линий дл€ полей родительского класса
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
		std::cout << " абинет:";
		inputLetters(cin, roomNumber);
	}
}
