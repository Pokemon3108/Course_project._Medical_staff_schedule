#include "pch.h"
#include "ServiceStaff.h"

std::istream & operator>>(std::istream & in, ServiceStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj);
	cout << "Рабочая область:";
	inputLetters(in, obj.workPlace);
	return in;
}

std::ostream & operator<<(std::ostream & out, const ServiceStaff & obj)
{
	using namespace std;
	out << dynamic_cast<const TechnicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(20) << obj.workPlace;
	return out;
}

void ServiceStaff::chooseParameters()
{
	TechnicalStaff::chooseParameters();
	cout << "7-Закрепленный участок работы" << endl;
}

string ServiceStaff::getParameter(int n)
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
				std::cout << "Закрепленный участок работы:";
				inputLettersAndNumbers(cin, workPlace);
				return "workPlace";
			default:
				i = 1;
			}
		}
	} while (i);
	return parameter;
}

bool ServiceStaff::operator==(ServiceStaff & obj)
{
	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.workPlace == workPlace);
		
}

bool ServiceStaff::operator!=(ServiceStaff & obj)
{
	return (!(*this == obj));
}

string ServiceStaff::getWorkPlace()
{
	return workPlace;
}

void ServiceStaff::setWorkPlace(string place)
{
	workPlace = place;
}
