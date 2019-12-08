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
	using namespace std;
	out << dynamic_cast<const TechnicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(7) << obj.roomNumber<<'|';
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
	string parameter;
	do
	{
		parameter = TechnicalStaff::getParameter(n);
		if (parameter == "")
		{
			switch (n)
			{
			case 7:
				std::cout << "Кабинет:";
				inputLettersAndNumbers(cin, roomNumber);
				return "roomNumber";
			default:
				i = 1;
			}
		}
	} while (i);
	return parameter;
}

void AdministrativeStaff::table(std::ostream & out)
{
	TechnicalStaff::table(out);
	out << std::setiosflags(std::ios::left) << setw(8) << "|Кабинет";
}

void AdministrativeStaff::tableLines(std::ostream & out) const
{
	TechnicalStaff::tableLines(out);
	string str1(7, '-');
	out << str1 << '+';
	AdministrativeStaff obj;
	obj.graphicLines(out);
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
