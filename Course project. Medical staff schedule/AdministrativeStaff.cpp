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
	out << setiosflags(ios::left) << setw(10) << obj.roomNumber;
	return out;
}

bool AdministrativeStaff::operator==(AdministrativeStaff & obj)
{
	return (dynamic_cast<TechnicalStaff&>(obj) == *(dynamic_cast<TechnicalStaff*>(this)) 
		&& obj.roomNumber == roomNumber);
}

bool AdministrativeStaff::operator!=(AdministrativeStaff & obj)
{
	return (!(*this == obj));
}

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
	cout << "7-Кабинет:" << endl;
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