#include "pch.h"
#include "Doctor.h"

std::istream & operator>>(std::istream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	cout << "Категория:";
	inputLettersAndNumbers(in, obj.category);
	cout << "Специальность:";
	inputLetters(in, obj.speciality);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Doctor & obj)
{
	using namespace std;
	out << dynamic_cast<const MedicalStaff&>(obj);
	out << setiosflags(ios::left) << setw(10) << obj.category<< color<12, 2> << '|' << color<> << setw(10) 
		<<setw(19) << obj.speciality << color<12, 2> << '|' << color<>;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Doctor & obj)
{
	in >> dynamic_cast<MedicalStaff&>(obj);
	std::getline(in, obj.category, '|');
	std::getline(in, obj.speciality, '\n');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, Doctor & obj)
{
	out << dynamic_cast<MedicalStaff&>(obj);
	out << obj.category << '|' << obj.speciality << '\n';
	return out;

}

//bool Doctor::operator==(Doctor & obj)
//{
//	return (dynamic_cast<MedicalStaff&>(obj) == *(dynamic_cast<MedicalStaff*>(this)) && obj.category==category
//		&& obj.speciality==speciality);
//}

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

void Doctor::table(std::ostream & out)
{
	using namespace std;
	MedicalStaff::table(out);
	out << setiosflags(ios::left) << color<12, 2> << '|' << color<> << setw(10) << "Категория" << 
		color<12, 2> << '|' << color<> << setw(19) << "Специальность";
}

void Doctor::tableLines(std::ostream & out) const
{
	MedicalStaff::tableLines(out);
	string str1(10, '-');
	string str2(19, '-');
	out << str1 << '+' << str2 << '+';
	
	Doctor obj;
	obj.graphicLines(out);
	
}

void Doctor::chooseParameters()
{
	MedicalStaff::chooseParameters();
	cout << "7-Категория" << endl;
	cout << "8-Специальность" << endl;
}

string Doctor::getParameter(int n)
{
	int i = 0;
	string parameter; //параметр, который определяет какое поле было выбрано для поиска
	do
	{
		parameter = MedicalStaff::getParameter(n); //получаем выбранное поле родительского класса
		if (parameter == "") //если поля родительских классов не были выбраны
		{
			switch (n)
			{
			case 7:
				std::cout << "Категория:";
				inputLettersAndNumbers(cin, category);
				return "category";
			case 8:
				std::cout << "Специальность:" << endl;
				inputLetters(cin, speciality);
				return "speciality";
			}
		}
	} while (i);
	return parameter;
}

void Doctor::edit(int n)
{
	MedicalStaff::edit(n);
	switch (n)
	{
	case 7:
		std::cout << "Категория:";
		inputLettersAndNumbers(cin, category);
		break;
	case 8:
		std::cout << "Специальность:" << endl;
		inputLetters(cin, speciality);
		break;
	}
}
