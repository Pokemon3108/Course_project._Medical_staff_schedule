#include "pch.h"
#include "ServiceStaff.h"

std::istream & operator>>(std::istream & in, ServiceStaff & obj)
{
	in >> dynamic_cast<TechnicalStaff&>(obj);
	cout << "–абоча€ область:";
	inputLettersAndNumbers(in, obj.workPlace);
	return in;
}

std::ostream & operator<<(std::ostream & out, const ServiceStaff & obj)
{
	//вывод объекта в таблицу с разделител€ми и цветными границами
	using namespace std;
	out << dynamic_cast<const TechnicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(29) << obj.workPlace<< color<12, 3> << '|' << color<>;
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

	//вывод шапки таблицы с изменением цвета линий-разделителей между названи€ми колонок
	out << std::setiosflags(std::ios::left) << color<12, 3> << '|' << color<><<setw(29) << "–абоча€ область";
}

void ServiceStaff::tableLines(std::ostream & out) const
{
	//вывод шапки таблицы с изменением цвета линий-разделителей между названи€ми колонок
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
		std::cout << "–абоча€ область:";
		inputLetters(cin, workPlace);
	}
}

void ServiceStaff::chooseParameters()
{
	TechnicalStaff::chooseParameters();
	cout << "7-–абоча€ область" << endl;
}

string ServiceStaff::getParameter(int n)
{
	
	string parameter; //параметр, который определ€ет какое поле было выбрано дл€ поиска

	parameter = TechnicalStaff::getParameter(n); //получаем выбранное поле родительского класса
	if (parameter == "") //если пол€ родительских классов не были выбраны, то работаем с пол€ми данного класса
	{
		switch (n)
		{
		case 7:
			cout << "–абоча€ область:";
			std::getline(cin, workPlace);
			return "workPlace";
		}
	}

	//если был выбран параметр родительского класса, то вернуть его
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
