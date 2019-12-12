#include "pch.h"
#include "ServiceStaff.h"

std::istream & operator>>(std::istream & in, ServiceStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj);
	cout << "Рабочая область:";
	inputLettersAndNumbers(in, obj.workPlace);
	return in;
}

std::ostream & operator<<(std::ostream & out, const ServiceStaff & obj)
{
	using namespace std;
	out << dynamic_cast<const TechnicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(29) << obj.workPlace<< color<12, 2> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, ServiceStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj);
	std::getline(in, obj.workPlace, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, ServiceStaff & obj)
{
	out << dynamic_cast<TechnicalStaff&>(obj);
	out << obj.workPlace << '\n';
	return out;
}

void ServiceStaff::table(std::ostream & out)
{
	TechnicalStaff::table(out);
	out << std::setiosflags(std::ios::left) << color<12, 2> << '|' << color<><<setw(29) << "Рабочая область";
}

void ServiceStaff::tableLines(std::ostream & out) const
{
	TechnicalStaff::tableLines(out);
	string str1(29, '-');
	out << str1 << '+';
	ServiceStaff obj;
	obj.graphicLines(out);
}

void ServiceStaff::edit(int n)
{
	TechnicalStaff::edit(n);
	if (n == 7)
	{
		std::cout << "Рабочая область:";
		inputLetters(cin, workPlace);
	}
}

void ServiceStaff::chooseParameters()
{
	TechnicalStaff::chooseParameters();
	cout << "7-Рабочая область" << endl;
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
				std::cout << "Рабочая область:";
				//inputLettersAndNumbers(cin, workPlace);
				std::getline(cin, workPlace);
				return "workPlace";
			default:
				cout << "Введённое число не принадлежит заданному диапазону. Введите новый параметр: ";
				inputNumber(cin, n, 1, 7);
				i = 1;
			}
		}
	} while (i);
	return parameter;
}

//bool ServiceStaff::operator==(ServiceStaff & obj)
//{
//	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.workPlace == workPlace);
//		
//}

//bool ServiceStaff::operator!=(ServiceStaff & obj)
//{
//	return (!(*this == obj));
//}

string ServiceStaff::getWorkPlace()
{
	return workPlace;
}

void ServiceStaff::setWorkPlace(string place)
{
	workPlace = place;
}
