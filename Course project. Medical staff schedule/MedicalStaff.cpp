#include "pch.h"
#include "MedicalStaff.h"


bool MedicalStaff::operator==(MedicalStaff & obj)
{
	return (dynamic_cast<Staff&>(obj) == *(dynamic_cast<Staff*>(this)) && obj.department == department);
}

bool MedicalStaff::operator!=(MedicalStaff & obj)
{
	return (!(*this == obj));
}

string MedicalStaff::getDepartment() const
{
	return department;
}

void MedicalStaff::setDepartment(string department)
{
	department = department;
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
	using namespace std;
	out << dynamic_cast<const Staff&>(obj);
	out << setiosflags(ios::left) << setw(20) << obj.department;
	return out;
}

void MedicalStaff::chooseParameters()
{
	Staff::chooseParameters();
	cout << "6-Отделение" << endl;
}

std::string MedicalStaff::getParameter(int n)
{
	std::string parameter = Staff::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Отделение:";
			inputLetters(cin, department);
			return "department";

		default:
			return "";
		}
	}
	else return parameter;
}