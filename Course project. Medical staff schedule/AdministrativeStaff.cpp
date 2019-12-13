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
	out << setiosflags(ios::left) << setw(7) << obj.roomNumber<< color<12, 3> << '|' << color<>;  
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

	string parameter; //параметр, который определяет какое поле было выбрано для поиска
	
	parameter = TechnicalStaff::getParameter(n); //получаем выбранное поле родительского класса
	if (parameter == "") //если поля родительских классов не были выбраны, то работаем с полями данного класса
	{
		switch (n)
		{
		case 7:
			cout << "Кабинет:";
			inputLettersAndNumbers(cin, roomNumber);
			return "roomNumber";
		}
	}
	//если был выбран параметр родительского класса, то вернуть его
	return parameter;
}

void AdministrativeStaff::table(std::ostream & out)
{
	TechnicalStaff::table(out);

	//вывод шапки таблицы с изменением цвета линий-разделителей между названиями колонок
	out << std::setiosflags(std::ios::left) << color<12, 3> << '|' << color<> <<setw(7) << "Кабинет";
}

void AdministrativeStaff::tableLines(std::ostream & out) const
{
	//вывод линий-разделителей между строками таблицы
	TechnicalStaff::tableLines(out); 
	string str1(7, '-');
	out << str1 << '+';
	AdministrativeStaff obj;
	obj.graphicLines(out); //вывод линий-разделителей между строкми таблицы для колонок с графиком
}

void AdministrativeStaff::edit(int n)
{
	//определение параметра, который выбрал пользователь
	TechnicalStaff::edit(n);
	if (n == 7) //если пользователь выбрал 7-й параметр, то редактируем номер кабинета
	{
		std::cout << "Кабинет:";
		inputLetters(cin, roomNumber);
	}
}
