#include "pch.h"
#include "TechnicalStaff.h"

bool TechnicalStaff::operator==(TechnicalStaff & obj)
{
	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.profession==profession);
}

bool TechnicalStaff::operator!=(TechnicalStaff & obj)
{
	return (!(*this == obj));
}

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
	out << setiosflags(ios::left) << setw(20) << obj.profession;
	return out;
}

void TechnicalStaff::chooseParameters()
{
	Staff::chooseParameters();
	cout << "6-Должность" << endl;
}

string TechnicalStaff::getParameter(int n)
{
	string parameter = Staff::getParameter(n);
	if (parameter == "")
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
	else return parameter;
}

void TechnicalStaff::table(std::ostream & out)
{
	Staff::table(out);
	out << std::setiosflags(std::ios::left) << setw(20) << "Профессия";
}
