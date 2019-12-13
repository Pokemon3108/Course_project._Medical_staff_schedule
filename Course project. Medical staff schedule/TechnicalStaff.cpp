#include "pch.h"
#include "TechnicalStaff.h"

void TechnicalStaff::edit(int n)
{
	//определение параметра, который выбрал пользователь
	Staff::edit(n);
	if (n == 6) //если пользователь выбрал 6-й параметр, то редактируем профессию
	{
		std::cout << "Должность:";
		inputLetters(cin, profession); 
	}
}

//bool TechnicalStaff::operator==(TechnicalStaff & obj)
//{
//	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.profession==profession);
//}

string TechnicalStaff::getProfession()
{
	return profession;
}

void TechnicalStaff::setProfession(string profession_)
{
	profession = profession_;
}

std::istream & operator>>(std::istream & in, TechnicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	cout << "Должность:";
	inputLetters(in, obj.profession);
	return in;
}

std::ostream & operator<<(std::ostream & out, const TechnicalStaff & obj)
{
	using namespace std;
	out << dynamic_cast<const Staff&>(obj);
	out << setiosflags(ios::left) << setw(24) << obj.profession<< color<12, 3> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, TechnicalStaff & obj)
{
	in >> dynamic_cast<Staff&>(obj);
	std::getline(in, obj.profession, '|');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, TechnicalStaff & obj)
{
	out << dynamic_cast<Staff&>(obj);
	out << obj.profession << '\n';
	return out;
}

void TechnicalStaff::chooseParameters()
{
	Staff::chooseParameters();
	cout << "6-Должность" << endl;
}

string TechnicalStaff::getParameter(int n)
{
	string parameter = Staff::getParameter(n); //параметр, который определяет какое поле было выбрано для поиска
	if (parameter == "") //если поля родительских классов не были выбраны, то работаем с полями данного класса
	{
		switch (n)
		{
		case 6:
			std::cout << "Должность:";
			inputLetters(cin, profession);
			return "profession";

		default:
			return "";
		}
	}
	//если был выбран параметр родительского класса, то вернуть его
	else return parameter;
}

void TechnicalStaff::table(std::ostream & out)
{
	Staff::table(out);

	//вывод шапки таблицы с изменением цвета линий-разделителей между названиями колонок
	out << std::setiosflags(std::ios::left) << color<12, 3> << '|' << color<><< setw(24) << "Должность";
}

void TechnicalStaff::tableLines(std::ostream & out) const
{ 
	//вывод линий-разделителей между строками таблицы
	Staff::tableLines(out);
	string str1(24, '-');
	out << str1 << '+';
}
