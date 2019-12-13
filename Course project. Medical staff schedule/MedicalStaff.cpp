#include "pch.h"
#include "MedicalStaff.h"


//bool MedicalStaff::operator==(MedicalStaff & obj)
//{
//	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.department == department);
//}

string MedicalStaff::getDepartment() const
{
	return department;
}

void MedicalStaff::setDepartment(string department_)
{
	department = department_;
}

std::istream & operator>>(std::istream & in, MedicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	cout << "Отделение:";
	inputLetters(in, obj.department);
	return in;
}

std::ostream & operator<<(std::ostream & out, const MedicalStaff & obj)
{
	//вывод объекта в таблицу с разделителями и цветными границами
	using namespace std;
	out << dynamic_cast<const Staff&>(obj);
	out << setiosflags(ios::left) << setw(19) << obj.department<< color<12, 3> << '|' << color<>;
	return out;
	
}

std::ifstream & operator>>(std::ifstream & in, MedicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	std::getline(in, obj.department, '|');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, MedicalStaff & obj)
{
	out << dynamic_cast<Staff&>(obj);
	out << obj.department << '|';
	return out;
}

void MedicalStaff::table(std::ostream & out)
{
	Staff::table(out);

	//вывод шапки таблицы с изменением цвета линий-разделителей между названиями колонок
	out << std::setiosflags(std::ios::left)<< color<12,3> << '|' << color<><< setw(19) << "Отделение";
}

void MedicalStaff::tableLines(std::ostream & out) const
{
	//вывод линий-разделителей между строками таблицы
	Staff::tableLines(out);
	string str1(19, '-');
	out << str1 << '+';
}


void MedicalStaff::chooseParameters()
{
	Staff::chooseParameters();
	cout << "6-Отделение" << endl;
}

std::string MedicalStaff::getParameter(int n)
{
	string parameter = Staff::getParameter(n); //параметр, который определяет какое поле было выбрано для поиска
	if (parameter == "") //если поля родительских классов не были выбраны, то работаем с полями данного класса
	{
		switch (n)
		{
		case 6:
			cout << "Отделение:";
			inputLetters(cin, department);
			return "department";

		default:
			return "";
		}
	}
	//если был выбран параметр родительского класса, то вернуть его
	return parameter;
}

void MedicalStaff::edit(int n)
{
	//определение параметра, который выбрал пользователь
	Staff::edit(n);
	if (n == 6) //если пользователь выбрал 6-й параметр, то редактируем отделение
	{
		cout << "Отделение:";
		inputLetters(cin, department);
	}
}
