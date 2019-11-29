#include "pch.h"
#include "Doctor.h"

std::istream & operator>>(std::istream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "Категория:";
	inputLetters(in, obj.category);
	cout << "Специальность:";
	inputLetters(in, obj.speciality);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Doctor & obj)
{
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(11) << obj.category<<setw(20)<<obj.speciality;
	return out;
}

bool Doctor::operator==(Doctor & obj)
{
	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this)) && obj.category==category
		&& obj.speciality==speciality);
}

bool Doctor::operator!=(Doctor & obj)
{
	return (!(*this == obj));
}

string Doctor::getCategory()
{
	return category;
}

void Doctor::setCategory(string category_)
{
	category = category_;
}

string Doctor::getSpeciality()
{
	return speciality;
}

void Doctor::setSpeciality(string speciality_)
{
	speciality = speciality_;
}

void Doctor::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-Категория" << endl;
	cout << "8-Специализация" << endl;
}

string Doctor::getParameter(int n)
{
	int i = 0;
	string parameter;
	do
	{
		parameter = MedicalStaff::getParameter(n);
		if (parameter == "")
		{
			switch (n)
			{
			case 7:
				std::cout << "Категория:";
				inputLettersAndNumbers(cin, category);
				return "category";
			case 8:
				std::cout << "Специализация" << endl;
				inputLetters(cin, speciality);
				return "speciality";
			default:
				i = 1;
			}
		}
	} while (i);
	return parameter;
}